// Given a tree, we need total number of ways to color it in two colors such that each color has atleast one neighbour of same color

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

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<ii> vii;

vvi g;
vi prt;
ll dp[100001][2][2];
vb vist;

ll const Mod=1000000007;

int val(bool b){
	return b==true ? 1:0;
}

bool leaf(int v){				// this has a major role, we should not do as l==1 is leaf
	bool yes=true;
	loop(i,g[v].size()){
		if(g[v][i]!=prt[v])	yes=false;
	}
	return yes;
}

// clr==true ? white:black
ll dfs(int i, bool pclr, bool clr){		// color of vertex i and it's prt same, color of vertex i
	int l=g[i].size(), v1=val(clr), v2=val(pclr);
	ll sum, total=1, invalid=1, cw, cb;
	if(dp[i][v1][v2]!=-1)	return dp[i][v1][v2];
	if(leaf(i))	return (pclr==true ? dp[i][v1][v2]=1:dp[i][v1][v2]=0); 
	loop(j,l){
		int v=g[i][j];
		if(v!=prt[i]){
			cw=dfs(v,clr,true);			// (clr==true ? true:false), white color child
			cb=dfs(v,!clr,false);			// (clr==true ? false:true), black color child
			sum=cw+cb;				
			total=(total*sum)%Mod;			// total possible ways
			if(!pclr){					// clr of parent and node are not same 
				if(clr)	invalid=(invalid*cb)%Mod;	// hence invalid
				else	invalid=(invalid*cw)%Mod;
			}
		}
	}
	if(!pclr)	total=(total-invalid+Mod)%Mod;
	return dp[i][v1][v2]=total;
}

void dfs(int i){
	vist[i]=true;
	int l=g[i].size();
	loop(j,l){
		int v=g[i][j];
		if(!vist[v]){
			prt[v]=i;
			dfs(v);
		}
	}
	return;
}

void reset(int n){
	loop(i,n+1){
		loop(j,2){	dp[i][j][0]=-1;	dp[i][j][1]=-1;	}
	}
	return;
}

int main(){
	ll ans;
	int n, v1, v2;
	scan(n);
	g=vvi(n);	prt=vi(n,0);	vist=vb(n,false);	reset(n);
	loop(i,n-1){
		scanf("%d%d",&v1,&v2);	v1--;	v2--;
		g[v1].pb(v2);	g[v2].pb(v1);
	}
	prt[0]=0;	dfs(0);
	ans=dfs(0,false,true);
	printf("%lld\n",(2*ans)%Mod);
	return 0;
}

// This is a dp approach:
// At every node, we find total number of ways to color it's child and multiply
// And we subtract the invalid number of ways by (when node's parent as well as all it's children have different color from node's color)
