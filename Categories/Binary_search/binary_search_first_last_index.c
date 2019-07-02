#include<stdio.h>
#include<stdlib.h>

int binary_search_first_index(int *A, int n, int value)
{
	int start = 0, end=n-1, result=-1, mid;
	while(start<=end)
	{	
		mid = (start+end)/2;
		if(A[mid]==value)
		{
			result = mid;
			end = mid-1;
		}
		else if(A[mid]<value)
			start = mid+1;
		else 
			end = mid-1;
	}
	
	return result;
}

int binary_search_last_index(int *A, int n, int value)
{
	int start=0, end=n-1, result=-1, mid;
	while(start<=end)
	{
		mid = (start+end)/2;
		if(A[mid]==value)
		{
			result = mid;
			start= mid+1;
		}
		else if(A[mid]<value)
			start= mid+1;
		else 
			end = mid-1;
	}
	
	return result;
}


int main()
{
	int *arr, n, value, ind;
	scanf("%d%d", &n, &value);

	arr = (int *)malloc(n*sizeof(int));
	for(int i=0; i<n; i++)
		scanf("%d", arr+i);
		
	ind = binary_search_first_index(arr, n, value);
	if(ind==-1)
		printf("Sorry given value is not in the arry\n");
	else
		printf("min index is: %d\n", ind);
	
	
	ind = binary_search_last_index(arr, n, value);
	if(ind!=-1)	
		printf("last index is: %d\n", ind);
	
	return 0;	
}
