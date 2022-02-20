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

char A[100005], B[100005];

ll power(ll x, ll y){
	if(y==0)
		return 1;
	
	if(y%2)
		return (x*power(x,y-1))%Mod;
	else{
		ll h = power(x,y/2);
		return (h*h)%Mod;
	}
}

int main(){
	int tc;
	ll ans, x, y;
	scan(tc);
	while(tc--){
		scanf("%s %s",A,B);
		
		x = 0;
		// For finding a mod p
		loop(i,strlen(A)){				// x = (x*10 + a[i]) % p
			x*=10;
			x+=A[i]-'0';
			x%=Mod;
		}
		
		y = 0;
		loop(i,strlen(B)){				
			y*=10;
			y+=B[i]-'0';
			y%=(Mod-1);
		}
		printf("%lld\n",power(x,y));		
	}
	return 0;
}

// a^b mod p = (a mod p)^(b mod p-1)
// Here p has to be prime
