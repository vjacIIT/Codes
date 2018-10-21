#include<stdio.h>
#include<stdlib.h>

int partition(int *A, int start , int end)
{
	int pivot = A[end];
	int p_index = start, temp;
	for(int i=start; i<end; i++)
	{
		if(A[i]<=pivot)
		{
			temp = A[p_index];		
			A[p_index]=A[i];
			A[i] = temp;
			p_index++;
		}					
	}
	
	temp = A[p_index];
	A[p_index] = pivot;
	A[end] = temp;
	
	return p_index;
}

void quick_sort(int *A, int start, int end)
{
	int p_index;
	
	if(start<end)
	{
		p_index = partition(A, start, end);
		quick_sort(A, start, p_index-1);
		quick_sort(A, p_index+1, end);
	}

	else 
		return ;
}

int main()
{
	int n, *arr, p_index;
	scanf("%d", &n);
	
	arr = (int *)malloc(n*sizeof(int));
	
	for(int i=0; i<n; i++)
		scanf("%d", arr+i);

	quick_sort(arr, 0, n-1);
	
	for(int i=0; i<n; i++)
		printf("%d ", *(arr+i));
	printf("\n");
	return 0;
}
