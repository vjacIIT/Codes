#include<iostream>
using namespace std;

bool flg;
long long int n, sum, prd;
int ndigits;

void function(long long int  cn){
	ndigits=0;
	flg=false;
	sum=0;
	prd=1;
	while(cn!=0){
		ndigits++;
		if(cn%10==0)	flg=true;
		sum+=cn%10;
		prd*=cn%10;
		cn=cn/10;
	}
	return;
}

int main(){
	long long int cn;
	scanf("%lld",&n);
	cn = n;
	while(true){
		function(n);
		if(!flg && sum>=prd)	break;
		n+=cn;
	}
	printf("%d\n",ndigits);
	return 0;
}
