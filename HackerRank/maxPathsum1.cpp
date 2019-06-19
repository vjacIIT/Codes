#include<iostream>
using namespace std;

int n, **ar, **dp;

int fmax(int i, int j){
	if(i==n)	return 0;
	else if(dp[i][j]!=-1)	return dp[i][j];
	int sum=ar[i][j];
	int p1 = fmax(i+1,j);		// go down
	int p2 = fmax(i+1,j+1);		// go right
	sum+= (p1>p2) ? p1:p2;
	dp[i][j]=sum;
	return dp[i][j];
}

int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		ar = new int*[n];
		dp = new int*[n];
		for(int i=0; i<n; i++){
			ar[i]=new int[n];
			dp[i]=new int[n];
		}
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				ar[i][j]=0;
				dp[i][j]=-1;
			}
		}
		for(int i=0; i<n; i++){
			for(int j=0; j<=i; j++)	scanf("%d",&ar[i][j]);
		}
		printf("%d\n",fmax(0,0));
		for(int i=0; i<n; i++){
			delete []ar[i];
			delete []dp[i];
		}
		delete []ar;
		delete []dp;
	}
	return 0;
}
