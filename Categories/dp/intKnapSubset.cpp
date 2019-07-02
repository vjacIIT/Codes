// Concept is just take the element or not
// This program forms all the subsets and take the best out of that
// Time complexity is O(2^n)

#include<bits/stdc++.h>
using namespace std;

int n;
int *w;
int *p;

int mx(int p1, int p2){
	if(p1>p2)	return p1;
	return p2;
}

int pft(int c, int ind){
	int p1, p2;	
	if(c<0)	return -p[ind-1];		// means we cannot include last profit
	if(ind==n)	return 0;
	p1 = pft(c,ind+1);		// we do not include object
	p2 = pft(c-w[ind],ind+1)+p[ind];	// we include the object
	return mx(p1,p2);
}	

int main(){
	int mp, c;
	cin>>n;
	cin>>c;
	w = new int[n];
	p = new int[n];
	for(int i=0; i<n; i++)	cin>>w[i];
	for(int i=0; i<n; i++)	cin>>p[i];
	mp = pft(c,0);
	cout<<mp<<endl;	
	return 0;
}
