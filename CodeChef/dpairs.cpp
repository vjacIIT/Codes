#include<bits/stdc++.h>
using namespace std;

int bsrch(int *ar, int a, int st, int end){
	int mid = (st+end)/2;
	if(st>end)	return st;
	if(ar[mid]==a)	return mid+1;
	else if(ar[mid]>a)	return bsrch(ar, a, st, mid-1);
	else	return bsrch(ar, a, mid+1, end);
}

int main(){
	int *ar1, *ar2, n, m, ind=0, cnt=0, sr, min, imin=0, imax=0, max;
	cin>>n;	cin>>m;
	ar1 = new int[n];
	ar2 = new int[m];
	for(int i=0; i<n; i++)	cin>>ar1[i];
	for(int i=0; i<m; i++)	cin>>ar2[i];
	min=ar1[0];
	for(int i=0; i<n; i++){
		if(min>ar1[i]){
			min=ar1[i];
			imin=i;
		}
	}
	max=ar2[0];
	for(int i=0; i<m; i++){
		if(max<ar2[i]){
			max=ar2[i];
			imax=i;
		}
	}
	for(int i=0; i<m; i++)	cout<<imin<<" "<<i<<endl;
	for(int j=0; j<n; j++)	if(j!=imin)	cout<<j<<" "<<imax<<endl;
	return 0;
}
