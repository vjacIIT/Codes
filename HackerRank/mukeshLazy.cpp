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

vi evenPerSq(1e6+6,0);				// count of even perfect square divisors of i
vi countFactor(1e6+6,1);			// count of total perfect divisors of i, 1 is divisors of all

bool perSquare(int n){
	int i = sqrt(n);
	return i*i==n ? true : false;
}

void preCal(){
	Loop(i,2,1e6){
		for(int j=2; (ll)i*j<=1e6; j++){
			countFactor[i*j]++;						// all multiples of i
			if(i%2==0 && perSquare(i))
				evenPerSq[i*j]++;
		}
	}
	return;
}

int gcd(int a, int b){
	if(b%a==0)
		return a;
	return gcd(b%a,a);
}

int main(){
	preCal();										// takes O(nlogn)
	int tc, n, p, q;
	scan(tc);
	while(tc--){
		scan(n);
		p = evenPerSq[n];
		q = countFactor[n];
		if(p==0)
			printf("0\n");
		else{
			n = gcd(p,q);
			p/=n;
			q/=n;
			printf("%d/%d\n",p,q);
		}
	}
	return 0;
}
