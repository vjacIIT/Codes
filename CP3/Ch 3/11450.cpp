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
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<vb> vvb;
typedef vector<vi> vvi;
typedef vector<ii> vii;


vvi garments, dp;
vi sgar;
int money, ngar;
bool poss;

int maxMoney(int cmoney, int i){				// cmoney=money left, we are taking i'th garment
	if(cmoney<0)
		return INT_MIN;
	if(i==ngar)									// taken all garments
		return money-cmoney;
	if(dp[cmoney][i]!=-1)
		return dp[cmoney][i];
	
	int ans=-1;
	loop(j,sgar[i])
		ans=max(ans,maxMoney(cmoney-garments[i][j],i+1));
	
	return dp[cmoney][i]=ans;
}

// dp[cmoney][i] --> if you have cmoney at index i as starting money and have taken garments till i-1
// what is the maximum money you can spend

int main(){
	int tc, cmoney;
	scan(tc);
	while(tc--){
		scanf("%d%d",&money,&ngar);
		garments = vvi(ngar);
		dp = vvi(201,vi(ngar,-1));
		sgar = vi(ngar);
		loop(i,ngar){
			scan(sgar[i]);
			loop(j,sgar[i]){
				scan(cmoney);
				garments[i].pb(cmoney);
			}
			sort(garments[i].begin(),garments[i].end());
		}
		dp[money][0] = maxMoney(money,0);
		if(dp[money][0]<0)
			printf("no solution\n");
		else
			printf("%d\n",dp[money][0]);
	}
	return 0;
}

// THis is trying all possible solutions, hence TLE
