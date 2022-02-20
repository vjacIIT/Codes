#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#include<set>
#include<climits>
#include<iostream>
#include<cmath>
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

vector<vvi> dp;

int main(){
	int n, ncoins, modsum, sum, ans;
	vector<ii> coinval;
	scan(n);
	loop(t,n){
		scanf("%d%d",&ncoins,&modsum);
		dp = vector<vvi>(ncoins+1,vvi(modsum+1,vi(modsum+1,INT_MAX/2)));
		loop(i,ncoins+1)
			dp[i][0][0] = 0;
		coinval	= vector<ii>(ncoins+1);
		loop(coin,ncoins)
			scanf("%d%d",&coinval[coin+1].first, &coinval[coin+1].second);
		
		// dp[coin][x][y] == min no of coins required to make x*x + y*y with coin only
		Loop(coin,1,ncoins+1){
			loop(x,modsum+1){
				loop(y,modsum+1){
					sum = (x*x) + (y*y);
					if(sum>modsum*modsum)
						break;
					if(x-coinval[coin].first>=0 && y-coinval[coin].second>=0)
						dp[coin][x][y] = min(dp[coin-1][x][y], dp[coin][x-coinval[coin].first][y-coinval[coin].second]+1);
					else
						dp[coin][x][y] = dp[coin-1][x][y];
				}
			}
		}
		ans = INT_MAX/2;
		loop(x,modsum+1)
			loop(y,modsum+1)
				if((x*x)+(y*y)==(modsum*modsum))
					ans=min(ans,dp[ncoins][x][y]);
		if(ans==INT_MAX/2)
			printf("not possible\n");
		else
			printf("%d\n",ans);
	}

	return 0;
}
