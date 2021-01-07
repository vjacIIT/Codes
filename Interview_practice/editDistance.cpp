/*
	Given 2 strings s1 and s2, find min no of operations require to convert s1 to s2
	Operations:
		1. Insert a char		2. Delete a char		3. Replace a char
*/

#include<cstdio>
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int main(){
	vector<vector<int>> dp;
	string s1, s2;
	int m, n;
	cin>>s1>>s2;
	m = s1.size();
	n = s2.size();
	dp = vector<vector<int>> (m+1,vector<int>(n+1));
	for(int i=0; i<=m; i++)
		dp[i][0] = i;
	for(int i=0; i<=n; i++)
		dp[0][i] = i;
	
	for(int i=1; i<=m; i++){
		for(int j=1; j<=n; j++){
			if(s1[i-1]==s2[j-1])				// same characters
				dp[i][j] = dp[i-1][j-1];
			else
				dp[i][j] = min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]))+1;
		}
	}
	printf("%d\n",dp[m][n]);
	return 0;
}

/*
	dp[i][j] = min operations required to convert substring s1.substr(0,i) to substring s2.substr(0,j)
	insert is right, remove is down and replace is diagonal
*/
