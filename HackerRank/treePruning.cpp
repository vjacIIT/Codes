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

int n, k;
vi postOrder, prt, subTree;
vll wt;
vvi tree;
vvll dp;

int dfs(int i){
	postOrder.pb(i);
	loop(s,tree[i].size()){
		if(tree[i][s]!=prt[i]){
			prt[tree[i][s]] = i;
			subTree[i]+=dfs(tree[i][s]);
		}
	}
	return subTree[i];
}


int main(){
	ll ans=-1;
	int a, b;
	scan(n);
	scan(k);
	wt = vll(n);
	prt = vi(n,0);
	subTree = vi(n,1);						// size of subtree including itself
	tree = vvi(n);
	dp = vvll(n+1,vll(k+1));
	loop(i,n)
		scanf("%lld",&wt[i]);
	loop(i,n-1){
		scan(a);
		scan(b);
		a--; b--;
		tree[a].pb(b);
		tree[b].pb(a);		
	}
	subTree[0] = dfs(0);
	reverse(postOrder.begin(),postOrder.end());
	loop(i,k+1)
		dp[0][i]=0;							// seen 0 elements in PostOrder, what is max weight of tree
	Loop(i,1,n+1)
		dp[i][0]= dp[i-1][0] + wt[postOrder[i-1]];
	// Logic, dp[i][0] = dp[i-1][0]+wt[i] = dp[i-2][0]+wt[i-1]+wt[i]....= dp[0][0]+wt[1]+wt[2]....wt[n]
	// dp[i][0]=sum over i (wt[i])
		
	Loop(i,1,n+1)
		Loop(j,1,k+1)
			dp[i][j] = max(dp[i-1][j]+wt[postOrder[i-1]],dp[i-subTree[postOrder[i-1]]][j-1]);
	
	printf("%lld\n",dp[n][k]);				// seen all elements and can do at max k operations
	return 0;
}

// At i'th element -> either take it or not
//dp[i][j] = After seeing i-1 elements from left in postOrder array (deciding for i'th element), what is the maxium weight of tree can be formed if we remove atmost j nodes 
