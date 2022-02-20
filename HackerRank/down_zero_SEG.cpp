#include<cstdio>
#include<map>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

vector<int> dp(1000005,10000);
vector<int> v;

void fFactor(int n){
	for(int i=2; i*i<=n; i++){
		if((n%i)==0)
			v.push_back(n/i);
	}
	return;
}

void fMinSteps(int n){
	printf("Here for n %d\n",n);
	int b;
	if(dp[n]!=10000)
		return;
	
	v.clear();
	fFactor(n);										// find all factors
	for(int i=0; i<v.size(); i++){
		b = v[i];
		fMinSteps(b);
		dp[n] = min(dp[n],dp[b]+1);
	}
	fMinSteps(n-1);									// THIS line causes problem
	dp[n] = min(dp[n],dp[n-1]+1);
	return;
}
int main(){
	int q, n;
	scanf("%d",&q);
	while(q--){
		scanf("%d",&n);
		dp[0] = 0;
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 3;
		fMinSteps(n);
		printf("%d\n",dp[n]);
	}
	return 0;
}

// Solution idea is right, but as it is calling recursion again and again, stack cannot store this much
// Also solution finds all the factors of n, try doing it with precomputation

/*

#include<cstdio>
#include<vector>
using namespace std;

vector<int> v;

void findFactors(int n){
	for(int i=2; i*i<=n; i++)
		if((n%i)==0)
			v.push_back(n/i);
	return;
}

int main(){
	int qMax = 1000005, b, q;
	int dp[qMax];
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	for(int i=4; i<qMax; i++){
		v.clear();
		findFactors(i);
		dp[i] = dp[i-1]+1;
		for(int f=0; f<v.size(); f++){
			b = v[f];
			dp[i] = min(dp[i],dp[b]+1);
		}
	}
	scanf("%d",&q);
	while(q--){
		scanf("%d",&b);
		printf("%d\n",dp[b])
	}
	return 0;
}
*/

// This is exact same solution above with no function call, it works only for q = 10^5
// Because time complexity is O(nsqrt(n))
