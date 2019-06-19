#include<iostream>
using namespace std;

int gcd(int a, int b){
	if(b%a==0)	return a;
	else	return gcd(b%a,a);
}

int main(){
	int tc,n,a,b,d;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		scanf("%d",&a);
		printf("%d ",a);
		for(int i=1; i<n; i++){
			scanf("%d",&b);
			d = gcd(a,b);
			d = (a*b)/d;
			printf("%d ",d);
			a=b;
		}
		printf("%d\n",b);
	}
	return 0;
}
