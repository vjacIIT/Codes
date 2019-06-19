#include<iostream>
using namespace std;

 long int p[15];

bool isprime(long int a){
    for(int i=2; i*i<=a; i++){
        if(a%i==0)  return false;
    }
    return true;
}

int bsearch(int st, int end, long int n){
    int mid = (st+end)/2;
    if(st>end)	return st;
    else if(p[mid]==n)  return mid+1;
    else if(p[mid]>n)   return bsearch(st,mid-1,n);
    else    return bsearch(mid+1,end,n);
}

int main(){
    long int n;
    int cnt=1,q;
    p[0]=2;
    n=3;
    while(cnt<20){
        if(isprime(n)){
            p[cnt]=n;
            cnt++;
        }
        n++;
    }
    for(int i=1; i<15; i++)  p[i]=p[i-1]*p[i];
    scanf("%d",&q);
    while(q--){
        scanf("%ld",&n);
        if(n>614889782588491410)	printf("15\n");
        else{
        	cnt = bsearch(0,15,n);
       		printf("%d\n",cnt);
       	}
    }
    return 0;
}

