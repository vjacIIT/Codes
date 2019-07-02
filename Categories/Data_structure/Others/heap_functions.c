#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b)
{
	int temp;
	temp = *a; 
	*a = *b;
	*b = temp;
}

void max_heapify(int *A, int ind, int n)
{
	int lft=2*ind+1, rgt=2*ind+2, max_ind=ind;
	
	if(lft<n && A[lft]>A[ind])
		max_ind = lft;
	else
		max_ind = ind;
		
	if(rgt<n && A[rgt]>A[max_ind])
	{
		max_ind = rgt;
		swap(&A[max_ind],&A[ind]);
		max_heapify(A, max_ind, n);
	}
	else if(max_ind!=ind) 
	{
		swap(&A[max_ind],&A[ind]);
		max_heapify(A, max_ind, n);
	}
	else
		return;
}

void build_max_heap(int *A, int n)
{
	for(int ind=n/2-1; ind>=0; ind--)
		max_heapify(A, ind, n);
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

void replace_key(int *A, int ind, int value, int n)
{
	if(A[ind]>value)		// means value at that index has been decreased
	{	
		A[ind]=value;
		max_heapify(A, ind, n);
		return;
	}
	else 				// means value at that index has been increase or remained same
	{
		A[ind]=value;
		while(ind>0)
		{
			if(A[(ind-1)/2]<A[ind])
			{
				swap(&A[ind], &A[(ind-1)/2]);
				ind = (ind-1)/2;
			}
			else 
				return;
		}
		return;
	}
}		

void insert_key(int *A, int value, int n)
{
	A = (int*)realloc(A, (n+1)*sizeof(int));
	A[n]=value;
	while(n>0)
	{
		if(A[n]>A[(n-1)/2])
		{
			swap(&A[n], &A[(n-1)/2]);
			n=(n-1)/2;
		}
		else
			return;
	}
	return;
}

void extract_max(int *A, int n)
{
	swap(&A[n-1], &A[0]);
	max_heapify(A, 0, n-1);
}

int main()
{
	int *arr, n;
	
	scanf("%d", &n);
	arr = (int *)malloc(n*sizeof(int));
	
	for(int i=0; i<n; i++)
		scanf("%d", arr+i);
		
	build_max_heap(arr, n);
	extract_max(arr, n);
	for(int i=0; i<n-1; i++)
		printf("%d ", arr[i]);
	printf("\n");
	free(arr);
	return 0;
}
