#include<stdio.h>
long int fib[100];

long int fibo(int n)
{ 
  if(n==1 || n==2)
  	return 1;
  else if(fib[n]!=0)
        return fib[n];
  else
        fib[n] = fibo(n-1)+fibo(n-2);
        return fib[n];
}

int main()
{
  int n;  
  printf("Fibbonacci Number\n");
  scanf("%d",&n);
  printf("%ld\n", fibo(n));
 return 0;
}
