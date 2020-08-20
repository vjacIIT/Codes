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
	int n, cnt, cmax;
	vi wt;
	vvi ans;
	while(scan(n)!=EOF){
		if(n==0)
			break;
		wt = vi(n);
		cnt=1;
		cmax=1;
		loop(i,n)
			scan(wt[i]);
		sort(wt.begin(),wt.end());
		wt.pb(0);
		loop(i,n){
			if(wt[i]==wt[i+1])
				cnt++;
			else{
				cmax = max(cmax,cnt);
				cnt=1;
			}
		}
		print(cmax);
		newline;
		ans = vvi(cmax);
		loop(i,n){
			cnt=(i%cmax);
			ans[cnt].pb(wt[i]);
		}
		loop(i,cmax){
			loop(j,ans[i].size()){
				if(j)
					printf(" ");
				print(ans[i][j]);
			}
			newline;
		}
		newline;
	}
	return 0;
}
