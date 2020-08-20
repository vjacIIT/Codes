#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
#include<climits>
#include<iostream>
using namespace std;

#define loop(i,n)	for(int i=0; i<n; i++)
#define Loop(i,a,n)	for(int i=a; i<n; i++)
#define newline		printf("\n")
#define scan(n)		scanf("%d",&n)
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
	vi morning;
	vi noon;
	int n, d, r, no, ans;
	while(scanf("%d%d%d",&n,&d,&r)!=EOF){
		if(n==0 && d==0 && r==0)
			break;
		morning = vi(n);
		ans=0;
		noon = vi(n);
		loop(i,n)
			scan(morning[i]);
		loop(i,n)
			scan(noon[i]);
		sort(morning.begin(),morning.end());
		sort(noon.begin(),noon.end(),greater<>());
		loop(i,n){
			no = morning[i]+noon[i]-d;
			if(no>0)
				ans+=no*r;
		}
		printf("%d\n",ans);
	}
	return 0;
}
