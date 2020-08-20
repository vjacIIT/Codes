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

vi a;
int n;

bool prime(int k){
	if(k==1 || k%2==0)	return false;
	for(int i=3; i*i<=k; i+=2)	if(k%i==0)	return false;
	return true;	
}

void backtrack(int idx, int mask){
	if(idx==n){
		if(prime(a[0]+a[n-1])){	
			loop(i,n){
				if(i)	printf(" ");
				printf("%d",a[i]);
			}
			newline;
		}
		return;
	}
	loop(i,n){
		if(!(mask&(1<<i)) && prime(a[idx-1]+i+1)){
			a[idx]=i+1;
			backtrack(idx+1,mask|(1<<i));
		}
	}
	return;
}

int main(){
	int cse=0;
	while(scanf("%d",&n)!=EOF){
		if(cse)	newline;	cse++;
		printf("Case %d:\n",cse);
		a = vi(n);	loop(i,n)	a[i]=i+1;
		if(n>1)	backtrack(1,1);		// first index remains the same
		else	printf("1\n");
	}
	return 0;
}
