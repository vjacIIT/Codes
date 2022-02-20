#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	vector<long long> v = vector<long long>(n);
	vector<vector<long long>> dp = vector<vector<long long>>(n,vector<long long>(n));
	for(int i=0; i<n; i++)
		scanf("%lld",&v[i]);
	sort(v.begin(), v.end());
	for(int l=1; l<=n; l++){
		for(int i=0; i+l<=n; i++){
			int j=i+l-1;
			if(l==1)
				dp[i][j]=0;
			else
				dp[i][j]=min(dp[i][j-1],dp[i+1][j])+(v[j]-v[i]);
		}
	}
	printf("%lld\n",dp[0][n-1]);
	return 0;
}
