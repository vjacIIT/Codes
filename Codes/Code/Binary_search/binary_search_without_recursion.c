#include<stdio.h>
#include<stdlib.h>

int binary_search(int *A, int n, int value, int *flag)
{
	int strt=0, end=n-1;
	*flag=0;
	while(strt<=end)
	{
		if(A[strt]==value)
			return strt;
		else if(A[end]==value)
			return end;
		else if(A[(strt+end)/2]==value)
			return (strt+end)/2;
		else if(A[(strt+end)/2]>value) 
			end=((strt+end)/2)-1;
		else 
			strt=((strt+end)/2)+1;
	}
	
	printf("NO, elment is not there\n");
	*flag = 1;
	return 0;	
}

int main()
{
	int *arr, n, ind, value, *flag;
	
	printf("Enter the array size and value to be searched: ");
	scanf("%d%d", &n, &value);
	
	printf("Enter the array: ");
	arr = (int *)malloc(n*sizeof(int));
	for(int i=0; i<n; i++)
		scanf("%d", arr+i);
	
	ind = binary_search(arr, n, value, flag);
	if(*flag==0)
		printf("Index of input value is : %d\n", ind);
		
	return 0;	
}
