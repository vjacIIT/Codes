/*
	Given n dices and with each m faces (numbered 1 to m), give number of ways to form sum = x
*/


#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

int n, m, x;
vector<vector<int>> dp;

int ways(int no_dice, int sum){					// no of dice left
	if(dp[no_dice][sum]!=-1)
		return dp[no_dice][sum];
	
	if(sum<no_dice)
		return dp[no_dice][sum]=0;
	
	if(no_dice==sum)
		return dp[no_dice][sum]=1;
		
	dp[no_dice][sum]=0;
	for(int i=1; sum-i>=0 && i<=m; i++)
		dp[no_dice][sum]+=ways(no_dice-1,sum-i);

	return dp[no_dice][sum];
}

int main(){
	cin>>m>>n>>x;
	dp = vector<vector<int>> (n+1,vector<int>(x+1,-1));
	for(int i=1; i<=m && i<=x; i++)
		dp[1][i]=1;
	cout<<"NO of ways "<<ways(n,x)<<endl;
	return 0;
}

/*
	dp[i][j] = # ways to form sum=j, using i dices
*/
