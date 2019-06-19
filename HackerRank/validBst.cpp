#include<iostream>
using namespace std;

int n,*ar;

int findIndexGreater(int ind){
	for(int i=ind+1; i<n; i++){
		if(ar[i]>ar[ind])	return i;
	}
	return n;		// all values are smaller than the current ar[ind]
}

bool validBst(){
	int find;
	for(int i=0; i<n-1; i++){
		find = findIndexGreater(i);		// Gives the index of the first number greater than ar[i]
		for(int j=find; j<n; j++){		// all numbers at index >= this index must be greater than ar[i] 
			if(ar[i]>ar[j])	return false;
		}
	}
	return true;
}

int main(){
	bool vbst;
	int tc;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		ar = new int[n];
		for(int i=0; i<n; i++)	scanf("%d",ar+i);
		vbst = validBst();
		if(vbst)	printf("YES\n");
		else	printf("NO\n");
		delete []ar;
	}
	return 0;
}

// This program is O(n^2), can be done in O(nlogn) by making a tree and using the same logic

