#include<stdio.h>
#include<stdlib.h>

int find_index(int *A, int n)
{
	int start=0, end=n-1, mid;
	while(end>start+1)
	{
		mid = (start+end)/2;
		if(A[mid]<=A[end])
			end = mid;
		else
			start = mid;
	}
	
	if(A[end]<A[start])
		return end;
	else
		return start;
}

int binary_search(int *A, int n, int value, int flag)
{
	int index = find_index(A, n);
	int start, end, mid;
	if(flag==0)
	{
		start=0; 
		end=index-1;
	}
	
	else
	{
		start = index; 
		end = n-1;
	}
	
	while(start<=end)
	{
		mid = (start+end)/2;
		if(A[mid]==value)
			return mid;
		else if(A[mid]>value)
			end = mid-1;
		else 
			start = mid+1;
	}
	
	return -1;
}


int main()
{
	int *arr, n, value, result;
	scanf("%d%d", &n, &value);
	
	arr = (int*)malloc(n*sizeof(int));
	for(int i=0; i<n; i++)
		scanf("%d", arr+i);
	
	
	result = binary_search(arr, n, value,0);
	if(result!=-1)
		printf("index is: %d\n", result);
	else
	{
		result = binary_search(arr, n, value,1);
		if(result!=-1)
			printf("index is: %d\n", result);
		else 
			printf("Number is not in the given array\n");
	}

	free(arr);
	return 0;
}
