#include<cstdio>
#include<climits>
#include<cmath>
#include<algorithm>
using namespace std;

int main(){
	int n, no;
	scanf("%d",&n);
	while(n){
		int csum=0, ans=INT_MIN;
		for(int i=0; i<n; i++){
			scanf("%d",&no);
			csum+=no;
			ans=max(ans,csum);
			if(csum<0)
				csum=0;
		}
		if(ans>0)
			printf("The maximum winning streak is %d.\n",ans);
		else
			printf("Losing streak.\n");
		scanf("%d",&n);
	}
	return 0;
}
