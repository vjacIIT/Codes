// Given a set of numbers, find the maximum xor possible using any subset of set

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

vi a;
vvi dp;

int main(){
	int n, nbits, mmax, k, tc;
	scan(tc);
	while(tc--){
		nbits=0;
		mmax = -1;
		scan(n);
		scan(k);
		a = vi(n);
		loop(i,n){
			scan(a[i]);
			mmax = max(mmax,a[i]);
		}
		 while(mmax>0){
		     nbits++;
		     mmax/=2;
		 }
		 mmax = (1<<nbits)-1;                    // Maximum xor possible
		 dp = vvi(n+1,vi(mmax+1,0));
		 dp[0][0] = 1;                           // number of subsets of empty set with Xor = 1
		 Loop(i,1,n+1){
		     loop(j,mmax+1){
		     	dp[i][j] = dp[i-1][j] + dp[i-1][j^a[i-1]];
				if(dp[i][j])
					dp[i][j]=1;	
			}
		}
		nbits=-1;
		loop(i,mmax+1){
			if(dp[n][i])
				nbits = max(nbits,i^k);
		}
		printf("%d\n",nbits);
	}
	return 0;
}
