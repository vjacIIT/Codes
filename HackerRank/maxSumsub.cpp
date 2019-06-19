#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;

int main(){
	int tc, n, *ar, sum, ans;
	scanf("%d", &tc);
	while(tc--){
		ans = INT_MIN;
		scanf("%d",&n);
		ar = new int[n];
		for(int i=0; i<n; i++)	scanf("%d",ar+i);
		sum = 0;
		for(int i=0; i<n; i++){
			sum+=ar[i];
			if(sum>ans)	ans=sum;		// if current sum > maximum sum, update maximum sum
			if(sum<0)	sum=0;
		}
		printf("%d ",ans);				// maximum continous sum subarray
		sort(ar,ar+n,greater<int>());
		sum = ar[0];
        for(int i=1; i<n; i++){
            if(sum+ar[i]>sum)    sum+=ar[i];
            else break;
        }
        printf("%d\n",sum);
		delete []ar;
	}
}

// This is O(n), dp solution
// If sum comes out to be -ve, update sum=0
