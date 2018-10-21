#include<stdio.h>
#include<stdlib.h>

int count_rotation(int *A, int n)
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

int main()
{
	int *arr, n, count;
	scanf("%d", &n);
	
	arr = (int *)malloc(n*sizeof(int));
	for(int i=0; i<n; i++)
		scanf("%d", arr+i);
	
	count = count_rotation(arr, n);
	printf("Number of rotation of sorted array is: %d\n", count);
	
	return 0;
}
