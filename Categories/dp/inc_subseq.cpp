#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, *ar, *arl, *ari, *arm, ind, mx;
	cin>>n;
	ar = new int[n];
	arl = new int[n];			// stores the current maximum length for that element in index i
	ari = new int[n];			// stores the index of the last element which caused the length to increase by 1 (for backtrack)
	for(int i=0; i<n; i++)		cin>>ar[i];
	for(int i=0; i<n; i++)		arl[i]=1;
	for(int i=0; i<n; i++)		ari[i]=-1;
	
	// Main thing is to remember the total number of elements that are smaller than the current i'th element and also in increasing order
	for(int i=1; i<n; i++){
		for(int j=0; j<i; j++){
			if(ar[j]<ar[i] && arl[i]<=arl[j]+1){
				arl[i]=arl[j]+1;
				ari[i]=j;
			}
		}
	}
	mx=-1;
	ind =-1;
	for(int i=0; i<n; i++){
		if(mx<arl[i]){
			mx=arl[i];
			ind = i;
		}
	}
	arm = new int[n];
	for(int i=mx-1; i>=0; i--){
			arm[i]=ar[ind];
			ind = ari[ind];
	}
	
	for(int i=0; i<mx; i++)	cout<<arm[i]<<" ";
	cout<<"\n";
	return 0;
}
