#include<bits/stdc++.h>
using namespace std;

int *ar;

int mx(int a, int b){
	if(a>b)	return a;
	return b;
}

int cut(int l, int a, int b, int c){
	int x, y, z;
	if(l<0)	return -40000;
	if(l==0)	return 0;
	if(ar[l]>0)		return ar[l];
	
		x= cut(l-a, a, b, c);
		y= cut(l-b, a, b, c);
		z= cut(l-c, a, b, c);
		x = mx(x, mx(y, z));	
		ar[l]=x+1;
		return ar[l];
}

int main(){
	int n, a, b, c;
	cin>>n>>a>>b>>c;
	ar = new int[n+5];
	for(int i=0; i<=n; i++)	ar[i]=-1;
	a = cut(n, a, b, c);
	cout<<a<<endl;
}
