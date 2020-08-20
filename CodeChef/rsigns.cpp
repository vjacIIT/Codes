#include<cstdio>
using namespace std;

const int no = 1000000007;

long int power(int n){
	long int k;
	if(n==0)	return 1;
	if(n==1)	return 2;
	if(n%2==0){
		k = power(n/2);
		k = (k*k)%no;
		return k;
	}
	else	return 2*power(n-1);
}

int main(){
	int tc;
	long int k;
	scanf("%d",&tc);
	while(tc--){
		scanf("%ld",&k);
		k = (10*power(k-1))%no;
		printf("%ld\n",k);
	}
	return 0;
}
