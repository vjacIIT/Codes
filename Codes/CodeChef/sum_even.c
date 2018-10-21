#include<stdio.h>
int main()
{
	long int el1, el21, el22, difference1, difference2, diff_matrix[30];
	long int n;
	long int tc, i, flag;

	scanf("%ld", &tc);

	while(tc--)
	{		difference1=100000; difference2=100000; flag=0;
		scanf("%ld", &n);

		if(n==1)
		{
			printf("2\n");
			flag=1;
		}
		else if(n==2)
		{
			printf("1\n");
			flag=1;
		}
		i=1;
		el1=1; 
		el21=1;
		el22=1;		
		while(el21<n)  // it is always smaller or equal to our n
			el21*=2;

		el21/=2;

		while(el22<n)	// it is always bigger or equal to our n		
			el22*=2;


		difference2 = (el22+1)-n;  // difference which is formed by bigger el22

		diff_matrix[0]= n-(1+el21);
		while(el1<el21 && diff_matrix[i-1]>=0)
		{
			diff_matrix[i]= n-(el1+el21);
			el1*=2;		i++;	
		}		
		el1/=2;

		// difference which is formed by smaller el21

		//	printf("diff_matrix[%d-1] is %ld\n",i, diff_matrix[i-1]);
		//	printf("diff_matrix[%d-2] is %ld\n",i, diff_matrix[i-2]);
		if(diff_matrix[i-1]<0)
			diff_matrix[i-1]*=-1;
		if(diff_matrix[i-2]<=diff_matrix[i-1])
			difference1 = diff_matrix[i-2];
		else 
			difference1 = diff_matrix[i-1];

		//printf("el1 is %ld el21 is %ld el22 is %ld\n", el1, el21, el22);

		if(difference1>=difference2 && el21!=el22 && difference2>=0 && flag==0)
			printf("%ld\n", difference2);
		else if(difference1<difference2 && el21!=el22 && difference1>=0 && flag==0)
			printf("%ld\n", difference1);
		else if(el21==el22 && flag==0)
			printf("1\n");
	}

	return 0;
} 
