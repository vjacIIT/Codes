#include<stdio.h>
int main()
{
 long int n, i;
 scanf("%ld", &n);
 if(n%2==0)
{
 while((n%2)==0)
 {  
   n=n/2;
 }
 printf("2 ");
}

 for(i=3; i<=n; i=i+2)
 {
 if(n%i==0){
 while((n%i)==0)
 {
   n=n/i;  
 }
 printf("%ld  ", i);
           }
 }
 printf("\n");
 return 0;
}
