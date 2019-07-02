#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n, *ptr, index, min, temp;
	
	printf("Give total no of elements:");
	scanf("%d", &n);
	ptr = (int*)malloc(n*sizeof(int));
	
	for(int i=0; i<n; i++)
		scanf("%d", ptr+i);

	for(int i=0; i<n; i++)
	{
			min = ptr[i];
			for(int j=i; j<n; j++)
			{
					if(*(ptr+j)<=min)
					{
							min = *(ptr+j);
							index = j;		
					}
			}
			temp = ptr[i];
			ptr[i]= min;
			ptr[index]= temp;
	}

	for(int i=0; i<n; i++)
			printf("%d ", ptr[i]);
	printf("\n");

	return 0;
}
