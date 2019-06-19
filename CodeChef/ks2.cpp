#include<cstdio>
using namespace std;

int findSum(long long int n){
	int sum=0;
	while(n>0){
		sum+=n%10;
		n=n/10;
	}
	return sum;
}

int main(){
	long long int n;
	int tc, sum;
	scanf("%d",&tc);
	while(tc--){
		scanf("%lld",&n);
		sum = findSum(n);
		printf("%lld",n);
		if(sum%10==0)	printf("0\n");
		else	printf("%d\n",10-(sum%10));
	}
	return 0;
}
