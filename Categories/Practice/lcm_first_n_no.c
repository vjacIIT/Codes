#include<stdio.h>
long int HCF(long int a,long int b)
{
     int sn1, sn2;
      if(a>b){
     sn1=b; b=a; a=sn1;
             }
 while((b%a)!=0){
              sn2=a;
            a=b%a; 
              b=sn2;
                }
  return a;                     
}

long int LCM(long int a,long int b)
{
   return ((a*b)/HCF(a,b));
}


long int recursion(long int n){
     if(n==2){ return (LCM(1,2)); }
     return (LCM(recursion(n-1),n));
                    }
int main()
{
 int tc, n;
 long int i;
 long int ar[41];
 for(i=2; i<=41; i++){
       ar[i-1]=recursion(i);
                     }

 scanf("%d", &tc);
 for(i=0; i<tc; i++){ ar[0]=1;
     scanf("%d", &n);
     printf("%ld\n", ar[n-1]);
                    }
 return 0;
}
