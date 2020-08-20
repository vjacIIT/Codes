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
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<string> vs;
typedef vector<vb> vvb;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int main(){
	vvb dp;
	vi wt, v;
	int asum, n, sum, id;
	while(scanf("%d%d",&asum,&n)!=EOF){
		wt = vi(n);		dp = vvb(n+1,vb(asum+1,false));
		loop(i,n+1)	dp[i][0]=true;
		loop(i,n)	scan(wt[i]);
		Loop(i,1,n+1){
			Loop(j,1,asum+1){
				if(wt[i-1]<=j)
					dp[i][j]=dp[i-1][j] || dp[i-1][j-wt[i-1]];
				else
					dp[i][j]=dp[i-1][j];
			}
		}
		sum=asum;		id=n;
		while(!dp[n][sum])	sum--;
		asum=sum;
		while(sum){
			if(dp[id-1][sum])	id--;
			else{	
				v.pb(wt[id-1]);	sum-=wt[id-1];
			}
		}
		id = v.size();
		loop(i,id)	printf("%d ",v[id-i-1]);
		printf("sum:%d\n",asum);
		v.clear();	wt.clear();
	}
	return 0;
}
