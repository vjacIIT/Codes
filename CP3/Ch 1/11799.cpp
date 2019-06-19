#include<iostream>
using namespace std;

int main(){
	int t,n,spd,max;
	scanf("%d",&t);
	for(int i=1; i<=t; i++){
		max=-1;
		scanf("%d",&n);
		while(n--){
			scanf("%d",&spd);
			if(spd>max)	max=spd;
		}
		printf("Case %d: %d\n",i,max);
	}
	return 0;
}
