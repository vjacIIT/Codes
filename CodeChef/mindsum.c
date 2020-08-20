#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int fr1=0;

typedef struct st
{
	long int val, ind;
}st;

int comparator(const void *p1, const void *p2)
{
	int a, b;
	a = ((st*)p1)->val;
	b = ((st*)p2)->val;
	if(a!=b)
		return a-b;
	else
	{
		a = ((st*)p1)->ind;
		b = ((st*)p2)->ind;
		return a-b;
	}
}

long int digitSum(long int n)
{
	long int sum =0;
	if(n<10)
		return n;
		
	for(int i=0; i<12; i++)
	{
		sum+=n%10;
		n-=n%10;
		n = n/10;
		//printf("%ld\n", n);
	}
	
	if(sum%10==sum)
		return sum;
	else
		return digitSum(sum);
}

long int AcdigitSum(long int n)
{
	long int sum =0;
	if(n<10)
		return n;
	
	for(int i=0; i<12; i++)
	{
		sum+=n%10;
		n-=n%10;
		n = n/10;
		//printf("%ld\n", n);
	}
	
	return sum;
}

void function(long int *ar, long int N, long int D, int i)
{
	long int sum;
	long int nplsd;
	if(i>5000)
		return;
	sum=AcdigitSum(N);
	nplsd = N+D;
	ar[2*i+1]=sum;
	ar[2*i+2]=nplsd;
	if(sum%10!=sum)
		function(ar, sum, D, 2*i+1);
	function(ar, nplsd, D, 2*i+2);
	return;
}

int find(long int *ar, int key)
{
	for(int i=0; i<5000; i++)
	{
		if(ar[i]==key)
			return i+1;
	}
}

int main()
{
	st *arr1;
	int tc;
	long int N, D;
	long int arr[10000];
	scanf("%d", &tc);
	while(tc--)
	{
		arr1 = (st*)malloc(100*sizeof(st));
		for(int i=0; i<10000; i++)
			arr[i]=-1;
		scanf("%ld%ld", &N, &D);
		arr[0]=N;
		function(arr, N, D, 0);
		
		/*for(int i=0; i<500; i++)
			printf("%ld ", arr[i]);
		printf("\n");*/
		
		for(int i=0; i<10; i++)
		{
			arr1[i].val=digitSum(N+i*D);
			arr1[i].ind=i+fr1;
			fr1=0;
		}
		
		qsort((void*)arr1, 10, sizeof(st), comparator);
		
		int ind = find(arr, arr1[0].val);
		//printf("%d\n", ind);
		fr1=0;
		while(ind>0)
		{
			ind=ind/2;
			fr1++;
		}
		printf("%ld %d\n", arr1[0].val, fr1-1);
	}
	return 0; 	
	//for(int i=0; i<10; i++)
		//printf("%ld %ld\n", arrs[0].val, arrs[0].ind);
		//printf("\n");

}
