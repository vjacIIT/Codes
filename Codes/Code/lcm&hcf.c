#include<stdio.h>
long int HCF(long int a, long int b){
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
long int LCM(long int a, long int b)
{
    return ((a*b)/HCF(a,b));
}


int main()
{
 long int a, b, hcf, lcm;
 scanf("%ld %ld", &a, &b);
 hcf=HCF(a,b);
  printf("HCF is %ld\n", hcf);
 lcm=LCM(a,b);
  printf("LCM is %ld\n", lcm);
 return 0;
}
