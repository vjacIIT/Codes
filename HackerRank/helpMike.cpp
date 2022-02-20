#include<bits/stdc++.h>
    
using namespace std;
    
int main(){
    int T;
    long long int N,K,i;
    scanf("%d",&T);
    while(T--)
    {
        cin>>N>>K;
        long long int arr[K];
        arr[0] = N/K;
        for(i=1 ; i< K ; i++)
            arr[i] = (int)(N-i)/K + 1;
        if(K%2!=0)
        {
            long long int sum = 0;
            sum  = sum + (arr[0]*(arr[0] - 1))/2;
            for(i=1 ; i<=K/2 ; i++)
            {
                sum = sum + arr[i]*arr[K-i];
            }
            cout<<sum<<endl;
        }
        else
        {
            long long int sum = 0;
            sum  = sum + (arr[0]*(arr[0] - 1))/2;
            for(i=1 ; i< K/2 ; i++)
            {
                sum = sum + arr[i]*arr[K-i];
            }
            sum = sum + (arr[K/2]*(arr[K/2] - 1))/2;
            cout<<sum<<endl;
        }
    }
    return 0;
}
// ar[i] stores the number of numbers in [1,n] with remainder i
// Now, the sum of two integers is divisible by K if:
//		a. BOth the numbers are divisible by k
//		b. If one has remainder p and other has K-p
