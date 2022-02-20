// Given n, k ans x
// We need to find total number of arrays of length n, with each value between 1-k, A[1]=1 and A[n]=x
// Also none of the adjacent elements have same elements

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
typedef vector<ii> vii;
typedef vector<ll> vll;

ll const prm=1000000007;			// this is a prime number
ll n, k, x;
vll dp;

ll fmod(ll i){
	ll ph;
	if(i==0)	return 1;
	if(i%2==0){
		ph=fmod(i/2);
		return (ph*ph)%prm;
	}
	else{
		ph=fmod(i-1);
		return (ph*(k-1))%prm;
	}	
}

ll countArray(){
	Loop(i,2,n+1){
		dp[i]=(((k-1)*dp[i-2]) + ((k-2)*dp[i-1]))%prm;
	}
	return x==1 ? dp[n-1]:dp[n]*fmod(prm-2);	// using fermat's little theorem
}

int main(){
	ll ans;
	scanf("%lld%lld%lld",&n,&k,&x);
	dp = vll(n+5,-1);	dp[0]=1;	dp[1]=0;
	ans=countArray();
	printf("%lld\n",ans%prm);
	return 0;
}

// dp[i] is the number of ways such that A[1]=1, A[i]!=1 and adjacent elements are not same

// Concept is that if last element!=1 then total choices are same irrespective last element is 2,3...k (anything)
// So there are two casses, last element is 1 or not
// If it is one x==1, ans=dp[n-1], else ans=dp[n]/(k-1) 

// dp[0]=1, no element, 1 possibilty
// dp[1]=0, one element but it has to be 1, but dp[1] where dp[1]!=1 so zero
// Fermat's little theorem, a^(p-1)~== 1(mod p) 
