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

int n, m, p;
int storePrice[14], storeNo[14];		// -1 if not a store, else stores amount that can be saved
int dist[51][51];				// min distance required to reach from i'th shop to 0
int dp[14][16385];

int saveMoney(int pos, int mask){
	int d;
	if(mask==(1<<p)-1)
		return -dist[0][storeNo[pos]];	// min dist req from 0 to pos, also our loss  
	if(dp[pos][mask]!=-1)
		return dp[pos][mask];
	dp[pos][mask]=-dist[0][storeNo[pos]];
	loop(i,p){
		if(!(mask & (1<<i))){
			d = storePrice[i]-dist[storeNo[pos]][storeNo[i]];
			d+=saveMoney(i,mask|(1<<i));
			dp[pos][mask]=max(d,dp[pos][mask]);
		}
	}
	return dp[pos][mask];
}

int main(){
	int tc, v1, v2;
	double wt;
	scan(tc);
	while(tc--){
		scanf("%d%d",&n,&m);
		n++;
		memset(storePrice, 0, sizeof(storePrice));
		memset(storeNo, 0, sizeof(storeNo));
		memset(dp, -1, sizeof(dp));
		loop(i,51){
			loop(j,51)
				dist[i][j]=1e8;
			dist[i][i]=0;
		}
		loop(i,m){
			scanf("%d%d%lf",&v1,&v2,&wt);
			dist[v1][v2]=min(dist[v1][v2],(int)round(wt*100.0));
			dist[v2][v1]=dist[v1][v2];
		}
		// floyd warshell
		loop(k,n)
			loop(i,n)
				loop(j,n)
					dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
		scan(p);
		p++;
		storePrice[0]=0;
		storeNo[0]=0;
		loop(i,p-1){
			scanf("%d%lf",&v1,&wt);
			storePrice[i+1]=(int)round(wt*100.0);
			storeNo[i+1]=v1;
		}
		v1 = saveMoney(0,1);	
		if(v1<=0)
			printf("Don't leave the house\n");
		else
			printf("Daniel can save $%.2f\n",((double)v1)/100.0);
	}
	return 0;
}

// We need to do state compression so that we operate only on stores not on all vertices

// mask has only stores and iterate over stores only
// when jumping from one store to another, use min distance from each other (use floyd warshell for that)

// When reaching all the stores then returning the min distance from there to 0'th vertex (home)