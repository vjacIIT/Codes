// Given an integer as a string, find the sum of all it's substrings cast as integers

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
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int main(){
	char str[1000000];
	int l, dig;
	ll ones=0, sum;
	scanf("%s",str);		l=strlen(str);
	ones=0;		sum=0;
	loop(i,l){
		dig=str[l-i-1]-'0';
		ones*=10;	ones++;		ones%=MOD;
		sum+=(ll)dig*(ll)(l-i)*ones;	sum%=MOD;
	}
	printf("%lld\n",sum);
	return 0;
}


// There will be n*(n+1)/2 substrings
// We need to find frequency and position of each digit in each substring
// (1's indexing) for i'th digit (dig), freq=i and positions=(n-i+1) different positions starting from Unit's place, hence multiply by 111111...(n-i+1) times
