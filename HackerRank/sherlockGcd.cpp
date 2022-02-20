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
typedef pair<ll,ll> llll;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<vb> vvb;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<llll> vllll;

int gcd(int a, int b){
	if(a==0)
		return b;
	else
		return gcd(b%a,a);
}

int main(){
	int tc, d, g, n;
	scan(tc);
	while(tc--){
		scan(n);
		loop(i,n){
			scan(d);
			if(!i)
				g=d;
			else
				g = gcd(g,d);
		}
		if(g==1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
