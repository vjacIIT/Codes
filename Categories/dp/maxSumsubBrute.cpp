#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;

int main(){    
    int n, *ar, sum, msum, tc;
    scanf("%d",&tc);
    while(tc--){
        msum = INT_MIN;
        scanf("%d",&n);
        ar = new int[n];
        for(int i=0; i<n; i++)    scanf("%d",ar+i);
        for(int l=1; l<=n; l++){        // finding for all the lengths
            for(int i=0; i<=n-l; i++){        // starting from indices
                sum = 0;
                for(int j=i; j<i+l; j++)    sum+=ar[j];        // travelling through the array for sum
                if(sum>msum)    msum=sum;
            }
        }
        printf("%d\n",msum);
        delete []ar;
    }
    return 0;
}

// This is O(n^3)
// Brute force for finding max sum subarray (subarrays are continuous, different from subsequences) at all the lengths
