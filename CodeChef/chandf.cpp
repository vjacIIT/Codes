// Given X, Y, L, R. Find Z in range [L,R], such that (X&Z)*(Y&Z) is max with min Z possible
// X,Y,L,R <= 10^12
// optimal answer = X|Y, but it need not be in range [L,R]
// Strategy of coming from Most Significant bit
//	: putting 1 if by putting Z comes in range [L,R] will not work
//	X = 1110000				= 7 
//  Y = 0011000				= 12
// with l=0, r=8, above strategy will make Z=0001000 	= 8, which is not optimal
// Because X&Z = 0 happens, which causes full expression to be 0

// Hence we are trying all possible values of Z in range [L,R] with some greedy strategy

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

vi l, r;

void binary(ll temp, char c){
	int cnt=0;
	while(temp>0){
		if(c=='L')
			l[cnt]=temp%2;
		else
			r[cnt]=temp%2;
		
		temp/=2;
		cnt++;
	}
	return;
}

int main(){
	bool check;
	vll z;
	int tc;
	ll X, Y, L, R, temp, Z, mmax, b1, b2, b3;
	scan(tc);
	while(tc--){
		scanf("%lld%lld%lld%lld",&X,&Y,&L,&R);
		if(X==0 || Y==0 || L==R){
			printf("%lld\n",L);
			continue;
		}
		l = vi(63,0);
		r = vi(63,0);
		binary(L,'L');
		binary(R,'R');
		Z=0;
		check = true;
		z.pb(L);
		z.pb(R);
		for(int b=62; b>=0; b--){
			// Initial bits of l and r which are same has to be same, otherwise out of bounds
			if(l[b]==r[b] && check){
				if(l[b])
					Z = Z|(1LL<<b);
				continue;
			}
			check = false;
			if(r[b]){									// if r[b]=1 && l[b]=0					
				temp = (1LL<<b);
				// either Z[b]=0
				// all except b'th bit in Z =1, Z[b]=0
				// it ensures that the temp is in range [L,R]
				z.pb(Z+temp-1);									// stores all possible Z
				Z = Z|(1LL<<b);
				// or if Z[b]=1, then continue for some other possible Z
			}
			// if r[b]=0 && l[b]=1, then we have to put Z[b]=0
		}
		sort(z.begin(),z.end());
		mmax = -1;
		
		// Now we have mmaximum value of (X&Z)*(Y&Z) with Z in range [L,R]
		loop(i,z.size()){
			temp = (X&z[i])*(Y&z[i]);
			if(temp>mmax){
				mmax = temp;
				Z = z[i];
			}
		}
		// For minimizing Z, we need to put Z[b]=0, where X[b]=0 && Y[b]=0
		// Because b'th bit will not contribute in multiplication
		for(int b=62; b>=0; b--){
			b3 = (Z>>b)&1;
			if(b3==0)
				continue;
			b1 = (X>>b)&1;
			b2 = (Y>>b)&1;
			if(b1==0 && b2==0 && Z-(1LL<<b)>=L)
				Z = Z - (1LL<<b);						// Z[b]=0
		}
		printf("%lld\n",Z);
		z.clear();
	}
	return 0;
}
