#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#include<set>
#include<climits>
#include<iostream>
#include<cmath>
using namespace std;

#define loop(i,n)	for(int i=0; i<n; i++)
#define Loop(i,a,n)	for(int i=a; i<n; i++)
#define newline		printf("\n");
#define scan(n)		scanf("%d",&n)
#define mp	make_pair
#define pb	push_back
#define MOD 1000000007

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<bool> vb;
typedef vector<vb>	vvb;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int main(){
	int n;
	int coins[6] = {0, 1, 5, 10, 25, 50};
	ll dp[6][30001];
	memset(dp, 0, sizeof(dp));
	// dp[i][j] = ways to form sum j using i coins only
	loop(i,6)
		dp[i][0]=1;
	Loop(i,1,6){
		Loop(j,1,30001){
			dp[i][j] = dp[i-1][j];
			if(j>=coins[i])
				dp[i][j] = dp[i][j-coins[i]] + dp[i-1][j];
		}
	}
	while(scanf("%d",&n)!=EOF){
		if(n<5)
			printf("There is only 1 way to produce %d cents change.\n",n);
		else
			printf("There are %lld ways to produce %d cents change.\n",dp[5][n],n);
	}
	return 0;
}
