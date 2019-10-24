//Goldbach's conjecture :any EVEN integer can be represented as sum of two prime numbers (not necesarry distinct)

#include<iostream>
using namespace std;

bool is_prime(long long int n){
    if(n<=3)    return n>1;
    else if(n%2==0 || n%3==0)    return false;
    long long int i=5;
    while(i*i<=n){
        if(n%i==0 || n%(i+2)==0)    return false;	// 3 numbers are checked here, rest 3 are checked due to divisibility by 2 and 3
        i=i+6;				// therefore directly add 6
    }
    return true;
}

int main(){
    bool p;
    long long int n,k;
    int tc;
    scanf("%d",&tc);
    while(tc--){
        scanf("%ld%ld",&n,&k);
        if(n==1)    printf("No\n");
        else{
            if(k==1){
                p = is_prime(n);
                if(p)    printf("Yes\n");
                else    printf("No\n");
            }
            else if(k==2){
                if(n%2==0 && n!=2)  printf("Yes\n");
                else{
                    p = is_prime(n-2);
                    if(p)    printf("Yes\n");
                    else    printf("No\n");
                }
            }
            else{
                if(n>=2*k)    printf("Yes\n");
                else    printf("No\n");
            }
        }
    }
    return 0;
}

// This program is uptill now my best to check if a number is prime or not, it is faster than sqrt(n)
// is_prime takes 6 steps at a time
