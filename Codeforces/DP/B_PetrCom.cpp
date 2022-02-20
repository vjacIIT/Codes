#include<cstdio>
#include<vector>
using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vb> vvb;

vi a;
vvb dp;

int main(){
	int n;
	scanf("%d",&n);		a = vi(n);
	for(int i=0; i<n; i++)	scanf("%d",&a[i]);
	dp = vvb(n+1,vb(360,false));	dp[0][0]=true;
	for(int i=1; i<=n; i++){
		for(int j=0; j<360; j++)	
			dp[i][j]=dp[i-1][(j-a[i-1]+360)%360] | dp[i-1][(j+a[i-1])%360];
	}
	if(dp[n][0])	printf("YES\n");
	else	printf("NO\n");
}

// dp[i][j] = By using all the indices from 0 to i, can we reach 0 or not
// Either we can reach from j+a[i] or from j-a[i]
