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

vi preSum, tree, ltree, vsum;
int n;


void buildTree(int ind, int st, int end){
	if(st>end)
		return;
	if(st==end){
		tree[ind]=preSum[st];
		return;
	}
	int mid = (st+end)>>1;
	buildTree(2*ind+1, st, mid);
	buildTree(2*ind+2, mid+1, end);
	tree[ind] = max(tree[2*ind+1], tree[2*ind+2]);
	return;
}

void push(int tind, int st, int end){
	int val = ltree[tind];
	ltree[tind]=0;
	tree[tind]-=val;
	if(st!=end){
		ltree[2*tind+1] += val;
		ltree[2*tind+2] += val;
	}
	return;
}

// point update
void updateValue(int tind, int st, int end, int ind, int val){
	// lazy value not zero
	if(ltree[tind]!=0)
		push(tind, st, end);

	// ind out of the current range
	if(st>end || st>ind || end<ind)
		return;
	if(st==end){
		tree[tind] = val;
		return;
	}
	int mid = (st+end)>>1;
	updateValue(2*tind+1, st, mid, ind, val);
	updateValue(2*tind+2, mid+1, end, ind, val);
	tree[tind] = max(tree[2*tind+1], tree[2*tind+2]);
	return;
}

// range update
void updateRange(int tind, int st, int end, int qst, int qend, int val){
	// lazy value not 0
	if(ltree[tind]!=0)
		push(tind, st, end);

	// no overlap
	if(st>end || qend<st || qst>end)
		return;
	// current range is full inside query update range
	if(qst<=st && qend>=end){
		tree[tind]-=val;
		if(st!=end){
			ltree[2*tind+1] += val;
			ltree[2*tind+2] += val;
		}
		return;
	}
	int mid = (st+end)>>1;
	updateRange(2*tind+1, st, mid, qst, qend, val);
	updateRange(2*tind+2, mid+1, end, qst, qend, val);
	tree[tind] = max(tree[2*tind+1], tree[2*tind+2]);
	return;
}

int main(){
	int tc;
	int ans;
	scan(tc);
	loop(t,tc){
		ans=INT_MIN;
		scan(n);
		vvi matrix = vvi(2*n,vi(2*n+1,0));
		loop(i,n){
			Loop(j,1,n+1){
				scan(matrix[i][j]);
				loop(x,2)
					loop(y,2)
						matrix[i+n*x][j+n*y] = matrix[i][j];
			}
		}

		loop(i,2*n)
			Loop(j,1,2*n+1)
				matrix[i][j]+=matrix[i][j-1];

		Loop(l,1,n+1){
			Loop(r,l,l+n){
				vsum = vi(2*n,0);
				preSum = vi(2*n,0);
				tree=vi(4*n, INT_MIN);
				ltree=vi(4*n,0);
				loop(i,2*n)
					vsum[i]=matrix[i][r]-matrix[i][l-1];
				
				// prefix sum array of n elements
				loop(i,2*n){
					preSum[i]=vsum[i];
					if(i)
						preSum[i]+=preSum[i-1];
				}

				// maximum sum subarray with size <=n using prefix sum 
				buildTree(0,0,n-1);
				ans = max(ans, tree[0]);
				loop(i,n){
					// subtract vsum[i] from all the elements
					updateRange(0,0,n-1,0,n-1,vsum[i]);
					// point update, add vsum[i+1] to vsum[i+n]
					updateValue(0,0,n-1,i,preSum[i+n]-preSum[i]);
					ans=max(ans, tree[0]);
				}
			}
		}
		printf("%d\n",ans);
	}

	return 0;
}

// main difference here is to find a maximum sum subarray with size <=n using a segment tree
// Find maximum sum subarray starting with vsum[0] with size <= n, then starting with vsum[1] ..... and starting with vsum[n-1]
// take the max out of it.
// Put prefix sum of from index 0 to n-1. Put that in a segment tree and find the max of each node.
// tree[0] will give me max sum subarray with size <=n starting from vsum[0].
// Now do it for vsum[1] to vsum[n]. And compare with previous max sum subarray.
// Take the max of all.