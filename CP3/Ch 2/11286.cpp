#include<cstdio>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

int main(){
	map<string,int>	mp;
	string s;
	int n, ar[5], mx, cnt;
	while(scanf("%d",&n)!=EOF){
		if(n==0)	break;
		mx=-1;	cnt=0;
		for(int i=0; i<n; i++){
			s.clear();
			for(int j=0; j<5; j++)	scanf("%d",ar+j);
			sort(ar,ar+5);
			for(int j=0; j<5; j++)	s+=to_string(ar[j]);
			mp[s]++;
		}
		for(auto it=mp.begin(); it!=mp.end(); it++)	mx<it->second ? mx=it->second:mx;	
		for(auto it=mp.begin(); it!=mp.end(); it++)	it->second==mx ? cnt+=mx:cnt+=0;
		printf("%d\n",cnt);
		mp.clear();
	}
	return 0;
}
