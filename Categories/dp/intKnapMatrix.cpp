// Given denominations with profit, find maximum profit with sum of weights <= capacity
// Time complexity is O(c*n), donot works if c is high

#include<bits/stdc++.h>
using namespace std;

long int **dp;
vector<pair<long int,long int>> v;	// weight,profit pair

long int mpft(long int a, long int b){
	if(a>b)	return a;
	return b;
}

int main(){
	long int c,n,w,p;	// capacity and number of objects
	cin>>c>>n;
	for(int i=0; i<n; i++){
		cin>>w>>p;
		v.push_back(make_pair(w,p));
	}
	sort(v.begin(),v.end());	// sort based on weight
	
	dp = new long int*[n+1];		// row=weight,profit	column=capacity
	for(int i=0; i<n+1; i++)	dp[i]=new long int[c+1];
	for(int i=0; i<n+1; i++){
		for(int j=0; j<c+1; j++)	dp[i][j]=0;
	}
	
	for(int i=1; i<n+1; i++){
		for(int j=1; j<c+1; j++){
			if(j<v[i-1].first)	dp[i][j]=dp[i-1][j];
			else{
				dp[i][j]=mpft(dp[i-1][j],dp[i-1][j-v[i-1].first]+v[i-1].second);	
				// do not take, take
			}
		}
	}
	cout<<dp[n][c]<<endl;
	return 0;
}
