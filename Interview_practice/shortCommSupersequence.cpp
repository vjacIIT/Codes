#include<cstdio>
#include<vector>
#include<iostream>
using namespace std;

int main(){
	int n, m;
	vector<vector<int>> dp;
	string s1, s2;
	cin>>s1>>s2;
	n = s1.size();
	m = s2.size();
	dp = vector<vector<int>> (n+1,vector<int>(m+1));
	for(int i=0; i<=n; i++){
		for(int j=0; j<=m; j++){
			if(!i)							// if one string is empty
				dp[i][j] = j;
			else if(!j)							// shortest string length is the other one's length
				dp[i][j] = i;		
			else if(s1[i-1]==s2[j-1])
				dp[i][j] = 1+dp[i-1][j-1];
			else
				dp[i][j] = 1+min(dp[i-1][j],dp[i][j-1]);
		}
	}
	cout<<dp[n][m]<<endl;
	return 0;
}
