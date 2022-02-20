#include<cstdio>
#include<climits>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

int totalMiles;
int wind[10][1001];
int dp[10][1001];

int fuelReq(int posx, int posy){
	if(posx>9 || posx<0)
		return INT_MAX/2;
	if(posy==totalMiles/100){
		// has to come to level 0 (ground) at the end
		if(posx==0)
			return dp[posx][posy]=0;
		else
			return dp[posx][posy]=INT_MAX/2;
	}
	if(dp[posx][posy]!=-1)
		return dp[posx][posy];
	int up = fuelReq(posx+1,posy+1)+60-wind[posx][posy];
	int down = fuelReq(posx-1, posy+1)+20-wind[posx][posy];
	int hold = fuelReq(posx, posy+1)+30-wind[posx][posy];
	return dp[posx][posy] = min(up, min(down, hold));
}

int main(){
	int tc;
	scanf("%d",&tc);
	for(int t=0; t<tc; t++){
		scanf("%d",&totalMiles);
		for(int i=9; i>=0; i--){
			for(int j=0; j<totalMiles/100; j++){
				scanf("%d",&wind[i][j]);
			}
		}
		memset(dp, -1, sizeof(dp));
		printf("%d\n\n",fuelReq(0,0));
	}
	return 0;
}