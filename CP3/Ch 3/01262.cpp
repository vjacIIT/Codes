#include<cstdio>
#include<vector>
#include<iostream>
using namespace std;

vector<string> ans;
vector<vector<char>> v;

void permute(int i, string s){
	if(i==5){
		ans.push_back(s);
		return;
	}
	int l = v[i].size();
	char c;
	for(int j=0; j<l; j++){
		c = v[i][j];
		permute(i+1,s+c);
	}
	return;
}

int main(){
	vector<vector<char>> m1, m2;
	vector<bool> cnt1, cnt2;
	int tc, k;
	scanf("%d",&tc);
	while(tc--){
		m1 = vector<vector<char>>(6,vector<char>(5));
		m2 = vector<vector<char>>(6,vector<char>(5));
		v = vector<vector<char>>(5);
		scanf("%d\n",&k);
		for(int i=0; i<6; i++)
			scanf("%s",&m1[i][0]);
		for(int i=0; i<6; i++)
			scanf("%s",&m2[i][0]);
		
		for(int j=0; j<5; j++){
			cnt1 = vector<bool>(26,0);
			cnt2 = vector<bool>(26,0);
			for(int i=0; i<6; i++){
				cnt1[m1[i][j]-'A']=1;
				cnt2[m2[i][j]-'A']=1;
			}
			for(int i=0; i<26; i++){
				if(cnt1[i] && cnt2[i])
					v[j].push_back(i+65);
			}
			cnt1.clear();	cnt2.clear();
		}
		permute(0,"");
		if(ans.size()<k)	printf("NO\n");
		else	printf("%s\n",ans[k-1].c_str());
		ans.clear();	v.clear();
	}
	return 0;
}
