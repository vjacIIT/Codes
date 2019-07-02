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
	int *ai, n, i, k, cup,tc, tca,j, steps;
	
	tca=1;
	scanf("%d", &tc);
	while(tc--)
	{
		cup=0;
		scanf("%d%d", &n, &k);
		
		ai = (int*)malloc(n*sizeof(int));
			for(int i=0; i<n; i++)	
				scanf("%d", ai+i);
		
		merge_sort(ai, n);	// now ai has expiry date.
		j=0;
		for(i=0; i<n; i++)
		{
			while(j<n)
			{
				steps=1;
				while(steps<=k)
				{
					if(i+1<=ai[j+steps-1] && (j+steps-1)<n)
					{
						cup++;
						steps++;
						//printf("CUPS:%d, Steps:%d\n", cup, steps);
					}
					else
						break;
				}
				
				if(steps!=1)
				{
					j+=steps-1;
					break;
				}
				else 
					j++;
			}
			if(j==n)
				break;
		}
		printf("Case #%d: %d\n", tca, cup);
		free(ai);
		tca++;
	}
	return 0;
}
