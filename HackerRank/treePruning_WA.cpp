// Given a tree and weights of each node and k, we can do at max k operations
// On each operation we can remove one node with it's subtree
// Finally we need to give maximum weight of tree possible

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
vi prt;
vll wt,dp;								// stores the total weight of node including subtree
vvi tree;

ll dfs(int i){
	loop(s,tree[i].size()){
		if(tree[i][s]!=prt[i]){
			prt[tree[i][s]] = i;
			dp[i] += dfs(tree[i][s]);
		}
	}
	return dp[i];
}

void goUp(int i, ll v){
	dp[i] -= v;
	if(prt[i]!=i)
		goUp(prt[i],v);
	return;
}

void dfs2(int i){
	dp[i]=0;
	loop(s,tree[i].size()){
		if(tree[i][s]!=prt[i])
			dfs2(tree[i][s]);
	}
	return;
}

int fmin(){									// gives node of min values
	int ind;
	ll min = dp[0];
	loop(i,n){
		if(dp[i]<min){
			min=dp[i];
			ind=i;
		}
	}
	return ind;
}

int main(){
	int a, b;
	scan(n);
	scan(k);
	prt = vi(n,0);
	wt = vll(n);
	dp = vll(n);
	tree = vvi(n);
	loop(i,n){
		scanf("%lld",&wt[i]);
		dp[i]= wt[i];
	}
	loop(i,n-1){
		scan(a);
		scan(b);
		a--;	b--;
		tree[a].pb(b);
		tree[b].pb(a);
	}
	dp[0] = dfs(0);							// dp[0] holds the weight of total tree
	loop(i,n)
		printf("%lld ",dp[i]);
	newline;
	a = fmin();								// node of min value
	while(dp[a]<0){							// node with total weight<0, remove that node
		k--;
		cout<<"need to remove "<<a<<endl;
		goUp(prt[a],dp[a]);							// all parents dp values are relaxed
		dfs2(a);									// make dp all subtree nodes of a = 0, no weight
		loop(i,n)
			printf("%lld ",dp[i]);
		newline;
		a = fmin();							// next node with min value
		if(k==0)
			break;
	}
	printf("%lld\n",dp[0]);
	return 0;
}

// Idea: Find the weight for each node with it's subtree included, then find min of weight and remove it, do it while k>=0 && min<0

// Wrong greedy idea -> Test case 
/*
								100
							  /		\
							200		50
								   /   \
								-500   -500

	If k=2, I should take out both -500 one by one
	But my algorithm will take out 50(net weight -950) 
*/ 
