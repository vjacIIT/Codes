#include<bits/stdc++.h>
using namespace std;

int func(int k){
	for(int i=1; i<=10; i++){
		if(i+i*i>k)	return i-1;
		else if(i+i*i==k)	return i;
	}
}

int main(){
	int n, k;
	cin>>n>>k;
	k = (2*(240-k))/5;
	k = func(k);
	if(k>n)	cout<<n<<endl;
	else	cout<<k<<endl;
	return 0;
}
