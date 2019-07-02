#include<stdio.h>
#include<stdlib.h>

int *merge(int *arr1, int l1, int *arr2, int l2, int *arr)
{
		int i=0, j=0, k=0;
		while(i<l1 && j<l2)
		{
				if(arr1[i]<=arr2[j])
				{
						arr[k]=arr1[i];  
						i++; 
				}
				else
				{
						arr[k]= arr2[j];
						j++;
				}
				
				k++;
		}
		
		
		while(i<l1)
		{
				arr[k] = arr1[i];
				i++;		k++;
		}
		
		while(j<l2)
		{
				arr[k] = arr2[j];
				j++;		k++;
		}

	return arr;				
}


int *merge_sort(int *A, int l)
{
		int i, j;
		int *arr1, *arr2;
		
		if(l==1)
			return A;
		else
		{
			   arr1 = (int *)malloc((l/2)*sizeof(int));
			   arr2 = (int *)malloc((l-(int)(l/2))*sizeof(int));	
				
				for(i=0; i<l/2; i++)
						arr1[i] = A[i]; 
			
				for(j=l/2; j<l; j++)
						arr2[j-l/2] = A[j];
				
				arr1 = merge_sort(arr1, i);
				arr2 = merge_sort(arr2, j-l/2);
				A  = merge(arr1, i, arr2, j-l/2, A);
				
				return A; 
		}
}


int main()
{
	int *arr, n, i, j;
	
	scanf("%d", &n);
	
	arr = (int*)malloc(n*sizeof(int));
		for(int i=0; i<n; i++)	
			scanf("%d", arr+i);
	
	arr = merge_sort(arr, n);
	for(i=0; i<n; i++)
			printf("%d ", *(arr+i));
			printf("\n");
				
	return 0;
}
