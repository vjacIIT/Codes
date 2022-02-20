/*
	cutting sticks problem with knuth's optimisation
	dp[left][right] = Cost[i][j] + min(dp[left][k]+dp[k][right]) for all k in [left+1,right-1]
	Idea: Instead of going to all the k in [left+1,right-1], we only go to a few of coordinates
		Suppose ind[i][j] be the index k for which dp[left][right] be minimum
		We can prove that ind[i][j-1]<=ind[i][j]<=ind[i+1][j], 
		hence due to this we search only from ind[i][j-1] to ind[i+1][j]
	Time Complexity: O(n^2)
*/

#include<cstdio>
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<vector<int>> dp, idx;
vector<int> cut;

int minCut(int left, int right){
	int curr, ind;
	if(left+1>=right){
		idx[left][right] = right;
		return dp[left][right] = 0;
	}
	if(dp[left][right]!=-1)
		return dp[left][right];
	
	minCut(left,right-1);
	minCut(left+1,right);
	dp[left][right] = INT_MAX;
	for(int i=idx[left][right-1]; i<=idx[left+1][right]; i++){
		curr = minCut(left,i)+minCut(i,right)+cut[right]-cut[left];
		if(curr<dp[left][right]){
			dp[left][right] = curr;
			ind = i;
		}
	}
	idx[left][right] = ind;
	return dp[left][right];
}

int main(){
	int l, ncut;
	scanf("%d",&l);
	while(l){
		scanf("%d",&ncut);
		dp = vector<vector<int>>(ncut+2,vector<int>(ncut+2,-1));
		idx = vector<vector<int>>(ncut+2,vector<int>(ncut+2,0));
		cut = vector<int>(ncut+2,0);
		cut[0] = 0;											// starting
		cut[ncut+1]=l;										// ending
		for(int i=1; i<=ncut; i++)
			scanf("%d",&cut[i]);
		minCut(0,ncut+1);
		printf("The minimum cutting is %d.\n",dp[0][ncut+1]);
		scanf("%d",&l);
	}
	return 0;
}
