// Given No. of staircases n, find the number of ways to reach the top using 1 or 2 steps only

#include<iostream>
#include<climits>
using namespace std;

int *dp;

int nsteps(int n){
	if(n<=0)	return 0;
	if(n==1)	return 1;
	if(n==2)	return 2;
	if(dp[n]!=-1)	return dp[n];
	else dp[n]=nsteps(n-1)+nsteps(n-2);
	return dp[n];
}

int main(){
	int n;
	scanf("%d",&n);
	dp = new int[n+1];
	for(int i=0; i<n+1; i++)	dp[i]=-1;
	printf("%d\n",nsteps(n));
	return 0;
}
