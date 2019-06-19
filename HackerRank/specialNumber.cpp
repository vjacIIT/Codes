#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

string s[8192];
long long int ar[8192];
int cnt=0;

void number(string str, int depth){
    if(depth==13){
        s[cnt]=str;
        return;
    }
    number(str+"9",depth+1);
    cnt++;
    number(str+"0",depth+1);
    return;
}

long int findMultiple(int n){
    for(int i=0; i<cnt; i++){
        if(ar[i]%n==0)    return ar[i];
    }
    return 0;
}

int main(){
    int tc,n;
    number("",0);
    for(int i=0; i<cnt; i++)    ar[i]=stol(s[i]);
    sort(ar,ar+cnt);
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&n);
        printf("%ld\n",findMultiple(n));
    }
    return 0;
}

//Finds the nearest mulitple of n which has 0's and 9's only
//It finds all the possible 0's and 9's upto 10^13, then sort and compares
