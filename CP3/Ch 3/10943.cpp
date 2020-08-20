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

int n,k;
vvi dp;

int findWays(int i, int csum){
	int ans=0;
	if(csum<0)
		return 0;
	if(dp[i][csum]!=-1)
		return dp[i][csum];
	
	loop(j,n+1){
		if(csum>=j){
			ans+=findWays(i+1,csum-j);					// j added in the sum
			ans%=1000000;
		}
		else
			break;
	}
	return dp[i][csum]=ans;
}

int main(){
	while(scanf("%d%d",&n,&k)!=EOF){
		if(n==0 && k==0)
			break;
		dp = vvi(k,vi(n+1,-1));
		loop(i,k)
			dp[i][0] = 1;				// only 1 way to fill if current sum = 0
		loop(j,n+1)
			dp[k-1][j] = 1;				// k-1 elements filled, last element is (n-j)
		dp[0][n] = findWays(0,n);
		print(dp[0][n]);
		newline;
	}
	return 0;
}


//  dp[i][csum] = total number of ways to fill, with csum(current sum) left, filling the i'th element, 
//  Answer = n+k-1
//  		C	mod 1,000,000, so I will try a nCr = (n-1)Cr + (n-1)C(r-1)
//  		 k-1
//  		 	
//  		 	Next I will try with Chinese remainder theorem
