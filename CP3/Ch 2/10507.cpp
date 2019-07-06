#include<cstdio>
#include<vector>
using namespace std;

vector<vector<int>>	g(26);
vector<int>	v;							// stores all the waked up elements
vector<bool> wake;

int cint(char c){
	return c-'A';
}

bool fcnt(int i){
	int cnt=0;
	for(int j=0; j<g[i].size(); j++){
		if(wake[g[i][j]])	cnt++;
		if(cnt>2)	return true;
	}
	return false;
}

int main(){
	vector<bool> psnt;					// wether alphabet is present or not
	vector<int>	h;						// stores newly waked up elements
	char str[5], c1, c2;
	int n, q, time;
	while(scanf("%d",&n)!=EOF){
		psnt = vector<bool>(26,false);	wake=vector<bool>(26,false);	time=0;
		scanf("%d\n",&q);
		scanf("%s\n",str);	
		for(int i=0; i<3; i++){
			wake[cint(str[i])]=true;	v.push_back(cint(str[i]));
			psnt[cint(str[i])]=true;
		}
		for(int i=0; i<q; i++){
			scanf("%c%c\n",&c1,&c2);
			psnt[cint(c1)]=true;	psnt[cint(c2)]=true;
			g[cint(c1)].push_back(cint(c2));
			g[cint(c2)].push_back(cint(c1));
		}
		while(v.size()<n){
			h.clear();
			for(int i=0; i<26; i++){
				if(psnt[i] && !wake[i] && fcnt(i)){			// if !waken up already and can be waken up
						v.push_back(i);
						h.push_back(i);
				}
			}
			if(h.size()==0)	break;
			for(int i=0; i<h.size(); i++)	wake[h[i]]=true;
			time++;
		}
		if(v.size()!=n)	printf("THIS BRAIN NEVER WAKES UP\n");
		else	printf("WAKE UP IN, %d, YEARS\n",time);
		v.clear();	for(int i=0; i<26; i++)	g[i].clear();	
	}
	return 0;
}
