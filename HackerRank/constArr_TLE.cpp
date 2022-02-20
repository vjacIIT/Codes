// Given an n, we need to find no of ways to construct an array of length n such that:
// 1. First element is 1, last element is x
// 2. There are no same adjacent elements
// 3<=n,k<=10^5

#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

#define loop(i,n)	for(int i=0; i<n; i++)
#define Loop(i,a,n)	for(int i=a; i<n; i++)
#define mp	make_pair
#define pb	push_back

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll>	vll;
typedef pair<int,int> ii;
typedef vector<bool> vb;
typedef vector<vll>	vvll;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const ll mod=1000000007;
vll a;
vvll dp;
ll n, x, k;

ll recurse(int idx){			// need to fill at index idx
	ll ans=0;
	if(idx==n-1){
		if(a[idx-1]==x)	return 0;
		else	return 1;
	}
	Loop(i,1,k+1){
		if(a[idx-1]!=i){
			a[idx]=i;
			if(dp[idx][i]==-1)	dp[idx][i]=recurse(idx+1);
			ans+=dp[idx][i];
			ans%=mod;
			a[idx]=0;
		}
	}
	return ans;
}

int main(){
	ll ans;
	scanf("%lld%lld%lld",&n,&k,&x);
	dp=vvll(n,vll(k+2,-1));			// at i'th index what are the values from 1-k we have put
	a = vll(n,0);	a[0]=1;	a[n-1]=x;
	ans=recurse(1);
	printf("%lld\n",ans);
}

// This goes to TLE
