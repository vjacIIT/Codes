// Number of ways to form sum=n with some denominations
// Repetition is not allowed. Similar to intKnapsack

#include<bits/stdc++.h>
using namespace std;

int *coin;
int **dp;			// two state dp
bool **flg;			// ensures that we have seen that state before

int fways(int n, int i){		// ways to form sum n, using elements upto index i only 
	int add, dnadd;
	if(n==0)	return 1;
	else if(n<0)	return 0;
	if(i==-1)	return 0;
	if(flg[i][n]==true)	return dp[i][n];
	else	flg[i][n]=true;
	if(n-coin[i]<0)	dp[i][n]=fways(n,i-1);
	else{
		add = fways(n-coin[i],i-1);
		dnadd = fways(n,i-1);
		dp[i][n]=add+dnadd;
	}
	return dp[i][n];
}

int main(){
	int n, m;
	cin>>n>>m;	// sum, number of denominations
	coin = new int[m];
	dp = new int*[m];
	flg = new bool*[m];
	for(int i=0; i<m; i++){
		cin>>coin[i];	// value of each denomination
		dp[i]=new int[n];
		flg[i] = new bool[n];		
	}
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++)	flg[i][j]=false;
	}
	cout<<fways(n,m-1)<<endl; 		// sum=n with all the elements
	return 0;
}
// It is very similar to matrix solution, difference is that it just uses recursion
