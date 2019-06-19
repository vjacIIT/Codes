#include<stdio.h>
#include<stdlib.h>

int compare(const void *a, const void *b)
{
	int A, B;
	A = *((int*)a);
	B = *((int*)b);
	return A-B; 
}

int main()
{
	long int N, ev, od, no, fr, flag, tc;
	long int n1, n2;
	int *arev, *arod;
	scanf("%ld", &tc);
	while(tc--)
	{
		fr=0; 
		flag=0;
		od=0;
		ev=0;
		n1=0; 
		n2=0;
		scanf("%ld", &N);
		arev = (int*)malloc(N*sizeof(int));
		arod = (int*)malloc(N*sizeof(int));
		for(int i=0; i<N; i++)
		{
			scanf("%ld", &no);
			if(no%2==0)
			{
				arev[ev]=no;
				ev++;
			}
			else
			{
				arod[od]=no;
				od++;
			}
		}
		qsort(arev, ev, sizeof(int), compare);
		qsort(arod, od, sizeof(int), compare);
		for(int i=0; i<ev; i++)
			arev[i]=arev[i]>>2;		// now 2 bit value has been reduced from each value
		
		for(int i=0; i<od; i++)
			arod[i]=arod[i]>>2;
		
		//printf("ev: %d, od: %d\n", ev, od);
		n1=(ev*(ev-1))/2;
		n2=(od*(od-1))/2;
		for(int i=0; i<ev-1; i++)
		{
			if(arev[i]==arev[i+1] && flag==0)
			{
				flag=1;
				fr=fr+2;
			}
			else if(arev[i]==arev[i+1])	
				fr++;
			else
			{	
				n1=n1-(fr*(fr-1))/2;
				fr=0;
				flag=0;
			}
		}
		if(flag==1)
			n1=n1-(fr*(fr-1))/2;	
		fr=0;
		flag=0;
		for(int i=0; i<od-1; i++)
		{
			if(arod[i]==arod[i+1] && flag==0)
			{
				flag=1;
				fr=fr+2;
			}
			else if(arod[i]==arod[i+1])
				fr++;
			
			else
			{
				n2 = n2-(fr*(fr-1))/2;
				fr=0;
				flag=0;
			}
		}	
		if(flag==1)
			n2=n2-(fr*(fr-1))/2;	
		
		printf("%ld\n",n1+n2);
		free(arev);
		free(arod);
	}	
	return 0;
}
