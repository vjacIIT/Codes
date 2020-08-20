#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
#include<cmath>
#include<climits>
#include<iostream>
using namespace std;

#define loop(i,n)	for(int i=0; i<n; i++)
#define Loop(i,a,n)	for(int i=a; i<n; i++)
#define newline		printf("\n")
#define scan(n)		scanf("%d",&n)
#define print(n)	printf("%d",n)
#define mp	make_pair
#define pb	push_back
const int Mod = 1e9+7;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<vb> vvb;
typedef vector<vi> vvi;
typedef vector<ii> vii;

// See that dp[n][r] = dp[n-1][r] + dp[n-1][r]
// Hence dependent only on last line, hence dp is only 2X(r+1)
// ni&1 helps in switches from 1 to 0 and 0 to 1
int nCr(int n, int k){
	vvi dp;
	dp = vvi(2,vi(k+1,0));
	loop(ni,n+1){
		for(int r=0; r<=k && r<=ni; r++){
			if(r==0 || r==ni)
				dp[ni&1][r]=1;
			else
				dp[ni&1][r] = (dp[(ni-1)&1][r]+dp[(ni-1)&1][r-1])%1000000;
		}
	}
	return dp[n&1][k];
}

int main(){
	int ans, n, k;
	while(scanf("%d%d",&n,&k)!=EOF){
		if(n==0 && k==0)
			break;
		k--;
		ans = nCr(n+k,k);
		printf("%d\n",ans);
	}
	return 0;
}
// Using nCr
// Earlier time Complexity = O(nk)
// Now O((n+k)k), but still it is faster than dp of O(nk), because it is not going to all states
// Space Complexity is less, see the use of previous dp
