#include<bits/stdc++.h>
using namespace std;

vector<int> coin;
bool *flg;
int *dp;

int fmin(int n){
	int min=INT_MAX, cmin;
	if(n<0)	return INT_MAX/2;
	if(n==0)	return 0;
	if(flg[n]==true)	return dp[n];
	flg[n]=true;
	for(int i=0; i<coin.size(); i++){
		cmin = fmin(n-coin[i])+1;	// takes account of taking and not taking of coin
		if(cmin<min)	min=cmin;
	}
	dp[n]=min;
	return dp[n];
}

int main(){
	int n,m, min;
	cin>>n>>m;
	dp = new int[n+1];
	flg = new bool[n+1];
	for(int i=0; i<n+1; i++){
		flg[i] = false;
		dp[i] = INT_MAX;
	}
	for(int i=0; i<m; i++){
		cin>>min;
		coin.push_back(min);
	}
	sort(coin.begin(), coin.end());
	min=fmin(n);
	cout<<min<<endl; 
	return 0;
}

// Time is O(n*m)
// Only 1D array dp is used
