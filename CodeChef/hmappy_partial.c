#include<stdio.h>
#include<stdlib.h>
#include<math.h>

long long int sum=0;
long long int bl;
long int stps = 0;
//long int sb=0;
//long int nb=0;

typedef struct st
{
	long int mul, can;
}st;

void swap(st *a, st *b)
{
	long int c;
	c = b->mul;
	b->mul = a->mul;
	a->mul = c;
	
	c = b->can;
	b->can = a->can;
	a->can = c;
	return;
}

void max_heapify(st *ac, int i, int n)
{
	int max;
	max = i;
	if(2*i+1<n && ac[2*i+1].mul>ac[max].mul)
		max = 2*i+1;
	if(2*i+2<n && ac[2*i+2].mul>ac[max].mul)
	{
		swap(&ac[i], &ac[2*i+2]);
		max_heapify(ac, 2*i+2, n);
		return;
	}
	else if(2*i+1<n && max!=i)
	{
		swap(&ac[i], &ac[2*i+1]);
		max_heapify(ac, 2*i+1, n);
		return;
	}
	return;
}

void build_heap(st *ac, int n)
{
	for(int i=n/2; i>=0; i--)
		max_heapify(ac, i, n);
	return;
}

int fdStpsech(int mul, int htr, int can, long int *arrs, int i)
{
	long double stpeach;
	if(mul<=htr)
	{
		arrs[i]=0;
		return 0;	
	}
	else
	{
		stpeach = (1.0*(mul-htr))/can;
		arrs[i]=ceil(stpeach);
		return ceil(stpeach);
	} 
}

long int fdTotalStp(st *ac, int htr, int n, long int *arrs)
{
	long int tstps=0;
	for(int i=0; i<n; i++)
	{
		//printf("Sps: %ld\n", tstps);
		//tstps = stps;
		stps+=fdStpsech(ac[i].mul, htr, ac[i].can, arrs, i);
		//tstps = stps;
		//printf("Spd: %ld\n", tstps);
	}
	return stps;
}

long int fdHeight(st *ac, int n, long int bl, long int str, long int end, long int *arrs)
{
	stps=0;
	long int mid = (str+end)/2;
	//printf("IS FINE\n");
	stps = fdTotalStp(ac, mid, n, arrs);
	//printf("STEPS %ld\n", stps);
	if(stps>bl)
		return fdHeight(ac, n, bl, mid, end, arrs);
	else if(stps==bl)
		return mid;
	else if(stps<bl && bl-stps<n)
		return mid;
	else 
		return fdHeight(ac, n, bl, str, mid, arrs); 
}

int main()
{
	long int *arrb, *arrc, *arrs;
	long int n, max, ht=0;
	st *ac;
	
	scanf("%ld", &n);
	scanf("%lld", &bl);
	arrb = (long int*)malloc(n*sizeof(long int));
	arrc = (long int*)malloc(n*sizeof(long int));
	arrs = (long int*)malloc(n*sizeof(long int));
	ac = (st*)malloc(n*sizeof(st));
	
	for(int i=0; i<n; i++)
	{
		arrs[i]=0;
		scanf("%ld", arrb+i);
		sum += arrb[i];
	}
	for(int i=0; i<n; i++)
	{
		scanf("%ld", arrc+i);
		ac[i].mul = arrb[i]*arrc[i];
		ac[i].can = arrc[i];
	}
	
	/*if(bl>=sum)
	{
		printf("0\n");
		return 1;
	}*/
	
	// I have given the height and I need to find the number of ballons required by the total array to reach there or less than that value
	
	
	build_heap(ac, n);
	//printf("IS FINE\n");
	ht = fdHeight(ac, n, bl, 0, ac[0].mul, arrs);
	//printf("%ld\n", stps);
	bl = bl-stps;
	for(int i=0; i<n; i++)	// now I have got number of steps as well as height 
		ac[i].mul -=arrs[i]*ac[i].can; 
	
	build_heap(ac,n);
	while(bl>0)
	{
		ac[0].mul -= ac[0].can;	
		bl--;	// we need to decrease each multiplication by it's candy value
		max_heapify(ac,0, n);
	}
	printf("%ld\n", ac[0].mul);

/*{	
			max = 2*sb+1;
			if(ac[2*sb+2].mul>ac[max].mul)
				max=2*sb+2;				
			stp = ac[sb].mul/ac[sb].can-ac[max].mul/ac[sb].can;
			if(stp!=0)
				bl = bl-stp;
			else
			{
				nb++;
				sb = max;
				bl = bl-1;
				stp=1;
			}
			if(bl>=0)
				ac[sb].mul -=stp*ac[sb].can;
			else
				ac[sb].mul -=bl*ac[sb].can;
			max_heapify(ac, 0, n);			// then heapify at 0
		}
	}
	else if(n==2)		
	{
		while(bl>0)
		{	
			max=1;				
			stp = ac[0].mul/ac[0].can-ac[max].mul/ac[0].can;
			if(stp!=0)
				bl = bl-stp;
			else
			{
				stp=ac[0].mul/ac[0].can;
				bl=bl-stp;
			}
			if(bl>=0)
				ac[sb].mul -=stp*ac[sb].can;
			else
				ac[sb].mul -=bl*ac[sb].can;
			max_heapify(ac, 0, n);			// then heapify at 0
		}
	}
	else
	{
		stp = bl;
		ac[0].mul -=stp*ac[0].can; 
	}
	if(bl<=0)
		printf("%ld\n", ac[0].mul);
	else
	{
		while(bl>0)
		{
			ac[0].mul -= ac[0].can;
			bl--;
			max_heapify(ac, 0, n);
		}
		printf("%ld\n", ac[0].mul);
	}*/
	return 0;	
}
