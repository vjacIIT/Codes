#include<cstdio>
#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<climits>
using namespace std;

int main(){
	char *str;
	int tc, n;
	scanf("%d",&tc);
	str = new char[30];
	while(tc--){
		int ans=0;
		set<string> mset;
		scanf("%d",&n);
		vector<string> v = vector<string>(n);
		vector<int> cnt = vector<int>(26,0);		// stores count of each character
		vector<int> sidx = vector<int>(26,INT_MAX);		// starting index of each character
		for(int i=0; i<n; i++){
			scanf("%s",str);
			v[i] = str;
			mset.insert(str);
			cnt[str[0]-'a']++;
		}
		sort(v.begin(),v.end());
		for(int i=0; i<n; i++)
			sidx[v[i][0]-'a']=min(sidx[v[i][0]-'a'],i);
		//for(int i=0; i<n; i++)
			//cout<<v[i]<<" ";
		//cout<<endl;
		int end;
		for(int i=0; i<n; i++){
			//cout<<i<<endl;
			for(end=i; end<n;){
				string s = v[i];
				s[0]=v[end][0];
				if(mset.find(s)!=mset.end()){			// cannot switch char
					end = sidx[v[end][0]-'a']+cnt[v[end][0]-'a'];
					//cout<<"PROOOOOBLEM\n";
				}else{												// can switch char, try each string
					//cout<<"NO PROOOOOBLEM\n";
					for(int j=0; j<cnt[v[end][0]-'a']; j++){
						s = v[end+j];
						s[0] = v[i][0];
						//cout<<s<<" ";
						if(mset.find(s)==mset.end())
							ans++;
					}
					//cout<<endl;
					end+=cnt[v[end][0]-'a'];
				}
			}
		}
		printf("%d\n",2*ans);
		mset.clear();
		v.clear();
		cnt.clear();
	}
	return 0;
}
