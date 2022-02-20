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

int main(){
	int tc, n;
	vi wt, ht, lis, lds;
	scan(tc);
	loop(t,tc){
		scan(n);
		wt = vi(n);
		ht = vi(n);
		lis = vi(n);
		lds = vi(n);
		loop(i,n)
			scan(ht[i]);
		loop(i,n){
			scan(wt[i]);
			lis[i]=wt[i];
			lds[i]=wt[i];
		}
		Loop(i,1,n){
			Loop(j,0,i){
				if(ht[i]>ht[j] && lis[i]<=lis[j]+wt[i])
					lis[i]=lis[j]+wt[i];
				if(ht[i]<ht[j] && lds[i]<=lds[j]+wt[i])
					lds[i]=lds[j]+wt[i];
			}
		}
		int inc=0, dec=0;
		loop(i,n){
			inc = max(inc, lis[i]);
			dec = max(dec, lds[i]);
		}
		if(inc>=dec)
			printf("Case %d. Increasing (%d). Decreasing (%d).\n", t+1,inc,dec);
		else
			printf("Case %d. Decreasing (%d). Increasing (%d).\n", t+1,dec,inc);
	}
	return 0;
}
