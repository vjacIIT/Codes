#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
#include<cmath>
#include<climits>
#include<iostream>
using namespace std;

#define loop(i,n)	for(int i=0; i<n; i++)
#define Loop(i,a,n)	for(int i=a; i<n; i++)
#define newline		printf("\n")
#define scan(n)		scanf("%d",&n)
#define print(n)	printf("%d",n)
#define mp	make_pair
#define pb	push_back
const int Mod = 1e9+7;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<vb> vvb;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int n;
vvi matrix;
vi work;

int kadane(){
	int ans=INT_MIN, csum=0;
	loop(i,n){
		csum+=work[i];
		ans=max(ans,csum);
		if(csum<0)
			csum=0;
	}
	return ans;
}

int main(){
	int ans=INT_MIN;
	scan(n);
	matrix = vvi(n,vi(n));
	loop(i,n)
		loop(j,n)
			scan(matrix[i][j]);
	
	loop(l,n){
		work = vi(n,0);
		Loop(r,l,n){
			loop(w,n)
				work[w]+=matrix[r][w];			
			ans=max(ans,kadane());
		}
	}
	print(ans);
	newline;
	return 0;
}

// Idea: Sum for every rectangle lying b/w l to r is calculated, column sum is stored in work array 
// then kadane is used on work array to find max sum subarray (here matrix)
// As it is done for every l to r, it covers all the rectangle in the matrix
