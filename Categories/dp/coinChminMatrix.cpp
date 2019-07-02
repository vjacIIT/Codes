// we are given some coins and we need to find the minimum number of coins to reach a sum s
// we have infinite number of coins of each type
// this program is a matrix solution of the problem using dp

#include<bits/stdc++.h>
using namespace std;

vector<int> vc;			// stores value of each coin
int **dp;

int fmin(int a, int b){
	if(a>b)	return b;
	return a;
}

void pPrt(int i, int j){		// indices i and j
	if(i==0 || j==0)	return;
	if(dp[i][j]==dp[i-1][j])	pPrt(i-1,j);		// we did not take this coin
	else{					// we took the coin
		cout<<vc[i-1]<<" ";
		pPrt(i,j-vc[i-1]);
	}
	return;
}

int main(){
	int n, m, t, dt;
	cin>>n;			// sum which we want to make
	cin>>m;			// number of different denominations	
	
	dp = new int*[m+1];	
	for(int i=0; i<=m; i++)	dp[i]=new int[n+1];
	for(int i=0; i<=m; i++)	dp[i][0]=0;		// sum = 0
	for(int i=1; i<=n; i++)	dp[0][i]=INT_MAX-1;		// zero value coins
	
	for(int i=0; i<m; i++){
		cin>>t;			// value of each coin
		vc.push_back(t);
	}
	sort(vc.begin(),vc.end());
	
	for(int i=1; i<m+1; i++){
		for(int j=1; j<n+1; j++){
			if(j>=vc[i-1]){
				t = dp[i][j-vc[i-1]]+1;		// take coin
				dt = dp[i-1][j];		// do not take coin 
			}
			else{
				t=INT_MAX;
				dt = dp[i-1][j];
			}
			dp[i][j]=fmin(t,dt);
		}
	}
	cout<<dp[m][n]<<endl;
	pPrt(m,n);		// printing coins which are taken
	cout<<endl;
	return 0;
}

// Time Complexity O(n*m)

// Logic: Cell in grid-> dp[i][j] -> if sum = j and we have all the coins from vc[0] to vc[i] what is the minimum number of coins possible
// value of the coins are in sorted order
// Program takes O(n*m) time
