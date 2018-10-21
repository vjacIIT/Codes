#include<stdio.h>

long long int   ar[93];

 long long int fn(int n)
{   

 if(ar[n]!=-1)
    return ar[n];

 ar[n]=fn(n-1)+fn(n-2);
   
 return ar[n];  
        
}


int main()
{
 long long int fnn;
 int i, n;
 
  for(i=0; i<93; i++)
  {
       ar[i]=-1;
  }  

  ar[0]=0; ar[1]=1;

 scanf("%d", &n);
 fnn=fn(n);

 printf("%lld\n", fnn);
 
 return 0;
}
