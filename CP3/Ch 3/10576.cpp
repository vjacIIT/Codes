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
#define MOD 1000000007

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<bool> vb;
typedef vector<vb>	vvb;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vll> vvll;

ll s, d;

ll compare(int mask){
	ll sum=0, cons=0, v;		// cons stores the sum of five consecutive indexes sum
	loop(i,12){
		v = ((1<<i)&mask) ? s:-d;
		sum+=v;
		if(i<4)	cons+=v;	
		else{
			cons+=v;								// adding the new index value
			if(cons>=0)	return -1;
			cons-=((1<<(i-4))&mask) ? s:-d;			// removing the last index value 
		}
	}
	return sum;
}

int solve(){
	ll ans=-MOD;
	loop(i,(1<<12))	ans=max(ans,compare(i));
	return ans;
}

int main(){
	ll ans;
	while(scanf("%lld%lld",&s,&d)!=EOF){
		ans = solve();
		if(ans<0)	printf("Deficit\n");
		else	printf("%lld\n",ans);
	}
	return 0;
}
