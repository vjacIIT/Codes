#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

long int d=100000009;

typedef struct table
{
	int em, pno;		// contains empty as em, phone number as pno and string as str
	char str[20];
}table;

unsigned long int hashvalue(char *c, int len)
{
	unsigned long int val=0;
	unsigned long int p = 31;		// prime no for hashing 
						//hash(s)=(s[0]+s[1]⋅p+s[2]⋅p2+...+s[n−1]⋅pn−1)mod(d)
	unsigned long int power=1;
	for(int i=0; i<len; i++)
	{
		//printf("%ld\n", power);
		val+=((c[i]-'a'+1)*power)%d;		// hasing of a string to an integer here
		power=(power*p)%d;			// d=10^7 + 9 has the value to make it smaller otherwise it will go out of bounds
	}
	return val%d;
}

int main()
{
	int n, pno, flag;
	unsigned long int val;
	table *ar;
	char str[20];
	ar = (table*)malloc(d*sizeof(table));
	for(int i=0; i<d; i++)
		ar[i].em=0;
	scanf("%d", &n);
	while(n--)
	{
		scanf("%s %d", str, &pno);
		//printf("%s\n", str);
		val = hashvalue(str, strlen(str));
		if(ar[val].em==0)			// if place is empty fill it. em is 1 if it is full
			ar[val].em=1;
		else
		{
			while(ar[val].em==1)		// if already full go uptil we reach a nerby place which is empty
				val+=1;
		}
		//printf("Did it come here\n");
		ar[val].em = 1;				// fill the place and put the string into the place
		strcpy(ar[val].str, str);
		ar[val].pno = pno;
		
	}
	while(scanf("%s", str)!=EOF)
	{
		flag=0;
		val = hashvalue(str, strlen(str));
		if(ar[val].em==1)				// if full check for the string 
		{
			while(ar[val].em!=0)		// untill we reach end point 
			{
				if(strcmp(ar[val].str, str)==0)
				{
					flag=1;					// if we found out the string print it, flag is used as a flag for the search
					printf("%s=%d\n", str, ar[val].pno);
					break;
				}
				else
					val++;
			}
			if(flag!=1)						// means we have not find the string
				printf("Not found\n");
		}
		else					// else string is not there
			printf("Not found\n");
	}
	return 0;
}
