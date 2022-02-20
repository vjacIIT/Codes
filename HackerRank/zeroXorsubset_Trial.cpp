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

int mcount;
vvi answer(10000000);

int power(int a, int b){
	int h;
	if(b==0)
		return 1;
	if(b%2)
		return a*power(a,b-1);
	else{
		h = power(a,b/2);
		return h*h;
	}
}

// Given numbers from 0 to n-1, find number of subsets with Xor = 0
void countXor(int n, string str){					
	int cnt=0;
	if(n==0){
		loop(i,str.size()){
			if(str[i]=='1')
				cnt=cnt^i;
		}
		if(cnt==0){
			loop(i,str.size()){
				if(str[i]=='1')
					answer[mcount].pb(i);
			}
			mcount++;
		}
		return;
	}
	countXor(n-1,str+'0');				// don't take n'th number
	countXor(n-1,str+'1');				// take n'th number
	return;
}

int main(){
	int t, n;
	scan(t);
	while(t--){
		mcount=0;
		scan(n);
		countXor(power(2,n),"");
		printf("number of zero subsets %d\n",mcount);
		loop(i,mcount){
			loop(j,answer[i].size())
				printf("%d ",answer[i][j]);
			newline;
			answer[i].clear();
		}
	}
	return 0;
}
// This program helps to find the solution
// Number of subsets = 2^(2^n - n)
