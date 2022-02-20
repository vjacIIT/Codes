// Given two Strings a and b, we can do two changes in a :
// 1. Capitalize zero or more of a's lowercase letters
// 2. Delete all of it's remaining lowercase letters in a

// Can we make a=b by using just these operations

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
typedef vector<vb> vvb;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int main(){
	bool upperCase;
	char a[2000], b[2000];
	vvb dp;
	int q, la, lb;
	scan(q);	scanf("\n");
	loop(nt,q){
		upperCase=false;
		scanf("%s",a);	scanf("%s",b);	la=strlen(a);	lb=strlen(b);
		dp=vvb(la+1,vb(lb+1,false));	dp[0][0]=true;
		loop(i,la){				// b is empty and a has any upperCase letter
			if(upperCase || a[i]==toupper(a[i])){
				upperCase=true;
				dp[i+1][0]=false;
			}
			else	dp[i+1][0]=true;
		}
		loop(i,la){
			loop(j,lb){
				if(a[i]==b[j])	dp[i+1][j+1]=dp[i][j];										// if a[i] is uppercase and matches with b[j]
				else if(toupper(a[i])==b[j])	dp[i+1][j+1]=dp[i][j] || dp[i][j+1];		// I was missing this, was doing if(toupper(a[i])==b[j])---> wrong
				else if(toupper(a[i])==a[i])	dp[i+1][j+1]=false;							// uppercase but still doesn't matches
				else	dp[i+1][j+1]=dp[i][j+1];											// lowecase, doesn't matches, just discard it
			}
		}
		if(dp[la][lb])	printf("YES\n");
		else	printf("NO\n");
	}
	return 0;
}

// this problem is a tricky one of longest common subsequence
// We cannot remove the Capitals in A
