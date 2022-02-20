// Ques: Given n we can do 2 operations:
//		1. Calclate a,b (a!=1 && b!=1) such that a*b = n, reduce n = Max(a,b)
//		2. Reduce n by 1

// Find the min number of moves required to reduce n to 0 


#include<cstdio>
#include<vector>
using namespace std;

vector<int> v;

int main(){
	int qMax = 1000005, b, q;
	vector<int> dp(qMax,qMax);
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	for(int i=1; i<qMax; i++){
		dp[i] = min(dp[i],dp[i-1]+1);				// once calculated never changes
		for(int j=1; j*i<qMax; j++)
			if(i>=j)
				dp[i*j] = min(dp[i]+1,dp[i*j]);			// may change in future
			else if(dp[j]!=qMax)					// dp[j] calculated at least once (may not be right)
				dp[i*j] = min(dp[j]+1,dp[i*j]);
	}
	
	scanf("%d",&q);
	while(q--){
		scanf("%d",&b);
		printf("%d\n",dp[b]);
	}
	return 0;
}

// Time complexity O(nlogn + Q)
// See how all the factors are caculated, it is reverse
// Factor of n is not find, all multiples of i are taken whose value have been calculated earlier
