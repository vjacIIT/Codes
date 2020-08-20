#include<cstdio>
#include<vector>
using namespace std;

#define loop(i,n)	for(int i=0; i<n; i++)
#define mp	make_pair
#define pb	push_back

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vi bit;

int Lbit(int i){
	return i&(-i);
}

void update(int i, int val){
	for(; i<=5000; i+=Lbit(i))	bit[i]+=val;
	return;
}

int fsum(int i){
	int sum=0;
	for(; i>0; i-=Lbit(i))	sum+=bit[i];
	return sum;	
}

int main(){
	int tc, n, i, no, sum, ans;
	scanf("%d",&tc);
	while(tc--){
		ans=0;
		scanf("%d",&n);
		bit=vi(5001,0);
		loop(i,n){
			scanf("%d",&no);
			sum=fsum(no);
			ans+=sum;	update(no,1);
		}
		printf("%d\n",ans);
		bit.clear();
	}
	return 0;
}

// We can do this problem using 2 loops, but we have done this problem using BIT
// Time complexity is O(n*log(5001)), which is better than O(n^2)
// We can still improve it to O(n*log(n)), (i.e. n<=1000), by storing the different elements and their count only
