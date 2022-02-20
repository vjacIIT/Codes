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

int n;
vi lis, arr, lds;

int main(){
	int tc, l1, l2;
	scan(tc);
	loop(t, tc){
		scan(n);
		lis = vi(n,1);
		lds = vi(n,1);
		arr = vi(n);
		loop(i,n)
			scan(arr[i]);
		for(int i=n-2; i>=0; i--){
			for(int j=n-1; j>i; j--){
				if(arr[i]<arr[j] && lis[i]<=lis[j])
					lis[i]=lis[j]+1;
			}
		}
		for(int i=n-2; i>=0; i--){
			for(int j=n-1; j>i; j--){
				if(arr[i]>arr[j] && lds[i]<=lds[j])
					lds[i]=lds[j]+1;
			}
		}
		int ans=0;
		for(int i=0; i<n; i++)
			ans=max(lis[i]+lds[i]-1, ans);
		printf("%d\n",ans);
	}
	return 0;
}

/*	
	If we add i'th index car in train, then we only can add cars with weight > i'th on the right and weight < i'th on the left of it
	Hence ans = max(LIS[i] + LDS[i] - 1)
	LIS = Longest increasing subsequence starting with i'th car, LDS = Longest decreasing subsequence starting with i'th car
*/