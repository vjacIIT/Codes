#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
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

int main(){
	vi a;
	int n, Min, sum=0, k, ans;
	scan(n);	scan(k);
	a = vi(n);
	loop(i,n)	scan(a[i]);
	loop(i,k)	sum+=a[i];
	Min = sum;	ans=1;
	Loop(i,1,n-k+1){
		sum-=a[i-1];	sum+=a[i+k-1];
		if(sum<Min){
			Min = sum;	ans=i+1;
		}
	}
	printf("%d\n",ans);
	return 0;
}
