#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;

int main(){
	int tc, n, *ar, sum, msum;
	scanf("%d",&tc);
	while(tc--){
		msum = INT_MIN;
		scanf("%d",&n);
		ar = new int[n];
		for(int i=0; i<n; i++)	scanf("%d", ar+i);
		for(int i=0; i<n; i++){		// fixing the index first
			sum = 0;
			for(int l=1; l<=n-i; l++){		// now fixing the length
				sum+=ar[i+l-1];
				if(sum>msum)	msum=sum;
			}
		}
		printf("%d\n",msum);
		delete []ar;
	}
	return 0;
}

// Earlier in the O(n^3) brute force method, we were fixing the length first and finding the sum at different indices
// Now in this brute force method we are first fixing the index and then fixing the length
// Due to this for computing the sum for l+1 length and l length at the same index, we are not computing again from i to i+l again, we are using the precomputed sum
// This is O(n^2) brute force solution
