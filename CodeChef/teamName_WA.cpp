#include<cstdio>
#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<cstring>
#include<cmath>
#include<algorithm>
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
		for(int i=0; i<n; i++){
			scanf("%s",str);
			v[i] = str;
			mset.insert(str);
			cnt[str[0]-'a']++;
		}
		sort(v.begin(),v.end());
		int end;
		for(int i=0; i<n;){
			end=i;
			while(end<n && v[end][0]==v[i][0])			// for same character
				end++;
			vector<int> cchar = vector<int>(26,0);
			while(i<end){
				string s = v[i];
				//printf("Here for %s         ",s.c_str());
				for(int j=0; j<26; j++){
					if(cnt[j] && j!=(v[i][0]-'a')){
						char c= j+97;
						s[0] = c;
						//printf("%s ",s.c_str());
						if(mset.find(s)==mset.end())
							cchar[j]+=cnt[j];
						else
							cchar[j]--;
					}
				}
				//printf("\n");
				i++;
			}
			for(int j=0; j<26; j++)
				if(cchar[j]>0)
					ans+=cchar[j];
		}
		printf("%d\n",ans);
	}
	return 0;
}
