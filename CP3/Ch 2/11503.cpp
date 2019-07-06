#include<cstdio>
#include<map>
#include<iostream>
#include<vector>
using namespace std;

map<string,int> mp;
vector<int> rnk;
vector<int>	prt;
vector<int>	sz;							// size of the network

int fprt(int i){
	if(prt[i]==i)	return i;
	return prt[i]=fprt(prt[i]);
}

void combine(int i1, int i2){
	sz[i1]=sz[i1]+sz[i2];	sz[i2]=sz[i1];
	if(rnk[i1]>rnk[i2]){
		prt[i2]=i1;	return;
	}
	else{
		prt[i1]=i2;
		rnk[i1]==rnk[i2] ? rnk[i2]++:rnk[i2]+=0;
		return;
	}
}

int main(){
	char n1[50], n2[50];
	string s1, s2;
	int tc, nnames, n, i1, i2;					// total names
	scanf("%d",&tc);
	while(tc--){
		nnames=0;
		scanf("%d\n",&n);
		for(int i=0; i<n; i++){
			scanf("%s %s\n",n1,n2);
			s1=n1;	s2=n2;
			if(mp.find(s1)==mp.end()){
				mp[s1]=nnames;	rnk.push_back(0);	prt.push_back(nnames);	
				sz.push_back(1);	nnames++;
			}
			if(mp.find(s2)==mp.end()){	
				mp[s2]=nnames;	rnk.push_back(0);	prt.push_back(nnames);	
				nnames++;	sz.push_back(1);
			}
			i1 = mp[s1];	i2=mp[s2];
			i1 = fprt(i1);	i2=fprt(i2);
			if(i1!=i2)	combine(i1,i2);
			printf("%d\n",sz[i1]);
		}
		rnk.clear();	prt.clear();	mp.clear();		sz.clear();
	}
	return 0;
}
