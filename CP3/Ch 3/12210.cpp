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

int main(){
	vi boys, girls;
	int nb, ng, tc=0;
	while(scanf("%d%d",&nb,&ng)){
		tc++;
		if(!nb && !ng)
			break;
		boys = vi(nb);
		girls = vi(ng);
		loop(i,nb)
			scan(boys[i]);
		loop(i,ng)
			scan(girls[i]);
		if(ng>=nb){
			printf("Case %d: 0\n",tc);
			continue;
		}
		sort(boys.begin(),boys.end());
		//sort(girls.begin(),girls.end());
		printf("Case %d: %d %d\n",tc,nb-ng,boys[0]);
	}
	return 0;
}
