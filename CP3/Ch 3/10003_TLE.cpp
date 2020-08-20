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
vvi dp;
// map<pair<int,int>,int> dp;

int findCuts(int s, int e){
	int cnt=0;
	loop(i,k){
		if(!taken[i] && vcut[i]>=s && vcut[i]<=e)
			cnt++;
	}
	return cnt;
}

int minCost(int s, int e){
	int ans=INT_MAX;
	int cnt = findCuts(s,e);
	if(cnt==0 || s>=e)
		return 0;
	if(dp[s][e]!=-1)
		return dp[s][e];
	
	//if(dp[mp(s,e)])
		//return dp[mp(s,e)];
	
	loop(i,k){
		if(!taken[i] && vcut[i]>=s && vcut[i]<=e){
			taken[i]=true;
			int l1 = minCost(s,vcut[i]-1);
			int l2 = minCost(vcut[i],e);
			ans = min(ans,l1+l2+e-s+1);
			taken[i]=false;
		}
	}
	// return dp[mp(s,e)]=ans;
	return dp[s][e]=ans;
}

int main(){
	int ans;
	while(scanf("%d",&n)!=EOF){
		if(!n)
			break;
		dp = vvi(n,vi(n,-1));
		scanf("%d",&k);
		vcut = vi(k);
		taken = vb(k,false);
		loop(i,k)
			scan(vcut[i]);
		ans = minCost(0,n-1);
		printf("The minimum cutting is %d.\n",ans);
	}	
	return 0;
}
// dp[i][j] = what is the minimum cost of cutting from i to j
// So time complexity will be O(k*n^2), hence TLE
// Even when I tried with map(pair<int,int>,int) -> for dp, it got TLE
