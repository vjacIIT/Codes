// This problem is under dp category but I don't know how to solve using dp

#include<cstdio>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

#define loop(i,n)	for(int i=0; i<n; i++)
#define Loop(i,a,n)	for(int i=a; i<n; i++)
#define scan(n)		scanf("%d",&n);
#define mp	make_pair
#define pb	push_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<bool> vb;

int find(int cnt);
int cal(int val, int nt);

vi a, d;
int n;

int main(){
	int tc, Min, ans, sum;
	scan(tc);
	while(tc--){
		Min=INT_MAX;	ans=INT_MAX;
		scan(n);
		a=vi(n);	d=vi(n);
		loop(i,n){	scan(a[i]);	Min=min(Min,a[i]);	}
		loop(t,5){						// 5 different targets
			sum=0;
			loop(i,n){	
				d[i]=a[i]-Min+t;	
				sum+=d[i]/5;	sum+=(d[i]%5)/2;
				sum+=(d[i]%5)%2;
			}
			ans=min(sum,ans);
		}
		printf("%d\n",ans);
	}
	return 0;
}

// Greedy Method
// What we did is: there can be 5 targets we can reach from given vector a
// Either make all to min, min-1, min-2, min-3 or min-4
// To reach each of these targets we have just used the formula
// Take the max no of steps for 5, then of 2 and at last of 1
// We take the min number of steps from these targets
