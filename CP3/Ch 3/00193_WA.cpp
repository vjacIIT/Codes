#include<cstdio>
#include<vector>
#include<cstring>
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

int count(int n){
	int cnt=0;
	while(n){	cnt+=(n%2);	n/=2;	}
	return cnt;
}

int main(){
	vi prt, help;
	bool flg;
	int m, n, k, v1, v2, ans;
	scan(m);
	loop(cse,m){
		ans=-1;
		scanf("%d%d",&n,&k);
		gr = vvi(n);
		loop(i,k){
			scanf("%d%d",&v1,&v2);	v1--;	v2--;
			gr[v1].pb(v2);	gr[v2].pb(v1);
		}
		loop(i,1<<n){
			flg=true;
			loop(j,n){
				if(i&(1<<j)){				// if j'th bit is on, means black
					loop(k,(int)gr[j].size()){		// then all it's direct edges should be white
						v1 = gr[j][k];
						if(i&(1<<v1)){	flg=false;	break;	}
					}
					if(!flg)	break;
				}
			}
			if(flg && count(i)>ans){
				prt.clear();
				ans=count(i);
				v2 = i;
				while(v2){
					prt.pb(v2%2);	v2/=2;
				}				
			}
			else if(flg && count(i)==ans){
				help.clear();
				v2 = i;
				while(v2){
					help.pb(v2%2);	v2/=2;
				}
				if(help<prt)	prt=help;			// here I have compared vectors
			}
		}
		printf("%d\n",ans);
		loop(i,(int)prt.size()){
			if(prt[i]){
				printf("%d",i+1);
				ans--;
				if(ans)	printf(" ");
			}
		}
		newline;
		prt.clear();	gr.clear();
	}
	return 0;
}

// This solution seems to be wrong, although it finds correct no of vertices and also shows a valid solution (I hope so)
// Brute force solution, (n^2*2^n)
