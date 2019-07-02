#include<stdio.h>

  int main()
 {
  int a[3010], carry=0, sum=0, sumn[10002];
  int b[3010], i, j, tc, n;

  sumn[0]=0;

  for(i=0; i<3010; i++)
  {
     a[i]=0;  b[i]=0;
  }
  
  a[0]=1;
  
    for(i=0; i<10000; i++)
    {    
        sum=0;  
       for(j=0; j<3010; j++)
       {
 
          b[j]=2*a[j]+carry;
          carry=0;       
 
           if(b[j]>=10)
           { 
             carry=1;
             b[j]-=10;
           
           }
         
        // printf("%d ", b[3009-j]);
        }
  
   //    printf("\n");
       for(j=0; j<3010; j++)
       {
          sum+=b[j];
          a[j]=b[j];
       }

       sumn[i+1]=sum;       
   //    printf("%d, ", sumn[i+1]);
    }
 
  //  printf("\n");

   scanf("%d", &tc);
   for(i=0; i<tc; i++)
   {
      scanf("%d", &n);
      printf("%d\n", sumn[n]);
   }
 
  return 0;
 }

