#include<stdio.h>
#include<stdlib.h>

int main()
{
	int N, X, S, val1, val2, tc;
	scanf("%d", &tc);
	while(tc--)
	{
		scanf("%d%d%d", &N, &X, &S);
		while(S--)
		{
			scanf("%d%d", &val1, &val2);
			if(val1==X)
				X=val2;
			else if(val2==X)
				X=val1;
			else
				continue;
		}
		printf("%d\n", X);
	}
	return 0;
}
