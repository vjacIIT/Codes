#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;

long long dp[51][51][51];
int n, k, m;

long long totalSymbols(int n2, int k2, int m2){
	if(n2==n){
		// exactly k bars has to be there
		if(k2==k)
			return dp[n2][k2][m2]=1;
		else
			return dp[n2][k2][m2]=0;
	}
	if(k2>=k || m2>=m)
		return dp[n2][k2][m2]=0;
	if(dp[n2][k2][m2]!=-1)
		return dp[n2][k2][m2];
	// if taken the same color, m2->m2+1, else m2->0
	return dp[n2][k2][m2]=totalSymbols(n2+1,k2,m2+1)+totalSymbols(n2+1,k2+1,0);
}

int main(){
	while(scanf("%d%d%d",&n,&k,&m)!=EOF){
		memset(dp, -1, sizeof(dp));
		printf("%lld\n",totalSymbols(0,0,0));
	}
	return 0;
}