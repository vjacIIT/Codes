#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <set>
#include <climits>
#include <iostream>
#include <cmath>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++)
#define Loop(i, a, n) for (int i = a; i < n; i++)
#define newline printf("\n");
#define scan(n) scanf("%d", &n)
#define mp make_pair
#define pb push_back
#define MOD 1000000007

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int N, x, T, K, ibudget;
double budget;
vi price;
vector<double> favour;
vector<vector<vector<double>>> dp;

int main(){
	int fval;
	while(scanf("%d%d%d%d",&N,&x,&T,&K)!=EOF){
		if(N==0 && x==0 && T==0 && K==0)
			return 0;
		N++;
		price = vi(2*K,0);
		favour = vector<double>(2*K,0.0);
		loop(i,K){
			scan(price[i]);
			price[i+K] = price[i];
			loop(f,N){
				scanf("%d",&fval);
				favour[i]+=fval;
			}
			favour[i]/=N;
			favour[i+K]=favour[i];
		}
		budget = ((N*x*10.0)/11) - (N*T);
		if(budget<=0.0){
			printf("0.00\n");
			continue;
		}
		ibudget = budget;
		// dp[dish][dishesTaken][bud] = favour value with dish dishes, dishesTaken and bud as total budget 
		dp = vector<vector<vector<double>>>(2*K+1,vector<vector<double>>(2*N+1,vector<double>(ibudget+1,0.0)));
		Loop(dish,1,2*K+1){
			Loop(dishesTaken, 1, 2*N+1){
				Loop(bud,1,ibudget+1){
					dp[dish][dishesTaken][bud] = dp[dish-1][dishesTaken][bud];
					if(price[dish-1]<=bud)
						if(dp[dish][dishesTaken][bud] < dp[dish-1][dishesTaken-1][bud-price[dish-1]]+favour[dish-1]){
							dp[dish][dishesTaken][bud] = dp[dish-1][dishesTaken-1][bud-price[dish-1]]+favour[dish-1];
					}
				}
			}
		}
		double ans=0.0;
		loop(i,2*N+1)
			ans=max(ans,dp[2*K][i][ibudget]);
		printf("%.2lf\n",ans);
	}
	return 0;
}
