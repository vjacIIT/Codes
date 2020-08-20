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
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<vb> vvb;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int main(){
	unsigned int n, l, u, mmax, mmin, ans, temp, ibit;
	while(scanf("%d%d%d",&n,&l,&u)!=EOF){
		mmax = ~n;
		ans=0;
		for(int i=31; i>=0; i--){
			temp = ans|(1<<i);
			ibit = mmax&(1<<i);
			if(temp<=l)
				ans=temp;
			else if(ibit && temp<=u)
				ans=temp;			
		}
		printf("%u\n",ans);
	}
	return 0;
}
