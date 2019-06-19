#include<stdio.h>
#include<stdlib.h>

int isPrime(long int n)
{
	if(n==1)
		return -1;
	for(int i=2; i*i<=n; i++)
	{
		if(n%i==0)
			return -1;
	}
	return 1;
}

int main()
{
	int tc;
	long int n;
	scanf("%d", &tc);
	while(tc--)
	{
		scanf("%ld", &n);
		n=isPrime(n);
		if(n==1)
			printf("Prime\n");
		else
			printf("Not prime\n");
	}

}
