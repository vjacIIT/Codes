#include<cstdio>
#include<cmath>
using namespace std;

int nodigits(int n){
	int d=0;
	while(n>0){	d++;	n/=10;	}
	return d;
}

int gcd(int sm, int big){
	if(sm==0)	return big;
	return gcd(big%sm,sm);
}

int main(){
	int neg, uavg, avg, factor, cno=1, d1, d2, d3, r, n;
	while(scanf("%d",&n)){
		if(n==0)	break;
		printf("Case %d:\n",cno);		cno++;
		avg=0;
		for(int i=0; i<n; i++){	scanf("%d",&neg);	avg+=neg; }
		uavg = abs(avg);	neg=avg<0 ? 2:0;
		if(uavg%n==0){
			if(neg!=0)	printf("- ");
			printf("%d\n",uavg/n);
		}
		else if(uavg<n){
			factor = gcd(uavg,n);	uavg = uavg/factor;		n = n/factor;
			d1 = nodigits(uavg);	d2 = nodigits(n);	
			for(int i=0; i<d2-d1+neg; i++)	printf(" ");
			printf("%d\n",uavg);	if(neg!=0)	printf("- ");
			for(int i=0; i<d2; i++)	printf("-");	printf("\n");
			for(int i=0; i<neg; i++)	printf(" ");	printf("%d\n",n);
		}
		else{
			factor = gcd(uavg,n);	uavg = uavg/factor;		n = n/factor;
			factor = uavg/n;	r = uavg%n;
			d1 = nodigits(r);	d2 = nodigits(factor);	d3=nodigits(n);
			for(int i=0; i<d3+d2+neg-d1; i++)	printf(" ");
			printf("%d\n",r);	if(neg!=0)	printf("- ");
			printf("%d",factor);	for(int i=0; i<d3; i++)	printf("-");
			printf("\n");	for(int i=0; i<d2+neg; i++)	printf(" ");
			printf("%d\n",n);
		}
	}
	return 0;
}
