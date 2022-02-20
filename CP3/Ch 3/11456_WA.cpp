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
vi lis;

int bsearch(int st, int end, int no){
	if(st>end)
		return st;
	int mid = (st+end)>>1;
	if(lis[mid]==no)
		return mid;
	else if(lis[mid]>no)
		return bsearch(st, mid-1, no);
	else
		return bsearch(mid+1, end, no);
}

int LIS(vi arr){
	int maxLen = 0, ind;
	lis.clear();
	lis.pb(-1);
	loop(i,n){
		if(lis[maxLen]<arr[i]){
			lis.pb(arr[i]);
			maxLen++;
		}
		else{
			ind = bsearch(0,maxLen-1,arr[i]);
			lis[ind]=arr[i];
		}
	}
	return maxLen;
}

int main(){
	int tc, l1, l2;
	scan(tc);
	loop(t, tc){
		scan(n);
		vi arr, arr2;
		//printf("number of cars %d\n",n);
		arr = vi(n);
		arr2 = vi(n);
		loop(i,n)
			scan(arr[i]);
		loop(i, n)
			arr2[i]=arr[n-1-i];
		l1 = LIS(arr);
		l2 = LIS(arr2);
		printf("%d\n", l1>l2 ? l1:l2);
	}
	return 0;
}

/* 
	Wrong Approach 1
		Making a 2*n array with n+1 to 2*n elements to be in reverse of arr
		Then find the LIS in this 2*n array as answer
		WA on - 3 2 0 1, Got 4 but the ac answer is 3
*/

/*
	Wrong Approach 2
		Thought of find LIS in arr and reverse of arr
		Whichever is bigger will be the answer
		WA on - 1 0 3 2, Got 2 but the ac answer is 3
*/