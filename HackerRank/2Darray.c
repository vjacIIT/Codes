#include<stdio.h>
#include<stdlib.h>

int main()
{
	int **ar, n	;
	scanf("%d", &n);
	ar = (int**)malloc(n*sizeof(int*));
	for(int i=0; i<n; i++)
		ar[i]=(int*)malloc(n*sizeof(int));
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++){
			ar[i][j]=(i+j)%2;
			//scanf("%d", ar[i]+j);]
			printf("%d ", ar[i][j]);
		}
		printf("\n");
	}
	
	/*int sum=-1000, val;
	for(int i=0; i<4; i++)
	{
		for(int j=1; j<=4; j++)
		{
			val=ar[i][j-1]+ar[i][j]+ar[i][j+1]+ar[i+1][j]+ar[i+2][j]+ar[i+2][j-1]+ar[i+2][j+1];
			if(val>sum)
				sum=val;
		}
	}
	printf("%d\n", sum);
	*/
	return 0;
}
