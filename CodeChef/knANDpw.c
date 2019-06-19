#include<stdio.h>
#include<stdlib.h>

int main()
{
	int tc;
	long long int N, M, X, Y;
	scanf("%d", &tc);
	while(tc--)
	{
		scanf("%lld%lld%lld%lld", &N, &M, &X, &Y);
		N=(N-1);
		M=(M-1);
		if(X==1)
		{
			if(M%Y==0)
				printf("Chefirnemo\n");
			else if(M%Y==1 && N!=0)
				printf("Chefirnemo\n");
			else 
				printf("Pofik\n");
		}
		else if(Y==1)
		{
			if(N%X==0)
				printf("Chefirnemo\n");
			else if(N%X==1 && M!=0)
				printf("Chefirnemo\n");
			else 
				printf("Pofik\n");
		}
		else
		{	
			N=N%X;
			M=M%Y;
			if(N==0 && M==0)
				printf("Chefirnemo\n");
			else if(N==1 && M==1)
				printf("Chefirnemo\n");
			else
				printf("Pofik\n");
		}
	}
	return 0;
}
