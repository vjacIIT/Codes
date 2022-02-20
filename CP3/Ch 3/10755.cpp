#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#include<set>
#include<climits>
#include<iostream>
#include<cmath>
using namespace std;

#define loop(i,n)	for(int i=0; i<n; i++)
#define Loop(i,a,n)	for(int i=a; i<n; i++)
#define newline		printf("\n");
#define scan(n)		scanf("%d",&n)
#define mp			make_pair
#define pb			push_back
#define module		int(1e9+7)

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

int A, B, C;
vector<vvll> m;

int main(){
	int tc, temp;
	ll max_sum;
	scanf("%d",&tc);
	while(tc--){
		max_sum=-2147483648LL;;
		scanf("%d%d%d",&A,&B,&C);
		m = vector<vvll>(A,vvll(B,vll(C)));
		for (int i=0;i<A;++i)
			for (int j=0;j<B;++j)
				for (int k=0;k<C;++k){
				  long long g; cin>>g;
				  if (i>0) g+=m[i-1][j][k];
				  if (j>0) g+=m[i][j-1][k];
				  if (k>0) g+=m[i][j][k-1];
				  if (i>0 && j>0) g-=m[i-1][j-1][k];
				  if (j>0 && k>0) g-=m[i][j-1][k-1];
				  if (i>0 && k>0) g-=m[i-1][j][k-1];
				  if (i>0 && j>0 && k>0) g+=m[i-1][j-1][k-1];
				  m[i][j][k]=g;
				}		
		for (int i=0;i<A;++i) for (int j=0;j<B;++j) for (int k=0;k<C;++k) 
    	for (int i1=i;i1<A;++i1) for (int j1=j;j1<B;++j1) for (int k1=k;k1<C;++k1){
			long long s = m[i1][j1][k1];
			if (i>0) s-=m[i-1][j1][k1];
			if (j>0) s-=m[i1][j-1][k1];
			if (k>0) s-=m[i1][j1][k-1];
			if (i>0 && j>0) s+=m[i-1][j-1][k1];
			if (j>0 && k>0) s+=m[i1][j-1][k-1];
			if (i>0 && k>0) s+=m[i-1][j1][k-1];
			if (i>0 && j>0 && k>0) s-=m[i-1][j-1][k-1];
			if (s>max_sum) max_sum = s;
		}
		printf("%lld\n",max_sum);
		if(tc)
			printf("\n");
	}
	return 0;
}
