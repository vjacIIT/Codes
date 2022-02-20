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

vvi dp, nocoins;

int main(){
	int tc, tmoney, cntCoin, oldval, newval, moneyLeft;
	vi coins;
	scan(tc);
	loop(t,tc){
		scan(tmoney);
		scan(cntCoin);
		dp = vvi(cntCoin+1,vi(10001,INT_MAX/2));
		nocoins = vvi(cntCoin+1,vi(10001,INT_MAX/2));
		// dp[coin][money] = min amount required to be paid, with coin only and min money needed to be spent == money
		coins = vi(cntCoin+1);
		loop(i,cntCoin)
			scan(coins[i+1]);
		loop(i,cntCoin+1){
			dp[i][0] = 0;
			nocoins[i][0] = 0;
		}
		Loop(coin,1,cntCoin+1){
			Loop(money,1,10001){
				oldval = dp[coin-1][money];
				moneyLeft = money-coins[coin]>=0 ? money-coins[coin]:0;
				newval = dp[coin-1][moneyLeft]+coins[coin];
				if(newval<oldval){
					dp[coin][money] = newval;
					nocoins[coin][money] = nocoins[coin-1][moneyLeft]+1;
				}
				else if(newval==oldval && (nocoins[coin-1][moneyLeft]+1)<nocoins[coin-1][money]){
					dp[coin][money] = newval;
					nocoins[coin][money] = nocoins[coin-1][moneyLeft]+1;
				}
				else{
					dp[coin][money] = oldval;
					nocoins[coin][money] = nocoins[coin-1][money];
				}
			}
		}
		newval = INT_MAX;
		oldval = INT_MAX;
		Loop(money,tmoney,10001){
			if(dp[cntCoin][money]<oldval){
				oldval = dp[cntCoin][money];
				newval = nocoins[cntCoin][money];
			}
			else if(dp[cntCoin][money]==oldval && nocoins[cntCoin][money]<newval)
				newval = nocoins[cntCoin][money];
		}
		printf("%d %d\n",oldval,newval);
	}
	return 0;
}
