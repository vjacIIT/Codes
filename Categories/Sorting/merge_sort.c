#include<stdio.h>
#include<stdlib.h>

void merge(int *arr1, int l1, int *arr2, int l2)
{
		int i=0, j=0, k=0, arr[l1+l2];
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
		
		for(k=0; k<l1; k++)
				arr1[k]=arr[k];

		for(k=l1; k<l1+l2; k++)
				arr2[k-l1]=arr[k];

	return ;				
}


void merge_sort(int *A, int l)
{		
		int len;
		len = l/2;
		if(l==1)
			return ;
		else
		{		
				merge_sort(A, len);
				merge_sort(A+l/2, l-len);
				merge(A,l/2, A+l/2, l-len);
				
				return ; 
		}
}


int main()
{
	int *arr, n, i;
	
	scanf("%d", &n);
	
	arr = (int*)malloc(n*sizeof(int));
		for(int i=0; i<n; i++)	
			scanf("%d", arr+i);
	
	merge_sort(arr, n);
	for(i=0; i<n; i++)
			printf("%d ", *(arr+i));
			printf("\n");

	free(arr);
	return 0;
}
