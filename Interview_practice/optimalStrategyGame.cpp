/*
	Given an array of numbers (size of array is even), there are 2 opponents
	At each turn you can take a number from beginning or the end of the array
	Find the maximum value you can generate if you start at the beginning
	
	NOTE: Taking maximum of the available options is not optimal
	v = [8, 15, 3, 7]
	Greedy = 8 + 7 = 15
	Optimal = 7 + 15 = 22
*/

#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int> v;
vector<vector<int>> dp;

int F(int i, int j){
	if(dp[i][j]!=-1)
		return dp[i][j];
	
	if(i==j)
		return v[i];
	else if(i+1==j)
		return max(v[i],v[j]);
	
	int a = v[i] + min(F(i+1,j-1),F(i+2,j));
	int b = v[j] + min(F(i+1,j-1),F(i,j-2));
	return dp[i][j] = max(a,b);
}

int main(){
	cin>>n;
	v = vector<int>(n);
	dp = vector<vector<int>>(n,vector<int>(n,-1));
	for(int i=0; i<n; i++)
		cin>>v[i];
	printf("Max value generated %d\n",F(0,n-1));
	return 0;
}

/*
	dp[i][j] = maximum value you can get when you have vector only from index i to j

	Suppose your left index is i and right index is j, now there are 2 options:
		1. Take v[i]
			Opponent is also intelligent hence you will get min of the rest 2 values
				dp[i][j] = v[i] + min ( 	F(i+1,j-1)		,		F(i+2,j)		)
										(Opponent takes j'th)	(Opponent takes i+1'th)
		
		2. Take v[j]
			Opponent is also intelligent hece
				dp[i][j] = v[j] + min (		F(i+1,j-1)		,		F(i,j-2)		)
										(Opponent takes i'th)	(Opponent takes j-1'th)
*/
