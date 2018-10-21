#include<stdio.h>
#include<stdlib.h>


long long int power(int a, int b)
{
		long long int no = 1;
		for(int i=1; i<=b; i++)
				no*=a;
		return no;
} 

int * binary(long int n)
{
		int *arr, i=0;
		arr = (int *)malloc(40*sizeof(int));
		for(i=0; i<40; i++)
				arr[i]=0;
		i=0;
		while(n!=1)
		{
				arr[i]=n%2;
				n=n/2;
				i++;
		}
		arr[i]=1;
		return arr;
}

long long int HCF(long long int a,long long int b)
{
		long int temp;
		if(b==0)
			return a;
		while(a%b!=0)
		{
				temp = b;
				b = a%b;
				a = temp;
		}

		return b;
} 

int main()
{
	long long int A, B, no1=1, no2=1, hcf, N, i, j, ar1[40], ar2[40];
	int tc, *index;
	scanf("%d", &tc);
	while(tc--)
	{
	
	scanf("%lld%lld%lld", &A, &B, &N);
	
	index = (int*)malloc(40*sizeof(int));
	index = binary(N);
	no1 = 1; no2=1; 
		if(A==B)
		{
				
				for(i=0; i<=39; i++)
					{		
							
						   if(index[i]==1)
						   {
						   		ar1[i]=A;
						   		for(j=2; j<=power(2,i);)
						   		{
											j*=2;
											ar1[i]*= ar1[i];
											ar1[i] = ar1[i]%1000000007;
									}
							}
							
							else
									ar1[i]=1;
							
					}
					
					
				for(i=0; i<=39; i++)
					{
							no1 *= ar1[i];
							no1 = no1%1000000007;
					}
				
				
				printf("%lld\n", (2*no1)%1000000007);
		}
		
		else if(A == B+1)
				printf("1\n");
				
		else
		{
					
					
				for(i=0; i<=39; i++)
				{
							if(index[i]==1)
						   {
						   		ar1[i]=A;	ar2[i]=B;
						   		for(j=2; j<=power(2,i);)
						   		{
											j*=2;
											ar1[i]*= ar1[i];
											ar1[i] = ar1[i]%(A-B);
											ar2[i]*= ar2[i];
											ar2[i] = ar2[i]%(A-B);
									}
							}
							
							else
							{
									ar1[i]=1; ar2[i]=1;
							}
				}
					
				no1=1; no2=1;
				for(i=0; i<=39; i++)
				{
						no1*=ar1[i];		no1 = no1%(A-B);
						no2*=ar2[i]; 		no2 = no2%(A-B);
				}
					 
					
				no2 = (no1+no2)%(A-B);
				no1 = A-B;
				hcf = HCF(no1,no2)%1000000007;
				printf("%lld\n",hcf); 
		}
		
	}
			
	return 0;
}
