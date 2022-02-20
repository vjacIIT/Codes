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
	ll dp[1000000], l, sum=0;
	char str[1000000];
	scanf("%s",str);	l=(ll)strlen(str);
	dp[0]=str[0]-'0';	sum+=dp[0];
	Loop(i,1,l){
		dp[i]=(i+1)*(str[i]-'0') + dp[i-1]*10;
		dp[i]%=MOD;
		sum+=dp[i];
	}
	printf("%lld\n",sum%MOD);
	return 0;
}

// DP solution
// dp[i], stores the sum of value of all substrings ending at digit[i]
// Now two cases arise, whether to take (i-1)'th index digit or not
// If yes then we add (dp[i-1]*10 + digit[i]*i) ---> {digit[i] comes in all previous substrings}
// Else we have only one length substrings i.e. digit[i], hence formula comes\
// dp[i]= dp[i-1]*10 + i*digit[i] + digit[i];
