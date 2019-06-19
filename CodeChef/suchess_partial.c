#include <stdio.h>
#include <stdlib.h>

int comparator(const void *p1, const void *p2)
{
	int a =*(int*)p1;
	int b=*(int*)p2;
	return a-b; 
}

int binarySearch(int *ar, int st, int end, int key)
{
	int mid;
	if(st>end)
		return -1;
	else if(st==end)
	{
		if(ar[st]<key)
			return st+1;
		else 
			return st;
	}
	mid = (st+end)/2;
	if(ar[mid]==key)
		return mid;
	else if(ar[mid]>key)
		return binarySearch(ar, st, mid-1, key);
	else
		return binarySearch(ar, mid+1, end, key);
}

int function(int *ar, int key, int min)
{
	if(key>=min*min)
		return min;
		
	int i = binarySearch(ar, 0, min, key);
	for(int j=i; j<min; j++)
	{
		if(key<ar[j])
			return j;
	}
	return min;
}

int main()
{
      int N, M, min, q, no;
      scanf("%d%d", &N, &M);     // M is the length of each row (number of columns)
      char *car;
      car = (char*)malloc(M*sizeof(char));

      int  **arr, ***matcom1, ***matcom2;
      int *count, ct1=0, ct2=0, cnt1=0, cnt2=0, flag=0;
      min = N;
      if(min>M)
            min = M;
      
      matcom1=(int***)malloc(min*sizeof(int**));
      matcom2=(int***)malloc(min*sizeof(int**));
      for(int i=0; i<min; i++)
      {
      	matcom1[i]=(int**)malloc((i+1)*sizeof(int*));
      	matcom2[i]=(int**)malloc((i+1)*sizeof(int*));
      	for(int j=0; j<=i; j++)
      	{
      		matcom1[i][j]=(int*)malloc((i+1)*sizeof(int));
      		matcom2[i][j]=(int*)malloc((i+1)*sizeof(int));
      		for(int k=0; k<=i; k++)
      		{
      			matcom1[i][j][k]=(k+j)%2;
      			matcom2[i][j][k]=(k+j+1)%2;		
      		}	
      	}
      	
      }
            
      
      arr = (int**)malloc(N*sizeof(int*));
	count = (int*)malloc(min*sizeof(int));
	for(int i=0; i<min; i++)
		count[i]=10000;
	
	for(int i=0; i<N; i++)
		arr[i]=(int*)malloc(M*sizeof(int));
      
      for(int i=0; i<N; i++)
      {
            scanf("%s", car);
            for(int j=0; j<M; j++)
            {
                  arr[i][j]=car[j]-48;
            }
      }
      
      for(int i=0; i<min; i++)
      {
      	flag=0;
      	for(int j=0; j<N-i; j++)
      	{
      		for(int k=0; k<M-i; k++)
      		{
      			for(int l=0; l<=i; l++)
      			{
      				for(int w=0; w<=i; w++)
      				{
      					ct1=matcom1[i][l][w]-arr[j+l][k+w];
      					ct2=matcom2[i][l][w]-arr[j+l][k+w];
      					if(ct1<0)
      						cnt1+=-ct1;
      					else
      						cnt1+=ct1;
      					if(ct2<0)
      						cnt2+=-ct2;
      					else
      						cnt2+=ct2;
      				}
      			}	
      			if(cnt1<count[i])
      				count[i]=cnt1;
      			if(cnt2<count[i])
      				count[i]=cnt2;
      			cnt1=0;
      			cnt2=0;
      			if(count[i]==0)
      			{
      				flag==1;
      				break;
      			}
      		}
      	if(flag==1)
      		break;
      	}
      }
      
      /*for(int i=0; i<min; i++)
      	printf("%d ", count[i]);
      printf("\n");*/
      
      scanf("%d", &q);
 
      for(int i=0; i<q; i++)
      {
      	scanf("%d", &no);
      	no=function(count, no, min);
      	printf("%d\n", no);
      }
    return 0;
}
