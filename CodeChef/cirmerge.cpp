// Question is given an array, we need to choose two adjacent elements and sum them and make them one
// Penalty on each operation will be the sum, we need to minimize the penalty
// Greedy approach of finding the minimum sum of adjacnet elenents and add them will not work

#include<cstdio>
#include<vector>
using namespace std;

int main(){
	vector<vector<long long>> dp;
	vector<long long> a, cf;
	int tc,n,i,j,k,d;
	long long ans,g;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);		ans=(long long)1<<60;
		a = vector<long long>(2*n);		cf = vector<long long>(2*n);
		dp = vector<vector<long long>>(2*n,vector<long long>(2*n,(long long)1<<60));
		for(i=0; i<n; i++)	scanf("%lld",&a[i]);
		for(i=n; i<2*n; i++)	a[i]=a[i%n];
		cf[0]=a[0];
		for(i=1; i<2*n; i++)	cf[i]=cf[i-1]+a[i];
		for(i=0; i<2*n; i++)	dp[i][i]=0;
		for(d=1; d<(2*n)-1; d++){
			for(i=0; i<(2*n)-d; i++){
				j=i+d;
				for(k=i; k<j; k++){
					g=dp[i][k]+dp[k+1][j]+cf[j]-cf[i]+a[i];
					if(g<dp[i][j])	dp[i][j]=g;
				}
			}
		}
		for(i=0; i<n; i++){
			if(ans>dp[i][i+n-1])	ans=dp[i][i+n-1];
		}
		printf("%lld\n",ans);
		for(i=0; i<2*n; i++)	dp[i].clear();
		a.clear();	cf.clear();
	}
	return 0;
}

// This was a dp question on matrix chain multiplication
// To check for circular part, we have made twice the size of the original array and moved in circle
