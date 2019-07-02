// Given an array of +ve integers
// Divide it into 2 subsets such that absolute difference of sum of them is minimum

#include<iostream>
#include<vector>
using namespace std;

int absolute(int a, int b){
	if(a>b)	return a-b;
	return b-a;
}

int main(){
	int n, sum, v, ind, sum1, sum2, tc;
	cin>>tc;
	while(tc--){
		sum=0;	
		cin>>n;		// number of elements
		vector<vector<bool>> dp(n+1);	// rows defined, 0th row for no elements
		vector<int> val;
		for(int i=0; i<n; i++){
			cin>>v;
			sum+=v;
			val.push_back(v);
		}
		for(int i=0; i<=n; i++)	dp[i]=vector<bool>(sum+1);	
		for(int i=0; i<=n; i++)	dp[i][0]=true;			// 0 sum always possible
		for(int i=1; i<sum+1; i++)	dp[0][i]=false;		// non-zero sum with no elements
		for(int i=1; i<n+1; i++){
			for(int j=1; j<sum+1; j++){
				if(dp[i-1][j])	dp[i][j]=true;
				else if(j>=val[i-1] && dp[i-1][j-val[i-1]]) dp[i][j]=true;
				else	dp[i][j]=false;	
			}
		}
		ind = sum/2;
		while(!dp[n][ind])	ind--;		// use all elements, if sum possible
		cout<<sum-2*ind<<endl;
		val.clear();
		dp.clear();
	} 
		return 0;
}

// Time complexity is O(n*n*k), n==number of elements, k==maximum of all the elements
// Time complexity is O(n*sum)	sum==sum of all the elements of the array
// This is an np hard problem
