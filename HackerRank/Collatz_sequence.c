#include<stdio.h>
int main()
{
 long int i=1, j=1, n, max[1001]={0}, ithval[100]={0};
 int  count=0, k=1, tc ; 
   
    max[0]=0; 
    for(i=1; i<=6000000; i++)
    {
        count=0;
        j=i;
        while(j>1)
        {
              if(j%2==0){
                  j=j/2;       count++;
                        }
              else {
                 j=(3*j)+1;    count++;
                    }
         }

           
     
           if(count>=max[k-1]){
               max[k]=count;    ithval[k]=i;     
               printf("%ld,%ld \t", max[k], ithval[k]);      k++;
                              }
     }
   
   

   scanf("%d", &tc);
     for(i=0; i<tc; i++)
   {
     scanf("%ld", &n);

     for(k=1; ithval[k]<=n; k++);
          
          printf("%ld\n", ithval[k-1]);

   }    

 return 0;
}
