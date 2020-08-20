#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#include<set>
#include<climits>
#include<iostream>
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

vi wt;
vvi dp;

int main(){
	int t, n;
	while(scanf("%d%d",&t,&n)!=EOF){
		wt = vi(n);		dp = vvi(n+1,vi(t+1,0));
		loop(i,n+1)	dp[i][0]=1;
		loop(i,n)	scan(wt[i]);
		sort(wt.begin(),wt.end());
		Loop(i,1,n+1){
			Loop(j,1,t+1){
				if(wt[i-1]>j)	dp[i][j]=dp[i-1][j];
				else	dp[i][j]=dp[i-1][j]+dp[i-1][j-wt[i-1]];
			}
		}
		printf("%d\n",dp[n][t]);
	}
	return 0;
}

// Note: This dp solution is wrong, as it considers all the elements to be different
