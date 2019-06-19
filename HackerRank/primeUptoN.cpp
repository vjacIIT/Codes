// Sieve of Eratosthenes
// Assumes all numbers to be prime and then wipe out the non-prmes one by one

#include<iostream>
using namespace std;

bool p[1000000];

bool isPrime(int n){
	for(int i=2; i*i<=n; i++){
		if(n%i==0)	return false;
	}
	return true;
}

int main(){
	for(int i=0; i<1000000; i++)	p[i]=true;			// assuming all numbers are prime
	p[0]=false;
	p[1]=false;
	for(int i=2; i*i<=1000000; i++){
		for(int j=2; i*j<1000000; j++)	p[i*j]=false;
	}
	for(int i=0; i<1000000; i++){
		if(p[i])	printf("%d\t",i);
	}
	printf("\n");
	return 0;
}

//Every no which is not prime is being wiped out by one of it's factor, but if it has a divisor then maximum value of that will be sqrt(n), hence outer loop is till sqrt(n)

// Time complexity is O(nloglogn), space complexity is O(n)
// If we use isPrime then that will take O(n^3/2) time
