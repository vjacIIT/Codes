#include<stdio.h>
#include<stdlib.h>

int main()
{
	int tc, n, fr0, fr1;
	char name[3];
	char string;
	scanf("%d", &tc);
	while(tc--)
	{
		fr0=0;
		fr1=0;
		scanf("%d%s", &n, name);
		for(int i=0; i<n; i++)
		{
			scanf("%s", string);
			if(string[0]=='0')
				fr0++;
			else
				fr1++;
		}
		if(fr0==0)
		{
			if(strcmp(name, "Dee")==0)
			{
				printf("Dee\n");
				continue;
			}
			else
		}
		if(fr0%2==0 && fr1%2==0)
		{
			
		}
	}
	return 0;
}
