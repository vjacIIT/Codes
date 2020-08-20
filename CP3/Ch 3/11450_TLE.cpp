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


vvi garments;
vi sgar;
int money, ngar, cmoney, mmoney;
bool poss;

void maxMoney(int i){
	if(cmoney>money)
		return;
	if(i==ngar){
		poss=true;
		mmoney = max(mmoney,cmoney);
		return;
	}
	loop(j,sgar[i]){
		cmoney+=garments[i][j];
		maxMoney(i+1);
		cmoney-=garments[i][j];
	}
	return;
}

int main(){
	int tc;
	scan(tc);
	while(tc--){
		scanf("%d%d",&money,&ngar);
		garments = vvi(ngar);
		sgar = vi(ngar);
		loop(i,ngar){
			scan(sgar[i]);
			loop(j,sgar[i]){
				scan(cmoney);
				garments[i].pb(cmoney);
			}
			sort(garments[i].begin(),garments[i].end());
		}
		poss = false;
		cmoney = 0;
		mmoney = -1;
		maxMoney(0);
		if(poss)
			printf("%d\n",mmoney);
		else
			printf("no solution\n");	
	}
	return 0;
}

// THis is trying all possible solutions, hence TLE
// See the overlapping intervals
// cmoney is a state of dp here, similar to i (index of garment we need to take)
