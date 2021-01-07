/*
	2 water jugs of size m,n are given
	We can fill up any jar, empty any jar and pour water from one to another untill one gets full or other gets empty
	Find min no of operations required to get k litres of water
*/

#include<cstdio>
#include<climits>
#include<cmath>
#include<iostream>
using namespace std;

int m, n, k;

int gcd(int a, int b){
	if(a==0)
		return b;
	return gcd(b%a,a);
}

int minOperation(int fromCap, int toCap){
	int from=fromCap, to=0, temp, noSteps=1;		// 1 step to fill f
	while(from!=k && to!=k){
		temp = min(from,toCap-to);					// amount to be transfered
		to+=temp;
		from-=temp;
		noSteps++;
		if(from==k || to==k)
			break;
		if(from==0){
			from=fromCap;
			noSteps++;
		}
		if(to==toCap){
			to=0;
			noSteps++;
		}
	}
	return noSteps;
}

int minOp(){
	if(m>n)
		swap(m,n);					// hence n is always bigger now

	int g=gcd(m,n);
	if(k%g!=0 || k>n)
		return -1;					// not possible

	return min(minOperation(m,n),minOperation(n,m));
}

int main(){
	scanf("%d%d%d",&m,&n,&k);
	printf("%d\n",minOp());
	return 0;
}

/*
	First k has to be multiple of gcd(m,n) because mx + ny = k, has solutions only in that case
	Now either fill m bucket first or fill n bucket first and take min of these 2
	do these:
		1. Fill the bucket and pour into another
		2. If one is empty fill it up, if other one is full empty it
		3. Do untill either of them gets k liters of water
*/
