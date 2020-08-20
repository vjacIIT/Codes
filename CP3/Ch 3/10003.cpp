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
typedef pair<ll,ll> llll;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<vb> vvb;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<llll> vllll;

int n, k;
vi vcut;
vb taken;
int dp[52][52];

int minCost(int s, int e){
	int ans=INT_MAX;
	if(s+1==e)
		return 0;
	if(dp[s][e]!=-1)
		return dp[s][e];
	Loop(k,s+1,e)
		ans = min(ans,minCost(s,k)+minCost(k,e)+vcut[e]-vcut[s]);			// either take cut or not
		
	return dp[s][e]=ans;
}

int main(){
	int ans;
	while(scanf("%d",&n)!=EOF){
		if(!n)
			break;
		memset(dp,-1,sizeof(dp));
		scanf("%d",&k);
		vcut = vi(k+2);
		taken = vb(k,false);
		vcut[0] = 0;													// first cut at 0
		loop(i,k)
			scan(vcut[i+1]);
		vcut[k+1]=n;													// last cut at n (length)
		ans = minCost(0,k+1);
		printf("The minimum cutting is %d.\n",ans);
	}	
	return 0;
}
// Time complexity O(k^3)
// C(ai,ai+1) = 0														// No cut in betweeen
// C(ai,aj) = min [C[ai,ak] + C[ak,aj] + cost(ai,aj)]
// 			for all k
