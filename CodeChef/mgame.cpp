#include<bits/stdc++.h>
using namespace std;

int main(){
	long int n, p, t, max, cnt;
	cin>>t;
	while(t--){
		cin>>n;	cin>>p;
		max = (n-1)/2;
		if(max!=0)	cnt = (p-max)*(p-max)+(p-n)*(2*p-max-n);
		else	cnt = p*p*p;
		cout<<cnt<<"\n";
	}
	return 0;
}
