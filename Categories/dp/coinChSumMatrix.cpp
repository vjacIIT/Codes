// no of ways to form sum=n using denominations
// infinite of each type

#include<bits/stdc++.h>
using namespace std;

int *coin;
int **dp;
bool **flg;

int main(){
	int n, m;
	cin>>n>>m;
	
	dp = new int*[m+1];		// padding for base case
	flg = new bool*[m+1];
	for(int i=0; i<m+1; i++){
		dp[i]=new int[n+1];
		flg[i]=new bool[n+1];
	}
	for(int i=0; i<m+1; i++){
		for(int j=0; j<n+1; j++){
			dp[i][j]=0;
			flg[i][j]=false;
		}
	}
	for(int i=0; i<m+1; i++)	dp[i][0]=1;	// sum=0
	for(int i=1; i<n+1; i++)	dp[0][i]=0;	// no coin
	
	coin = new int[m];
	for(int i=0; i<m; i++)	cin>>coin[i];

	for(int i=1; i<m+1; i++){
		for(int j=1; j<n+1; j++){
			if(j<coin[i-1])	dp[i][j]=dp[i-1][j];	// do not take coin
			else	dp[i][j]=dp[i-1][j]+dp[i][j-coin[i-1]];
		}
	}
	cout<<dp[m][n]<<endl;
	return 0;
}
