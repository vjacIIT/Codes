#include<stdio.h>
#include<stdlib.h>

int main()
{
	int tc, n, fr;
	int *arr;
	scanf("%d", &tc);
	while(tc--)
	{
		fr=0;
		scanf("%d", n);
		arr = (int*)malloc(n*sizeof(int));
		for(int i=0; i<n; i++)
			scanf("%d", ar+i);
		for(int i=0; i<n-1; i++)
		{
			if(ar[i]!=-1)
				no=ar[i];
			if(arr[i]==ar[i+1] && arr[i]!=-1)
			{
				flag1=1;
				break;
			}	
			else if(arr[i]==arr[i+1])
				fr++;
			else if(arr[i+1]>=ar[i]+2  && ar[i]!=-1)
			{
				flag1=1;
				break;
			}
		}
		if(fr==n)
			printf("inf\n");
		else if(flag1=1)
			printf("impossible\n");
		
	}
}
