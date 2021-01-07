/*
	Given n eggs and k floors, what is the minimum no of trials required
	So that we know exactly at which floor egg will break first time
*/

#include<cstdio>
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int n, k;
vector<vector<int>> dp;

int minTrials(int eggs, int floors){
	int res=INT_MAX;
	if(dp[eggs][floors]!=-1)
		return dp[eggs][floors];
	dp[eggs][floors]=INT_MAX;
	for(int i=1; i<=floors; i++){
		res = 1+max(minTrials(eggs-1,i-1),minTrials(eggs,floors-i));
		if(dp[eggs][floors]>res)
			dp[eggs][floors]=res;
	}
	return dp[eggs][floors];
}

int main(){
	cin>>n>>k;
	dp = vector<vector<int>>(n+1,vector<int>(k+1,-1));
	for(int i=1; i<=n; i++){				// i eggs left with 0 floors
		dp[i][0]=0;
		dp[i][1]=1;
	}
	for(int i=0; i<=k; i++)				// one egg left with i floors
		dp[1][i]=i;
	cout<<"min Trials required "<<minTrials(n,k)<<endl;
	return 0;
}

/*
	dp[i][j] = # trials required if we have i eggs and j floors left
	dp[i][j] = 1 + min( max(dp[i-1][x-1]),dp[i][j-x] ) for all x = 1,2....j
*/
