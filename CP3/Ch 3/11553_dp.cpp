#include<cstdio>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

#define loop(i,n)	for(int i=0; i<n; i++)
#define Loop(i,a,n)	for(int i=a; i<n; i++)
#define mp	make_pair
#define pb	push_back

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;

vvi m, dp;
int n;

int rec(int bit1, int bit2){
	int tmp, ans=INT_MIN;
	if(dp[bit1][bit2]!=INT_MIN)	return dp[bit1][bit2];
	if(bit1==(1<<n)-1)	return dp[bit1][bit2]=0;		// all row reached
	loop(i,n){
		if(!(bit1&(1<<i))){									// row not reached
			tmp=INT_MAX;
			loop(j,n){
				if(!(bit2&(1<<j))){
					tmp=min(tmp,m[i][j]+rec(bit1|(1<<i), bit2|(1<<j)));			// bob is trying to minimize as row is choosen
				}
			}
			ans=max(ans,tmp);					// alice is trying to maximize from all the tmp answers
		}
	}
	return dp[bit1][bit2]=ans;
}

int main(){
	int tc, ans;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		m = vvi(n,vi(n));	dp=vvi(1024,vi(1024,INT_MIN));			// 2^10
		loop(i,n)
			loop(j,n) scanf("%d",&m[i][j]);
		dp[0][0]=rec(0,0);
		printf("%d\n",dp[0][0]);
	}
	return 0;
}

// This dp solution is taken from morris@github
