#include<stdio.h>
#include<stdlib.h>

int find_one_peak(int *A, int start, int end)
{
	int mid = (start+end)/2;
	if(A[mid]<A[mid-1])
		find_one_peak(A, start, mid-1);
	else if(A[mid]<A[mid+1])
		find_one_peak(A, mid+1, end);
	else if(start<=end)
		return A[mid];
	else 
		return -1;
}

int main()
{
	int n, *arr, peak;
	printf("Enter the size of array:");
	scanf("%d", &n);
	
	arr = (int *)malloc(n*sizeof(int));
	for(int i=0; i<n; i++)
		scanf("%d", arr+i);
	peak = find_one_peak(arr, 0, n-1);
	printf("Peak is: %d\n", peak);
	return 0;
}
