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

int n;
vector<pair<int,int>> points;
int dp[11][2048];

int dist(pair<int,int> a, pair<int,int> b){
	return abs(a.first-b.first) + abs(a.second-b.second);
}

int minCycle(int pos, int mask){
	if(mask==((1<<n)-1))
		return dp[pos][mask]=dist(points[0], points[pos]);
	if(dp[pos][mask]!=-1)
		return dp[pos][mask];
	dp[pos][mask] = INT_MAX;
	loop(i,n){
		if((mask&(1<<i))==0)
			dp[pos][mask]=min(dp[pos][mask],minCycle(i,mask|(1<<i))+dist(points[pos],points[i]));
	}
	return dp[pos][mask];
}

int main(){
	int tc, w, h;
	scan(tc);
	while(tc--){
		scanf("%d%d",&w,&h);	
		scanf("%d%d",&w,&h);
		scan(n);
		points = vector<pair<int,int>>(n+1);
		points[0].first = w;
		points[0].second = h;
		loop(i,n)
			scanf("%d%d",&points[i+1].first,&points[i+1].second);
		n++;
		memset(dp, -1, sizeof(dp));
		printf("The shortest path has length %d\n",minCycle(0,1));
	}
	return 0;
}

// starting point is given, do a full cycle tsp and print it