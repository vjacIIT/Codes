#include<stdio.h>
#include<stdlib.h>

int first_last_index(int *A, int n, int value, int flag)
{
	int start = 0, end=n-1, result=-1, mid;
	while(start<=end)
	{	
		mid = (start+end)/2;
		if(A[mid]==value)
		{
			result = mid;
			if(flag==0)
				end = mid-1;
			else
				start = mid+1;
		}
		else if(A[mid]<value)
			start = mid+1;
		else 
			end = mid-1;
	}
	
	return result;
}


int main()
{
	int *arr, n, value, ind_s, ind_e;
	scanf("%d%d", &n, &value);
	
	arr= (int*)malloc(n*sizeof(int));
	for(int i=0; i<n; i++)
		scanf("%d", arr+i);

	ind_s = first_last_index(arr, n, value, 0);
	ind_e = first_last_index(arr, n, value, 1);
	
	if(ind_s==-1 || ind_e==-1)
		printf("Input no is not in the array\n");
	else 
		printf("%d is coming %d times in array\n", value, ind_e-ind_s+1);
	return 0;	
}
