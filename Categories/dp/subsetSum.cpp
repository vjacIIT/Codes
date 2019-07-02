// Given set of elements, find that sum s is possible from them or not

#include<iostream>
#include<algorithm>
using namespace std;

bool **dp;
int *v;

int main(){
	int sum, n;		// sum, no of elements in set
	cin>>sum>>n;
	
	dp = new bool*[n+1];
	for(int i=0; i<n+1; i++)	dp[i]=new bool[sum+1];
	for(int i=1; i<sum+1; i++)	dp[0][i]=false;		// set element=0
	for(int i=0; i<n; i++)	dp[i][0]=true;			// sum=0
	
	v = new int[n];
	for(int i=0; i<n; i++)	cin>>v[i];
	sort(v, v+n);
	
	for(int i=1; i<n+1; i++){
		for(int j=1; j<sum+1; j++){
			if(dp[i-1][j])	dp[i][j]=true;		// j not included
			else if(j>=v[i-1] && dp[i-1][j-v[i-1]])	dp[i][j]=true;		// included
			else	dp[i][j]=false;
		}
	}
	cout<<dp[n][sum]<<endl;
	return 0;
}

// Time complexity O(s*n), np complete
