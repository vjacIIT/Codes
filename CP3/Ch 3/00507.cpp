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
	vi v;
	int r, s, csum, ans, st, ast, aend;
	scan(r);
	loop(rt,r){
		scan(s);
		v = vi(s-1);
		loop(i,s-1)
			scan(v[i]);
		
		st=0;	
		while(v[st]<0)
			st++;
		
		if(st==s-1){
			printf("Route %d has no nice parts\n",rt+1);
			continue;
		}
		ans = -1;
		csum=0;
		Loop(i,st,s-1){
			csum+=v[i];
			if(csum<0){
				csum=0;
				st=i+1;
			}
			if(csum>ans){
				ans=csum;
				ast = st;
				aend = i;
			}
			else if(csum==ans && (i-st)>(aend-ast)){
				ast = st;
				aend = i;
			}
		}
		printf("The nicest part of route %d is between stops %d and %d\n",rt+1,ast+1,aend+2);
	}
	return 0;
}
