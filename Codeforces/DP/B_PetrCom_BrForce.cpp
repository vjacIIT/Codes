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

int main(){
	bool flg=false;
	int n, sum;
	scan(n);	a = vi(n);
	loop(i,n)	scan(a[i]);
	loop(i,1<<n){
		sum=0;
		loop(j,n){
			if(i&(1<<j))	sum+=a[j];
			else	sum-=a[j];
			sum+=360;	sum%=360;	
		}
		if(!sum)	flg=true;
		if(flg)	break;
	}
	if(flg)	printf("YES\n");
	else	printf("NO\n");
	return 0;
}

// Brute Force solution
