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
typedef vector<vll> vvll;

int main(){
	ll ans;
	vi a;
	int t, n, xr;
	scan(t);
	loop(tc,t){
		ans=0;
		scan(n);	a=vi(n);
		loop(i,n)	scan(a[i]);
		loop(i,n){
			xr=a[i];
			Loop(j,i+1,n){
				xr=xr^a[j];
				if(xr==0)	ans+=(ll)(j-i);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
