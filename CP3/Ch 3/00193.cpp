#include<cstdio>
#include<vector>
#include<cstring>
#include<bitset>
#include<algorithm>
#include<set>
#include<climits>
#include<iostream>
using namespace std;

#define loop(i,n)	for(int i=0; i<n; i++)
#define Loop(i,a,n)	for(int i=a; i<n; i++)
#define newline		printf("\n");
#define scan(n)		scanf("%d",&n)
#define mp	make_pair
#define pb	push_back
#define MOD 1000000007
#define Black 1
#define White 0


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

vvi gr;
bitset<100> colored;
vi color, ansls;
int n, ans;

void solve(int u){
	int cnt=0, v;
	if(u==n){
		loop(i,n){
			if(color[i]==Black)	cnt++;
		}
		if(cnt>ans){
			ans=cnt;
			ansls.clear();
			loop(i,n){
				if(color[i]==Black)	ansls.pb(i);
			}
		}
		return;
	}
	bool canBlack = true;
	for(int i=0; i<(int)gr[u].size(); i++){
		v = gr[u][i];
		if(colored[v] && color[v]==Black){
			canBlack = false;
			break;
		}
	}
	colored.set(u);
	if(canBlack){
		color[u]=Black;
		solve(u+1);
	}
	color[u]=White;
	solve(u+1);
	colored.reset(u);
	return;
}

int main(){
	int m, k, v1, v2;
	scan(m);
	while(m--){
		colored.reset();
		ans=0;
		scan(n);	scan(k);
		gr = vvi(n);	color = vi(n,0);
		loop(i,k){
			scan(v1);	scan(v2);	v1--;	v2--;
			gr[v1].pb(v2);	gr[v2].pb(v1);
		}
		solve(0);
		printf("%d\n",ans);
		loop(i,(int)ansls.size()){
			if(i)	printf(" ");
			printf("%d",ansls[i]+1);
		}
		newline;
		loop(i,n)	gr[i].clear();	gr.clear();	color.clear();
	}
	return 0;
}

// Credits goes to ackora, copied from there
// Used kind of same concept before but didn't work
