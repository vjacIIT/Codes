#include<vector>
#include<cstdio>
using namespace std;

int main(){
	vector<long long> a;
	vector<long long>::iterator it;
	int n,i;
	long long penalty=0, g;
	g=scanf("%d",&n);
	a = vector<long long>(n);
	for(i=0; i<n; i++)	g=scanf("%lld",&a[i]);
	while(a.size()>1){
		g=(long long)1<<60;	it=a.begin();
		for(i=0; i<a.size()-1; i++)	if((a[i]+a[i+1])<g)	g=a[i]+a[i+1];
		penalty+=g;
		for(i=0; i<a.size()-1; i++)	if((a[i]+a[i+1])==g)	break;
		it+=i;	(*it)=g;	it++;	it=a.erase(it);
	}
	printf("%lld\n",penalty);
	return 0;
}

// This greedy approach gives wrong answer, but I don't have test cases in which it is wrong
// Approach is to find the min current sum of a[i]+a[i+1], add and replace with sum
// Correct approach is to use matrix chain multiplication
// dp[i][j]=min(dp[i][k]+dp[k+1][j]+penalty for adding) for all k between i and j-1
