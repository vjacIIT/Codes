// Given an array of integers, find the subset of non-adjacent elements with maximum sum

#include<cstdio>
using namespace std;

int big(int a, int b){
	int large;
	large = a>b ? a:b;
	return large;
}

int main(){
	int n, *ar, *incl, *excl;		// stores current max[i], current max[i-1]
	scanf("%d",&n);
	ar = new int[n];				
	incl = new int[n];
	excl = new int[n];
	for(int i=0; i<n; i++)	scanf("%d",ar+i);
	excl[0]=0;		incl[0]=big(ar[0],excl[0]);						
	for(int i=1; i<n; i++){
		incl[i]=big(ar[i]+excl[i-1],incl[i-1]);
		excl[i]=incl[i-1];
	}
	printf("%d\n",incl[n-1]);
	for(int i=n-1; i>=0; i--){
		if(incl[i]!=excl[i]){		// means we have taken that element
			printf("%d ",ar[i]);
			i--;					// we cannot take the previous element
		}
	}
	printf("\n");
	delete []ar;
	delete []incl;
	delete []excl;
	return 0;
}

// NOTE: Inclusion array doesn't mean that we have to take the current number. It stores the current maximum at index i, with or without the i'th element
// Exclusion stores the (i-1)'th maximum 
