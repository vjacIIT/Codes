#include<stdio.h>
#include<stdlib.h>

int binary_search(int *A, int start, int end, int value)
{
	if(A[start]>value)
		return -1;
	else if (A[end]<value)
		return -1;
	else if(start-end>=0)
		return -1;
	else
	{
		if(A[start]==value)
			return start;
		else if (A[end]==value)
			return end;
		else if(A[(start+end)/2]==value)
			return (start+end)/2;
		else if(A[(start+end)/2]>value)
			binary_search(A, start, ((start+end)/2)-1, value);
		else 
			binary_search(A, ((start+end)/2)+1, end, value);			
	}
}

int main()
{
	int *arr, n, value, ind;
	scanf("%d%d", &n, &value);
	
	arr = (int *)malloc(n*sizeof(int));
	for(int i=0; i<n; i++)
		scanf("%d", arr+i);
	ind = binary_search(arr, 0, n-1, value);
	
	if(ind==-1)
		printf("Given no is not in the array\n");
	else
		printf("Index of no in the array is :%d\n", ind);
		
	return 0;
}
