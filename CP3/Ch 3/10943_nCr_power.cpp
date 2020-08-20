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

vi isPrime;
const int MOD = 1e6;

int countFact(int n, int p){						// gives exponent of prime p in n!
	int e=0;
	while(n>0){
		e+=n/p;
		n/=p;
	}
	return e;
}

ll power(int p, int e){
	ll pw;
	if(e==0)
		return 1;
	if(e%2==1)
		return (p*power(p,e-1))%MOD;
	else{
		pw = power(p,e/2);
		return (pw*pw)%MOD;
	}
}

ll nCr(int n, int r){
	int e;
	ll ans=1;
	if(r==0)
		return 1;
	for(int p=2; p<=n; p++){
		if(isPrime[p]){
			e = countFact(n,p)-countFact(r,p)-countFact(n-r,p);
			// Actual power of prime i left in nCr, time O(logn)
			ans = (ans*power(p,e))%MOD;				// Takes O(log(e)), i.e. O(loglogn	)
		}
	}
	return ans;
}

int main(){
	int n=200, k;
	ll ans;
	isPrime = vi(200,1);
	isPrime[0]=0;
	isPrime[1]=0;
	// Here i is a factor for a number
	// For any number to be prime, there shouldn't be any factor till sqrt(n)
	for(int i=2; i*i<=n; i++){						// O(nloglogn)
		if(isPrime[i]){
			for(int j=2; i*j<=n; j++)				// all multiples of i are not prime
				isPrime[i*j]=0;
		}
	}
	while(scanf("%d%d",&n,&k)!=EOF){
		if(n==0 && k==0)
			break;
		ans = nCr(n+k-1,k-1);
		printf("%lld\n",ans);
	}
	return 0;
}
// Time Complexity O(nloglogn + nlogn)
// isPrimes takes O(nloglogn) and nCr takes(nlogn)
