/*
	Problem: Given an array a, find the longest increasing subsequence
	Solution:
			1. DP O(n^2)
					Find Lis[i] (length of longest increasing subsequence ending at a[i]) for each element at take the max out of it.
					Algorithm -> Lis[i] = max(1+Lis[j]) where j<i and a[j]<a[i]

			2. DP O(nlogn)
					Find Lis[i] (stores index of min possible value of last element of increasing subsequence of lenght i)
					, means from all increasing subsequence of length i Lis[i] stores the index of min value out of the last elements
					Find prt[i] (stores the index of parent value of each element in the array a)
					Algorithm:
						1. Tranverse in the array a and check if the a[i] > curr
						2. YES: prt[i] = Lis[l-1]  (l is length of Lis), Append i in Lis, curr = a[Lis[l]]
							, if current element is greater than current last value in Lis, means we can add i (index) in Lis to increase the length of subsequence
						3. NO: then do binary search on values at the indices stored in Lis and put index i at the ceil of a[i]
							ind = binary_search(values from Lis), Lis[ind] = i, prt[i] = prt[ind]
					Finally the max Lis length is length of longest increasing subsequence
					Use parents to find the actual increasing subsequence
*/

#include<cstdio>
#include<vector>
#include<iostream>
#include<climits>
using namespace std;

int n;
vector<int> Lis, arr, Lis_val, prt;				// Lis_val stores the values inside the Lis

int bSearch(int st, int end, int val){
	if(st>end)
		return st;								// return ceil
	int m = (st+end)>>1;
	if(Lis_val[m]==val)
		return m;
	else if(Lis_val[m]<val)
		return bSearch(m+1,end,val);
	else
		return bSearch(st,m-1,val);
}

void printSequence(int ind){
	if(ind==-1)
		return;
	printSequence(prt[ind]);
	printf("%d ",arr[ind]);
	return;
}

int main(){
	int curr, l, ind;							// l is current length of Lis
	scanf("%d", &n);
	arr = vector<int>(n);
	prt = vector<int>(n,-1);
	for(int i=0; i<n; i++)
		scanf("%d", &arr[i]);
	
	curr = INT_MIN;
	l = 0;
	for(int i=0; i<n; i++){
		if(arr[i]>curr){					// length of Lis increased
			l == 0 ? prt[i]=-1 : prt[i]=Lis[l-1];
			l++;
			Lis.push_back(i);
			Lis_val.push_back(arr[i]);		// inserting values for binary search
		}
		else{
			ind = bSearch(0, l-1, arr[i]);
			prt[i]=prt[Lis[ind]];
			Lis[ind] = i;
			Lis_val[ind] = arr[i];
		}
		curr=arr[Lis[l-1]];
	}
	printf("Length of longest increasing subsequence: ");
	printf("%d\n",l);
	printSequence(Lis[l-1]);
	printf("\n");
	return 0;
}

