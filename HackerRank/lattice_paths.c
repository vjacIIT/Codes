#include<stdio.h>
int no = 1000000007;

 int main()
{
 long long int a[501][501];
 int i, j, r, c, tc;

   for(i=0; i<500; i++)
   {
      a[i][500]=1;
      a[500][i]=1;
   }

   a[500][500]=0;
   

   for(i=499; i>=0; i--)
   {
       for(j=499; j>=0; j--)
       {
           a[i][j]=(a[i+1][j]+a[i][j+1])%(no);
       }
   }

/*   for(i=0; i<=500; i++)
   {
       for(j=0; j<=500; j++)
       {
           printf("%lld ",a[i][j]);
       }
     printf("\n");
   }
*/
 
    scanf("%d", &tc);
  
   for(i=0; i<tc; i++)
  {
   scanf("%d %d", &r, &c);

   printf("%lld\n",a[500-r][500-c]);
  }  

 return 0;
}
