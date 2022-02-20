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

vi arr, idx, prt, ans;

int bsearch(int no, int s, int e){
	if(s>e)
		return s;
	
	int mid = (s+e)>>1;
	if(ans[mid]==no)
		return mid;
	else if(ans[mid]>no)
		return bsearch(no, s, mid-1);
	else
		return bsearch(no, mid+1, e);
}

int main(){
	int n=1, alen=0, ind, no;
	arr.pb(INT_MIN);
	prt.pb(-1);
	while(scanf("%d",&no)!=EOF){
		arr.pb(no);
		prt.pb(-1);
		n++;
	}
	ans.pb(INT_MIN);
	idx.pb(-1);
	Loop(i,1,n){
		if(arr[i]>ans[alen]){
			ans.pb(arr[i]);
			idx.pb(i);
			prt[i]=idx[alen];
			alen++;
		}
		else{
			ind = bsearch(arr[i], 1, alen);
			ans[ind]=arr[i];
			idx[ind]=i;
			prt[i]=idx[ind-1];
		}
	}
	ans.clear();
	printf("%d\n-\n",alen);
	ind = idx[alen];
	while(ind!=-1){
		ans.pb(arr[ind]);
		ind = prt[ind];
	}
	loop(i,alen)
		printf("%d\n",ans[alen-i-1]);
	return 0;
}

// LIS with O(nlog(k)) time. k is the size of LIS
