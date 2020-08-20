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
	
bool check(){
	loop(i,n-1){
		if(!prime(a[i]+a[i+1]))	return false;
	}
	return prime(a[0]+a[n-1]) ? true:false;
}

int main(){
	int cnt=0, fac, h;
	while(scanf("%d",&n)!=EOF){
		h=0;	fac=1;	loop(i,n-1)	fac*=i+1;
		a = vi(n);	loop(i,n)	a[i]=i+1;
		if(cnt)	newline;	cnt++;
		printf("Case %d:\n",cnt);
		do{
			if(h==fac) break;	h++;
			if(check()){	loop(i,n)	printf("%d ",a[i]);	newline;	}
		}while(next_permutation(a.begin(),a.end()));
	}
	return 0;
}

// This solution got TLE, because it is O((n-1)!) and n<=16
