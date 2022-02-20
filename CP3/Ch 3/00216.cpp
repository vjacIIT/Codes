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

struct vertex{
	int x, y;
	vertex(int a, int b){
		x = a;
		y = b;
	}
};

double dist(vertex a, vertex b){
	double x = a.x-b.x;
	double y = a.y-b.y;
	return 16.0+sqrt((x*x)+(y*y));
}

int n;
vector<vertex> vertices;
pair<int, double> dp[8][258];

pair<int,double> minDistance(int i, int mask){
	double d;
	if(mask==((1<<n)-1))
		return dp[i][mask]=make_pair(i,0.0);
	pair<int, double> ans = make_pair(-1, 300000.0);
	loop(j,n){
		if((mask&(1<<j))==0){
			d = minDistance(j,mask|(1<<j)).second+dist(vertices[i],vertices[j]);
			if(ans.second>d){
				ans.second=d;
				ans.first=j;
			}
		}
	}
	return dp[i][mask]=ans;
}

int main(){
	int h, cnt=0, nh, mask;
	double d, tmp;
	while(scanf("%d",&n)!=EOF){
		if(n==0)
			break;
		vertices = vector<vertex>(n,vertex(0,0));
		loop(i,n)
			scanf("%d%d",&vertices[i].x,&vertices[i].y);
		for(int i = 0; i < 8; i++)
            for(int j = 0; j < 258; j++)
                dp[i][j] = make_pair(-1, -1.0);
		d = 300000.0;
		loop(i,n){			
			tmp = minDistance(i,1<<i).second;
			if(d>tmp){
				d = tmp;
				h=i;
			}
		}
		// dp[i][mask] == min dist req to reach i from some initial vertex using vertices which are unset in mask
		mask=1<<h;
		nh = dp[h][mask].first;
		cnt++;
		printf("**********************************************************\nNetwork #%d\n",cnt);
		while(h!=nh){
			printf("Cable requirement to connect (%d,%d) to (%d,%d) is ",vertices[h].x,vertices[h].y,vertices[nh].x, vertices[nh].y);
			printf("%.2f feet.\n",dist(vertices[h], vertices[nh]));
			h = nh;
			mask = mask|(1<<h);
			nh = dp[h][mask].first;
		}
		printf("Number of feet of cable required is %.2f.\n",d);
	}
	return 0;
}

// As we don't have to make full cycle here, calling minDistance once might not give optium solution
// see that we have to do call minDistance n-1 times starting from different vertices
// Overall complexity is O(n^3 * 2^n)