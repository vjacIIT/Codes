#include<iostream>
using namespace std;

int main(){
	int stk[1001],n, ar[1001], cnt, i, tp=-1;
	while(scanf("%d",&n)!=EOF){
		if(n==0)	break;
		while(true){
			cnt=0;	i=0;	tp=-1;
			for(int k=0; k<n; k++){	scanf("%d",ar+k);	if(ar[0]==0)	break;	}
			if(ar[0]==0)	break;
			while(cnt!=n+1){
				if(tp==-1 || stk[tp]!=ar[i]){
					cnt++;	tp++;	stk[tp]=cnt;
				}
				else{	tp--;	i++;	}
			}
			if(tp!=0)	printf("No\n");
			else	printf("Yes\n");
		}
		printf("\n");
	}
}
