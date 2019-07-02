#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n, *ptr, temp;
	
	scanf("%d", &n);
	ptr = (int*)malloc(n*sizeof(int));
	
	for(int i=0; i<n; i++)
			scanf("%d", ptr+i);

	for(int i=0; i<n-1; i++)
	{
			for(int j=i+1; j>=0; j--)
			{
					if(ptr[j]<ptr[j-1])
					{
							temp = ptr[j-1];
							ptr[j-1]= ptr[j];
							ptr[j]= temp;
					}
			}
	
	}

	
	for(int i=0; i<n; i++)
			printf("%d ", ptr[i]);
	printf("\n");
	
	return 0;
}
