// given some denominations, number of ways to form sum=s
// one coin of each type

#include<bits/stdc++.h>
using namespace std;

int main(){
	int **dp, *coin;
	int n, m;
	cin>>n>>m;					
	
	dp = new int*[m+1];					// one row and column extra
	for(int i=0; i<m+1; i++)	dp[i]=new int[n+1];	// row=coin_element, column=sum
	for(int i=0; i<m+1; i++)	dp[i][0]=1;		// 0 sum
	for(int i=1; i<n+1; i++)	dp[0][i]=0;		// no coin	
	
	coin = new int[m];
	for(int i=0; i<m; i++)	cin>>coin[i];
	for(int i=1; i<m+1; i++){		// i=coins uptill i index
		for(int j=1; j<n+1; j++){		// j=sum upto j
			if(j<coin[i-1])	dp[i][j]=dp[i-1][j];		// cannot take coin
			else	dp[i][j]=dp[i-1][j]+dp[i-1][j-coin[i-1]];	// do not take + take
		}
	}
	cout<<dp[m][n]<<endl;
	return 0;
}
// Uses Matrix method to solve the problem
