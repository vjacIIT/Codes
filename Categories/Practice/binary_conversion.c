#include<stdio.h>
#include<stdlib.h>

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

int main()
{
	int *arr;
	long int n;
	scanf("%ld", &n);
	arr = (int*)malloc(40*sizeof(int));
	arr = binary(n);
	for(int i=39; i>=0; i--)
		printf("%d", arr[i]);
	printf("\n");
	return 0;
}
