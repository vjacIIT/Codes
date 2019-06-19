#include<iostream>
#include<climits>
using namespace std;

int main(){
	int n,bud,nh,nw,ppm,nbed,ans;
	while(scanf("%d%d%d%d",&n,&bud,&nh,&nw)!=EOF){
		ans = INT_MAX;
		for(int i=0; i<nh; i++){
			scanf("%d",&ppm);
			for(int j=0; j<nw; j++){
				scanf("%d",&nbed);
				if(nbed>=n && bud>=ppm*n && ans>ppm*n)	ans=ppm*n;
			}
		}
		if(ans!=INT_MAX)	printf("%d\n",ans);
		else	printf("stay home\n");
	}
	return 0;
}
