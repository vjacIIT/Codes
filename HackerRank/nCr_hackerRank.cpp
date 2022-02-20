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
vllll factor(4);
vvll nfact(4,vll(40));
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

void preCal(int k, ll p, ll mod){
	ll x;
	nfact[k][0]=1;
	nfact[k][1]=1;
	Loop(i,2,mod){
		if(i%p)
			x = i;
		else
			x = 1;
		nfact[k][i] = (nfact[k][i-1]*x)%mod;					// nfact[i] = (i!)p % p^q
	}
	return;
}

// f(n) =  ((f(mod-1)^n/mod)*f(n%mod))%mod
ll f(ll p, ll n, ll mod){
	ll ret;
	int k;
	if(p==3)
		k=0;
	else if(p==11)
		k=1;
	else if(p==13)
		k=2;
	else
		k=3;

	ret = power(nfact[k][mod-1],n/mod,mod)*nfact[k][n%mod];
	return ret%mod;
}

ll F(ll n, ll p, ll mod){								// gives (n!)p % p^q
	ll ret=1, np=1;
	while(np<=n){
		ret = ret*f(p,n/np,mod);
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
	if(b==11 || b==13 || b==37)
		return power(a,b-2,b);
	gcd(a,b,x,y);
	return (x+b)%b;
}

ll nCr(ll n, ll r, ll p, ll mod){						// nCr mod p^q
	ll e, r1, r2, ret;
	e = E(n,p)-E(r,p)-E(n-r,p);
	ret = power(p,e,Mod);
	if(ret>=mod)
		return 0;
	r1 = F(n,p,mod);									// gives (n!)p % p^q
	r2 = (F(r,p,mod)*F(n-r,p,mod))%mod;
	r2 = inv(r2,mod);
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
	factor.clear();
	remains.clear();
	ll cnt=0, p, q, ans, mm=m;
	int k=4;
	loop(i,k){
		p = factor[i].first;
		q = factor[i].second;
		cnt = power(p,q,Mod);
		remains.pb(mp(nCr(n,r,p,cnt),cnt));		// remainder, p^q
	}
	
	ans = chineseRemainder(k,mm);
	return ans;
}

int main(){
	factor[0] = mp(3,3);
	factor[1] = mp(11,1);
	factor[2] = mp(13,1);
	factor[3] = mp(37,1);
	preCal(0,3,27);							// calculates (i!)p mod p^q for each prime in m
	preCal(1,11,11);
	preCal(2,13,13);
	preCal(3,37,37);
	int tc;
	ll n, r, m;
	scan(tc);
	while(tc--){
		scanf("%lld%lld",&n,&r);
		m=142857;
		printf("%lld\n",nCr_mod_m(n,r,m));
	}
	return 0;
}
