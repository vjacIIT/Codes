#include<cstdio>
#include<vector>
#include<climits>
using namespace std;

vector<vector<long long>> m;

int main(){
	vector<long long> a, cf; 
	int n,i,d,j,k;
	long long g;
	scanf("%d",&n);
	a = vector<long long>(n);	cf=vector<long long>(n);		
	m=vector<vector<long long>> (n,vector<long long>(n,(long long)1<<60));
	for(i=0; i<n; i++){	scanf("%lld",&a[i]);	m[i][i]=0;	}
	cf[0]=a[0];	for(i=1; i<n; i++)	cf[i]=cf[i-1]+a[i];
	for(d=1; d<n; d++){
		for(i=0; i<n-d; i++){
			j=i+d;
			for(k=i; k<j; k++){
				g=m[i][k]+m[k+1][j]+cf[j]-cf[i]+a[i];
				if(g<m[i][j])	m[i][j]=g;
			}
		}
	}
	printf("%lld\n",m[0][n-1]);
	for(i=0; i<n; i++)	m[i].clear();	a.clear();	cf.clear();
	return 0;
}

// This is O(n^3) solution
// This is dp solution, using matrix chain multiplication
// For any m[i][j] (i.e. i to j), go from i->k then k+1->j, add the penalty for the individual ones and the penalty for adding them (here commulative frequencies)
// Next I will try greedy solution for this in which I will choose min sum pair among them
