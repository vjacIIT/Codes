// Given an integer n we need to print all its subset

#include<bits/stdc++.h>
using namespace std;

bool *vis;	// maintains the visited part of the elements
int n;

void prtSub(int i){		// takes the index 
	if(i==n){
		for(int i=0; i<n; i++){		// takes O(n) time to print all the subsets
			if(vis[i]==true)	cout<<i<<" ";
		}
		cout<<endl;	
		return;		// reached end	
	}
	vis[i]=false;		// element not choosen
	prtSub(i+1);
	vis[i]=true;		// choosen	
	prtSub(i+1);	
	return;
} 

int main(){
	cin>>n;
	vis = new bool[n];
	for(int i=0; i<n; i++)	vis[i]=false;
	prtSub(0);
	return 0;
}
