#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *ptr, n, *ptr2, min, index;
	
	printf("Give total no of integers:");
	scanf("%d", &n);
	
	ptr = (int*)malloc(n*sizeof(int));
	ptr2 = (int*)malloc(n*sizeof(int));
	
	
	for(int i=0; i<n; i++)
	{
			scanf("%d", ptr+i);
	}
	
	
	for(int j=0; j<n; j++)
	{
			min = 100000;
			
			for(int i=0; i<n; i++)
			{
					if(*(ptr+i)<min)
					{
							min = *(ptr+i);
							index = i;		
					}
				
			}
			ptr2[j]= min;
			ptr[index] = 100000; 
	}
	
	for(int j=0; j<n; j++)
	{
		printf("%d ", ptr2[j]);
	}
	printf("\n");
	
	return 0;
}
