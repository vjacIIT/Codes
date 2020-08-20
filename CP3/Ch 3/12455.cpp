#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> dp;
int *a;

int find(int i, int sum){
	int n1, n2;
	if(sum<0)	return -1;
	if(dp[i][sum]!=-1)	return dp[i][sum];
	n1=find(i-1,sum);
	n2=find(i-1,sum-a[i-1]);
	if(n1==1 || n2==1)	dp[i][sum]=1;
	else	dp[i][sum]=0;
	return dp[i][sum];
}

int main(){
	int tc,sum,n,i,ans;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d%d",&sum,&n);
		a = new int[n];
		for(i=0; i<n; i++)	scanf("%d",a+i);
		dp = vector<vector<int>>(n+1,vector<int>(sum+1,-1));
		for(i=0; i<=n; i++)	dp[i][0]=1;			// sum=0 always true
		for(i=1; i<=sum; i++)	dp[0][i]=0;		// no bars left
		sort(a,a+n);
		ans=find(n,sum);
		ans==1 ? printf("YES\n"):printf("NO\n");
		delete []a;	for(i=0; i<=n; i++)	dp[i].clear();
		dp.clear();		
	}
	return 0;
}
