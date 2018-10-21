#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b)
{
	int temp;
	temp = *a; 
	*a = *b;
	*b = temp;
}

void max_heapify(int *A, int i, int n)
{
	int lft=2*i+1, rgt=2*i+2, max_ind=i;
	
	if(lft<n && A[lft]>A[i])
		max_ind = lft;
	else
		max_ind = i;
		
	if(rgt<n && A[rgt]>A[max_ind])
	{
		max_ind = rgt;
		swap(&A[max_ind],&A[i]);
		max_heapify(A, max_ind, n);
	}
	else if(max_ind!=i) 
	{
		swap(&A[max_ind],&A[i]);
		max_heapify(A, max_ind, n);
	}
	else
		return;
}

void build_max_heap(int *A, int n)
{
	for(int i=n/2-1; i>=0; i--)
		max_heapify(A, i, n);
	return;
}

void heap_sort(int *A, int n)
{
	if(n==1)
		return;
	else
	{
		swap(&A[0], &A[n-1]);
		max_heapify(A, 0, n-1);
		heap_sort(A, n-1);
	}
}

int main()
{
	int *arr, n;
	
	scanf("%d", &n);
	arr = (int *)malloc(n*sizeof(int));
	
	for(int i=0; i<n; i++)
		scanf("%d", arr+i);
		
	build_max_heap(arr, n);
	heap_sort(arr, n);
	for(int i=0; i<n; i++)
		printf("%d ", arr[i]);
	printf("\n");
	free(arr);
	return 0;
}
