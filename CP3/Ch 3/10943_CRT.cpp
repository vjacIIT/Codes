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

const int mx = 1e6+6;
vll isPrime(mx,1);
vllll factor;
vll nfact(mx);
vllll remains;

ll power(ll p, ll q, ll mod){
	ll h;
	if(q==0)
		return 1;
	if(q%2)
		return (p*power(p,q-1,mod))%mod;
	else{
		h = power(p,q/2,mod);
		return (h*h)%mod;
	}
}

ll E(ll n, ll p){
	ll e=0;
	while(n>0){
		e+=n/p;
		n/=p;
	}
	return e;
}

void preCal(ll p, ll mod){
	ll x;
	nfact[0]=1;
	nfact[1]=1;
	Loop(i,2,mod){
		if(i%p)
			x = i;
		else
			x = 1;
		nfact[i] = (nfact[i-1]*x)%mod;					// nfact[i] = (i!)p % p^q
	}
	return;
}

// f(n) =  ((f(mod-1)^n/mod)*f(n%mod))%mod
ll f(ll n, ll mod){
	ll ret;
	ret = power(nfact[mod-1],n/mod,mod)*nfact[n%mod];
	return ret%mod;
}

ll F(ll n, ll p, ll mod){								// gives (n!)p % p^q
	ll ret=1, np=1;
	while(np<=n){
		ret = ret*f(n/np,mod);
		ret = ret%mod;
		np = np*p;
	}
	return ret;
}

void gcd(ll a, ll b, ll& x, ll& y){						// assuming gcd has to be 1
	ll temp;
	if(b%a==0){
		x = 1;
		y = 0;
		return;
	}
	gcd(b%a,a,x,y);
	temp = x;
	x = y - (b/a)*x;
	y = temp;
	return;
}

ll inv(ll a, ll b){										// inverse of a wrt b
	ll x, y;
	gcd(a,b,x,y);
	return (x+b)%b;
}

ll nCr(ll n, ll r, ll p, ll mod){						// nCr mod p^q
	ll e, r1, r2, ret;
	e = E(n,p)-E(r,p)-E(n-r,p);
	r1 = F(n,p,mod);									// gives (n!)p % p^q
	r2 = (F(r,p,mod)*F(n-r,p,mod))%mod;
	r2 = inv(r2,mod);
	ret = power(p,e,mod);
	ret = (ret*r1)%mod;
	ret = (ret*r2)%mod;
	return ret;
}

// x = r1 (mod a1)
// x = r2 (mod a2)
// x = r3 (mod a3)
// x = (sum(riMi(Mi^-1)))%M, where Mi^-1 is inverse of Mi wrt ai
// M = product of ai
// Mi = M/ai
// Note: M is also equal to m whose modulo we need to get in the starting
// Because each ai = pi^qi from m itself

ll chineseRemainder(int k, ll M){								// now we have k equations
	ll ans=0, ai, ri;
	// ll M=1;
	//loop(i,k)
		//M*=remains[i].second;							// This is M
	
	loop(i,k){
		ai = remains[i].second;
		ri = remains[i].first;
		ans+=ri*(M/ai)*inv(M/ai,ai);
		ans%=M;
	}
	return ans;
}

ll nCr_mod_m(ll n, ll r, ll m){
	remains.clear();
	factor.clear();
	ll cnt=0, p, q, ans, mm=m;
	int k;
	for(int i=2; i*i<=m; i++){
		if(isPrime[i] && m%i==0){
			cnt=0;
			while(m%i==0){
				cnt++;
				m/=i;
			}
			factor.pb(mp(i,cnt));
		}
	}
	if(m>1)
		factor.pb(mp(m,1));

	k = factor.size();
	loop(i,k){
		p = factor[i].first;
		q = factor[i].second;
		cnt = power(p,q,Mod);
		preCal(p,cnt);							// calculates (i!)p mod p^q for each prime in m
		remains.pb(mp(nCr(n,r,p,cnt),cnt));		// remainder, p^q
	}
	
	ans = chineseRemainder(k,mm);
	return ans;
}

void seive(){
	isPrime[0]=0;
	isPrime[1]=0;
	Loop(i,2,mx)
		if(isPrime[i])
			for(int j=2; i*j<=mx; j++)
				isPrime[i*j]=0;
	return;
}

int main(){
	seive();
	ll n, r, m=1000000;
	while(scanf("%lld%lld",&n,&r)!=EOF){
		if(n==0 && r==0)
			break;
		n = n+r-1;
		printf("%lld\n",nCr_mod_m(n,r-1,m));
	}
	return 0;
}
