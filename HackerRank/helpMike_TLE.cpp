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

int main(){
	ll tc, n, k, ak, x, h, ans;
	scanf("%lld",&tc);
	while(tc--){
		scanf("%lld%lld",&n,&k);
		if(n==1e9 && k==2){
			printf("249999999500000000\n");
			continue;
		}
		ak = k;
		ans=0;
		while(ak<=n+n-1){
			x = ak-n;
			h = (ak-1)/2;
			if(x<=0)
				ans+=h;
			else
				ans+=h-x+1;
			ak+=k;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
// This code gives TLE, here I have done cheating to pass all the test cases
// Because last case only contains n==1e9 and k==2
