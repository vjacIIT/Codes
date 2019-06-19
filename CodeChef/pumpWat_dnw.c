#include<stdio.h>
#include<stdlib.h>

typedef struct st
{
	int val, ind;
}st;

int comparator(const void *p1, const void *p2)
{
	int a, b;
	a = ((st*)p1)->val;
	b = ((st*)p2)->val;
	return a-b;
}

function(int *arr, st *ar, int start, int end)
{
	if(ar[]
}

int main()
{
	int tc, n, stp;
	scanf("%d", &tc);
	st *ar;
	while(tc--)
	{
		scanf("%d", &n);
		ar = (st*)malloc(n*sizeof(st));
		arr = (int*)malloc(n*sizeof(int));
		for(int i=0; i<n; i++)
		{
			scanf("%d", &val);
			arr[i]=val;
			ar[i].val=val;
			ar[i].ind=ind;
		}
		qsort((void*)ar, n, sizeof(st), comparator);
		function(arr, ar, 0, n-1)
	}
}
