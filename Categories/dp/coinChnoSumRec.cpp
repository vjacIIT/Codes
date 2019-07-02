//Given infinite supply of some denominations, no of ways to form a sum=n
// This program is a recursive solution of the problem
// It is a 2 state dp problem

#include<bits/stdc++.h>
using namespace std;

int *coin;
int **dp;	// rwo=coin, column=sum
bool **flg;

int fways(int i, int n){		//use coins upto index i and sum is n
	if(n<0)	return 0;
	if(n==0)	return 1;
	if(i<0)	return 0;
	if(flg[i][n]==true)	return dp[i][n];
	flg[i][n]=true;
	if(n<coin[i])	dp[i][n]=fways(i-1,n);
	else	dp[i][n]=fways(i-1,n)+fways(i,n-coin[i]);	// do not take or take
	return dp[i][n];
}

int main(){
	int n, m;
	cin>>n>>m;
	
	dp = new int*[m];
	flg = new bool*[m];
	for(int i=0; i<m; i++){
			dp[i]=new int[n];
			flg[i]=new bool[n];
	}
	
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			flg[i][j]=false;
			dp[i][j]=0;
		}
	}
	
	coin = new int[m];
	for(int i=0; i<m; i++)	cin>>coin[i];
	cout<<fways(m-1,n)<<endl;
	
	return 0;
}
// Time complexity O(n*m)
