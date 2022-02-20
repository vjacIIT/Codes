// Given a number n, we make a set of numbers 0 to 2^n - 1
// Find the number of subsets of this set whose xor is 0

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

int mcount;
vvi answer(100000);

ll power(ll a, ll b, ll mod){
	ll h;
	if(b==0)
		return 1;
	if(b%2)
		return (a*power(a,b-1,mod))%mod;
	else{
		h = power(a,b/2,mod);
		return (h*h)%mod;
	}
}

int main(){
	int t;
	ll n, r;
	scan(t);
	while(t--){
		mcount=0;
		scanf("%lld",&n);
		r = (power(2,n,Mod-1) - n%(Mod-1) + Mod-1)%(Mod-1);
		printf("%lld\n",power(2,r,Mod));
	}
	return 0;
}
// So the answer is straight 2^(2^n - n) % Mod
