#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

#define loop(i,n)	for(int i=0; i<n; i++)
#define Loop(i,a,n)	for(int i=a; i<n; i++)
#define scan(a)		scanf("%d",&a)
#define print(a)	printf("%d",a)
#define newline		printf("\n")
#define mp	make_pair
#define pb	push_back

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int main(){
	vi a;
	vvi dp;
	int tc, n;
	scan(tc);
	loop(i,tc){
		scan(n);
		dp = vvi(n,vi(100,0));		a=vi(n);
		loop(i,n)	scan(a[i]);
		Loop(i,1,n){
			dp[i][0]=max(dp[i-1][0],dp[i-1][1]+abs(a[i-1]-1));
			dp[i][1]=max(dp[i-1][0]+abs(a[i]-1),dp[i-1][1]+abs(a[i]-a[i-1]));
		}
		printf("%d\n",max(dp[n-1][0],dp[n-1][1]));
	}
	return 0;
}
