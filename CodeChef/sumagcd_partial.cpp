#include<cstdio>
#include<iostream>
using namespace std;

int *ar,n,mx;

int fGCD(int sm, int big){
	if(sm==0)	return big;
	return fGCD(big%sm,sm);
}

void allSubset(int nzero, int none, string s){
	int gcd1=-1, gcd2=-1;
	if(nzero+none==n){
		if(nzero==n || none==n)	return;
		//for(int i=0; i<n; i++)	printf("%c ",s[i]);
		for(int i=0; i<n; i++){
			if(s[i]=='0'){
				if(gcd1==-1)	gcd1=ar[i];
				else if(gcd1!=1)	gcd1=fGCD(gcd1,ar[i]);
			}
			else{
				if(gcd2==-1)	gcd2=ar[i];
				else if(gcd2!=1)	gcd2=fGCD(gcd2,ar[i]);
			}	
		}
		//printf("%d %d\n",gcd1,gcd2);
		if(mx<gcd1+gcd2)	mx=gcd1+gcd2;
		return;
	}
	allSubset(nzero+1,none,s+"0");
	allSubset(nzero,none+1,s+"1");
	return;
}

int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--){
		mx=-1;
		scanf("%d",&n);
		ar = new int[n];
		for(int i=0; i<n; i++)	scanf("%d",ar+i);
		allSubset(0,0,"");			// no of 0's and 1's
		printf("%d\n",mx);	
	}
	return 0;
}
