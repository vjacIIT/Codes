#include<cstdio>
#include<vector>
using namespace std;

int main(){
	vector<int> v, a, l, r;
	int n, k, sum, ans=0;
	scanf("%d%d",&n,&k);
	v = vector<int>(n+1,0);
	a = vector<int>(n+1,0);
	l = vector<int>(n+1,0);
	r = vector<int>(n+2,0);
	for(int i=1; i<=n; i++)	scanf("%d",&v[i]);
	for(int i=1; i<=n; i++)	scanf("%d",&a[i]);
	for(int i=1; i<=n; i++)
		if(a[i])	l[i]=l[i-1]+v[i];
		else	l[i]=l[i-1];
	for(int i=n; i>0; i--)
		if(a[i])	r[i]=r[i+1]+v[i];
		else	r[i]=r[i+1];
	
	sum=0;
	for(int i=1; i<=k; i++)	sum+=v[i];
	ans=max(ans,l[0]+sum+r[k+1]);
	for(int t=1; t<=n-k; t++){
		sum-=v[t];	sum+=v[t+k];
		ans=max(ans,l[t]+sum+r[t+k+1]);
	}
	printf("%d\n",ans);
	return 0;
}
