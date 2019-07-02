// A pair of node (a,b)are similar if a is ancestor of b and abs(a-b)<=k
// Now we need to find total number of such pairs

#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

vector<vector<int>>	gph(100005);
vector<long int> bit(100005,0);	// binary index tree
int n, k;
long int cnt;

void updateTree(int rt, int val){
	while(rt<=n){
		bit[rt]+=val;
		rt+= (rt&(-rt));
	}
	return;
}

long int fsum(int i){
	long int sum=0;
	while(i>0){
		sum+=bit[i];
		i-=(i&(-i));
	}
	return sum;
}

long int fancestor(int l, int r){
	return (fsum(r)-fsum(l));
}

void dfs(int rt){
	int l= rt-k<0 ? 1:rt-k;			
	int r=rt+k>n ? n:rt+k;
	cnt+=fancestor(l-1,r);						// number of ancestors in range [l,r]
	for(int i=0; i<gph[rt].size(); i++){
		updateTree(rt,1);
		dfs(gph[rt][i]);
		updateTree(rt,-1);
	}
	return;
}

int main(){
	int p, c, *prt, rt;
	scanf("%d%d",&n,&k);
	prt = new int[n+1];	for(int i=0; i<=n; i++)	prt[i]=i;
	for(int i=0; i<n-1; i++){
		scanf("%d%d",&p,&c);
		prt[c]=p;
		gph[p].push_back(c);
	}
	rt=n/2 + 1;			cnt=0;
	while(prt[rt]!=rt)	rt=prt[rt];
	for(int i=0; i<gph[rt].size(); i++){
		updateTree(rt,1);					// increment value by 1 of all those interval which has rt
		dfs(gph[rt][i]);
		updateTree(rt,-1);					// decrement value by 1 of all those interval which has rt
	}
	printf("%ld\n",cnt);
	return 0;
}

// Main Concern: While doing DFS on node we need to tell how many ancestors are there within range [node-k,node+k] for this node
// O(n^2) won't work here
// Hence we use BIT here, wtf HOW ????
// We put 1 in index of ancestor for node, then we need to find how many are ones in range required (how many ancestors are there), this sum of 1's is calculated using BIT
