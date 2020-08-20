#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	int tc, stp, n, k;
	int *ar;
	scanf("%d", &tc);
	while(tc--)
	{
		scanf("%d%d", &n, &k);
		ar=(int*)malloc(n*sizeof(int));
		for(int i=0; i<n; i++)
			scanf("%d", ar+i);
		
		stp=0;
		for(int i=0; i<n-1; i++)
		{
			if(ar[i+1]-ar[i]>k)
			{
				stp+=ceil((1.0*ar[i+1]-ar[i])/k)-1;
				//printf("%d\n", stp);
			}	
		}
		printf("%d\n", stp);
		free(ar);
	}
}
