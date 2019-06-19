#include<stdio.h>
#include<stdlib.h>

int *binary(int n)
{
	int *ar;
	int i=0;
	ar = (int*)malloc(20*sizeof(int));
	
	for(int i=0; i<20; i++)
		ar[i]=-1;
		
	while(n!=0)
	{
		ar[i]=n%2;
		n=n/2;
		i++;
	}
	return ar;
}

int main()
{
	int *ar;
	int arf[20], max=0, k=0, n;
	scanf("%d", &n);
	ar = binary(n);
	
	n=0;
	for(int i=0; i<20; i++)
	{
		if(ar[i]==-1)
			break;
		else
			n++;
	}
	
	//for(int i=0; i<n; i++)
		//printf("%d\n", ar[i]);
	
	for(int i=0; i<n; i++)
	{
		if(ar[i]==1)
			max++;
		else
		{
			arf[k]=max;
			k++; 
			max=0;
		}
	}
	arf[k]=max;
	max=arf[0];
	for(int i=0; i<=k; i++)
	{
		if(arf[i]>max)
			max=arf[i];
	}	
	printf("%d\n", max);
	return 0;
}
