#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#include<map>
#include<set>
#include<climits>
#include<iostream>
using namespace std;

#define loop(i,n)	for(int i=0; i<n; i++)
#define Loop(i,a,n)	for(int i=a; i<n; i++)
#define newline		printf("\n");
#define scan(n)		scanf("%d",&n)
#define mp	make_pair
#define pb	push_back
#define MOD 1000000007

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<bool> vb;
typedef vector<vb>	vvb;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vll> vvll;

vi a;
int n;
map<int,int> m;

/*
int findindex(int i, int v){
	for(int j=0; j<i; j++){
		if(a[j]==v)	return j;
	}
}

This find index causes program to work in O(n^2)

*/

int findindex(int v){
	return m[v];
}

// Map helps in O(nlog(n)) of the code
// Can do it in O(n), make a position array

int main(){
	int swp=0;
	scan(n);
	a = vi(n);
	loop(i,n){
		scan(a[i]);
		m[a[i]]=i;							// map[a[i]] is the index
	}
	for(int i=n-1; i>=0; i--){
		auto it = m.find(i+1);				// find the index of a[i] in array
		if(a[i]==i+1)	continue;
		swp++;
		a[it->second]=a[i];
		m[a[i]]=it->second;
		m[i+1]=i;
		a[i]=i+1;
	}
	printf("%d\n",swp);
	return 0;
}
