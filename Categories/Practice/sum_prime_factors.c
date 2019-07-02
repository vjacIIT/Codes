#include<stdio.h>

int main()
{
 long int n;
 long long int sum;

 long int i, ar[100]={0};
 int f1=0, j=0, k=0, tc, m;
 
 scanf("%d", &tc);
 for(m=0; m<tc; m++)
{ sum=0; f1=0; j=0; k=0;
 scanf("%ld", &n);
 if(n%2==0)
{
 while((n%2)==0)
 {  
   n=n/2;
 }
 ar[j]=2;
 j++;
}

 for(i=3; i<=n*n; i=i+2)
 {
 f1=0;
 if(n%i==0){
 ar[j]=i;
 j++;
 while((n%i)==0)
 {
   n=n/i; f1=1;  
 }

           }
 }

 if(f1==0)
 {
  ar[j]=n;
  j++;
  
 }

 for(k=0; k<j; k++)
 {
     
   sum+=ar[k];
  
 }

 printf("sum %lld\n", sum);
}

 return 0;
}
