#include<stdio.h>
int main()
{
 int  i, n, j, tc, l, count[100001][18], pf=0, pa[100000]={0}, pr[100000], max;
 long int k; 
     
     for(i=0; i<100000; i++)
     {
       pr[i]=1;
     }

     for(i=0; i<=100000; i++)
     {
          for(j=0; j<=17; j++)
          {
              count[i][j]=1;
          }
     }

     for(i=1; i<100000; i++)
     {   pf=0; pa[i]=pf;
         k=((i+2)*(i+1))/2;
         for(j=2; j*j<=k; j++)
         {
             if(k%j==0)
             {  pf++; pa[i]=pf;
               while(k%j==0)
                          {
                           count[i][pf]++;          
                           k=k/j;
                          }
              }
             
             
         }
      
             if(k!=1)
             {
                pf++; pa[i]=pf;
                count[i][pf]++;
             }
 

     }

     
     for(i=1; i<=42000; i++)
     {
        for(j=0; j<=pa[i]; j++)
        {
          pr[i]=pr[i]*count[i][j];
        }
        
     }
   
   /*  max=pr[0];
     for(i=0; i<=42000; i++){
       printf("%d\t", pr[i]);
       if(pr[i]>max){
                  if(max>1000){  printf("%d\n", i); break; }
                 
                  max=pr[i];
                     }
                           }
    printf("%d\n", max);
 */

    scanf("%d", &tc);  
  
    for(j=0; j<tc; j++){

    scanf("%d", &n);
    for(i=0; i<42000; i++)      
    {
      if(pr[i]>n){
        k=((i+2)*(i+1))/2;
        printf("%ld\n", k);
        break;
                  }
    }
                        }
  
 
 return 0;
}
