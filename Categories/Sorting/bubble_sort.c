#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *ptr, n, flag, temp;
	
	scanf("%d", &n);
	ptr = (int*)malloc(n*sizeof(int));
	
	for(int i=0; i<n; i++)
			scanf("%d", ptr+i);
			
	for(int i=n-1; i>=0; i--)
	{
			flag = 0;
			for(int j=0; j<i; j++)
			{
					if(ptr[j+1]<ptr[j])
					{
							temp = ptr[j+1];
							ptr[j+1]= ptr[j];
							ptr[j]= temp;
							flag=1;
					}
			}
			if(flag==0)
					break;
	}
	
	for(int j=0; j<n; j++)
			printf("%d ", ptr[j]);
	printf("\n");
	
	free(ptr);
	return 0;
}
