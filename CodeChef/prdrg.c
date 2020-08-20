#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	int tc, n;
	int p, x, y;
	scanf("%d", &tc);
	while(tc--)
	{
		scanf("%d", &n);
		y = pow(2, n);
		if(n%2==0)
		{
			p =0;
			x = 0;
			while(p!=n)
			{
				x = x*4+1;
				p +=2;
			}
		}
		else
		{
			p =1; 
			x = 1;
			while(p!=n)
			{
				x = x*4-1;
				p+=2;
			}
		}
		printf("%d %d ", x, y);
		
	}
	return 0;
}
