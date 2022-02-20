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

ll gcd(ll a, ll b){
	if(b==0)
		return a;
	if(a==0)
		return b;
	if(b%a==0)
		return a;
	return gcd(b%a,a);
}

int main(){
	vll a;
	ll g, k;
	int n, q;
	scan(n);
	a = vll(n);
	scan(q);
	loop(i,n)
		scanf("%lld",&a[i]);
	
	g = 0;
	Loop(i,1,n)
		g = gcd(g,a[i]-a[i-1]);
	
	loop(i,q){
		scanf("%lld",&k);
		printf("%lld\n",gcd(a[0]+k,g));	
	}
	
	
	return 0;
}
