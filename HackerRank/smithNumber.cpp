#include<iostream>
using namespace std;

int function(int  cn){
    int sum=0;
    while(cn!=0){
        sum+=cn%10;
        cn=cn/10;
    }
    return sum;
}

int main(){
    int n, sump=0, sum;
    scanf("%d",&n); 
    sum = function(n);
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            while(n%i==0){
                sump+=function(i);
                n=n/i;
            }
        }
    }
    if(n!=1)    sump+=function(n);
    //printf("%d\n",sump);
    if(sump==sum)   printf("1\n");
    else    printf("0\n");
    return 0;
}

