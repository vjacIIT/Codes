#include<stdio.h>
int main()
{
 int n, i, j, rm, div;
 char a[1000][50]={'\0'};
 int ar[54]={0};

 scanf("%d", &n);
     for(i=0; i<n; i++)  
     {
           for(j=0; j<50; j++)
           {
                scanf("\n%c", &a[i][j]);
           }
     }


   ar[0]=0;  ar[1]=0; ar[2]=0; ar[3]=0;
      for(i=0; i<50; i++)
      {    ar[i+4]=0;
           for(j=0; j<n; j++)
           {
              ar[i+4]+=((int)a[j][i]-48);
           }
      }
 
      for(i=0; i<54; i++)
      {
         printf("%d\t", ar[i]);  
      }
  
      printf("\n\n");

      for(i=53; i>=1; i--)
      {
         
         rm=ar[i]%10 ;
         div=ar[i]/10 ;
         ar[i-1]+=div;
         ar[i]=rm;  
      }
      
      

      printf("\n\n\n");
     
      for(i=0; i<54; i++)
      {
         printf("%d\t", ar[i]);  
      }
  
      printf("\n\n");
 
     for(i=0; i<5; i++)
     {
         
         if(ar[i]!=0)
         {
             for(j=i; j<=i+9; j++){
             printf("%d", ar[j]);
                                  }
             printf("\n");
             return 1;
         }
      
     }

     printf("\n");

 return 0;
}
