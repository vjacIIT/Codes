#include<cstdio>
using namespace std;

int power(int n){
	int hf;
	if(n==0)	return 1;
	if(n%2==0){
		hf = power(n/2);
		return hf*hf;
	}
	else	return 2*power(n-1);
}

int main(){
	int n, pn, *wt, *nbr, max_sum;
	while(scanf("%d",&n)!=EOF){
		pn = power(n);
		wt = new int[pn];	nbr=new int[pn];
		for(int i=0; i<pn; i++){	scanf("%d",wt+i);	nbr[i]=0;	}
		for(int i=0; i<pn; i++){
			for(int j=0; j<n; j++)	nbr[i]+=wt[i^(1<<j)];		// potency,	stores sum of its neighbours
		}
		max_sum=-1;				// for each index we sum it's value + it's neighbour value, for each index and each neighbour
		for(int i=0; i<pn; i++){
			for(int j=0; j<n; j++)	if(max_sum<nbr[i]+nbr[i^(1<<j)])	max_sum=nbr[i]+nbr[i^(1<<j)];
		}
		printf("%d\n",max_sum);	delete []wt;	delete []nbr;
	}
	return 0;
}

// Flip the index for getting the neighbour
// After finding sum of it's neighbour for each corner, we need to iterate over all the vertices and it's neighbour to find best possible sum
