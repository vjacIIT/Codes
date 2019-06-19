#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct circle
{
	long int x, y, r; 
}circle;

typedef struct st
{
	long int max;
	long int min;
}st;

int main()
{
	long int N, Q, k=0, q;
	circle *arr;
	long int dx, dy, i, j;
	long int count, maxr, minr;
	long double c1c2;
	st *com;
	scanf("%ld%ld", &N, &Q);
	arr = (circle*)malloc(N*sizeof(circle));
	for(i=0; i<N; i++)
		scanf("%ld%ld%ld", &(arr[i].x), &(arr[i].y), &(arr[i].r));
	
	com = (st*)malloc(((N*(N-1))/2)*sizeof(st));
	for(i=0; i<N; i++)
	{
		for(j=i+1; j<N; j++)
		{
			maxr = arr[i].r;
			minr = arr[j].r;
			dx = arr[i].x - arr[j].x;
			dy = arr[i].y - arr[j].y;
			c1c2 = sqrt(dx*dx + dy*dy);
			if(maxr<arr[j].r)
			{
				minr = maxr;
				maxr=arr[j].r;
			}
			if(c1c2>=maxr+minr)
			{
				com[k].max = c1c2 + arr[i].r + arr[j].r;
				com[k].min = ceil(c1c2 - arr[i].r - arr[j].r);
			}
			else if(c1c2>=maxr-minr)
			{
				com[k].max = c1c2 + arr[i].r + arr[j].r;
				com[k].min = 0;
			}
			else
			{
				com[k].max = c1c2+minr+maxr;
				com[k].min = ceil(maxr-c1c2-minr);
			}
			k++;
		}
	}
	
	for(i=0; i<Q; i++)
	{
		count=0;
		scanf("%ld", &q);
		for(j=0; j<N*(N-1)/2; j++)
		{
			//printf("%ld %ld\n", com[j].min, com[j].max);
			if(q>=com[j].min && q<=com[j].max)
				count++;
		}
		printf("%ld\n", count);
	}
	
	
	return 0;
}
