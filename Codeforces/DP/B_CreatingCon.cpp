#include<cstdio>
#include<vector>
#include<climits>
using namespace std;

vector<int> a;

int main(){
	int n, idx, ans=0, p;
	scanf("%d",&n);
	a = vector<int>(n+1,INT_MAX);
	for(int i=0; i<n; i++)	scanf("%d",&a[i]);
	idx = 0;	p=0;
	while(idx<n){
		if(2*a[idx]<a[idx+1]){	
			ans=max(ans,idx-p+1);	
			p=idx+1;
		}
		idx++;
	}
	printf("%d\n",ans);
	return 0;
}
