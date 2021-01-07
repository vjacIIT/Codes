/*
	An array of elements (size of array is even), either we take the first or the last element
	We win if we generate more elements values than our opponent. We start first
	Give the elements to take to win the game
*/

#include<cstdio>
#include<vector>
#include<iostream>
using namespace std;

int main(){
	vector<int>v;
	int n, oddSum=0, evenSum=0;
	cin>>n;
	v = vector<int>(n);
	for(int i=0; i<n; i++){
		cin>>v[i];
		if(i%2)
			oddSum+=v[i];
		else
			evenSum+=v[i];
	}
	if(oddSum<evenSum){
		for(int i=0; i<n; i+=2)
			cout<<v[i]<<" ";
		cout<<endl;
	}
	else{
		for(int i=1; i<n; i+=2)
			cout<<v[i]<<" ";
		cout<<endl;
	}
	return 0;
}

/*
	Find the sum of elements at odd and even indices
	If oddSum>evenSum, print all even index elements
	Else print all odd index elements
*/
