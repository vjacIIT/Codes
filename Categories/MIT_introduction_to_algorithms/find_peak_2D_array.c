#include<stdio.h>
#include<stdlib.h>

int find_global_max_ind(int **A, int mid, int n)
{
	int glob_max=A[0][mid];
	int glob_max_ind= 0;
	for(int i=0; i<n; i++)
	{
		if(A[i][mid]>glob_max)
		{
			glob_max_ind = i;
			glob_max=A[i][mid];
		}
	}
	printf("%d\n", A[glob_max_ind][mid]);
	return glob_max_ind;
}

int find_peak_2D_array(int **A, int start, int end, int n)
{
	int mid = (start+end)/2;    			// first we need to find the global maximum index in the mid column 
	int ind_max = find_global_max_ind(A, mid , n);
	
	if(A[ind_max][mid]<A[ind_max][mid-1])
		find_peak_2D_array(A, start, mid-1, n);
	else if(A[ind_max][mid]<A[ind_max][mid+1])
		find_peak_2D_array(A, mid+1, end, n);
	else if (start<=end)
		return A[ind_max][mid];
	else 
		return -1;
}

int main()
{
	int **arr, n, m, peak;
	printf("Enter number of rows and columns of array:");
	scanf("%d%d", &n, &m);
	arr = (int**)malloc(n*sizeof(int*));
	for(int i=0; i<n; i++)
	{
		arr[i] = (int*)malloc(m*sizeof(int));
		for(int j=0; j<m; j++)
			scanf("%d", arr[i]+j);
	}
	peak = find_peak_2D_array(arr, 0, m-1, n);
	printf("Peak in 2D array is %d\n", peak);
	return 0;
}
