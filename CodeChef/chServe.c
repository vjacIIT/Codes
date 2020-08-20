#include<stdio.h>
#include<stdlib.h>

int main()
{
	int t;
	long int p1, p2, k, l;
	scanf("%d", &t);
	for(int i=0; i<t; i++)
	{
		//printf("%d ", t);
		scanf("%ld%ld%ld", &p1, &p2, &k);
		l = p1/k;
		l = l+p2/k;		
		l = l%2 ;		
		p1 = p1%k;
		p2 = p2%k;
		if(p1+p2>=k)
			l+=1;
		if(l%2==0)
			printf("CHEF\n");
		else
			printf("COOK\n");
	}
	return 0;
}
