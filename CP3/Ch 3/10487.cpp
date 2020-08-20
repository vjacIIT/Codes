#include<cstdio>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

#define loop(i,n)	for(int i=0; i<n; i++)
#define mp	make_pair
#define pb	push_back

typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vi a;

int search(int st, int end, int no){
	int md=(st+end)>>1;
	if(st>end)	return st;			// element just bigger than no
	if(a[md]==no)	return md;
	else if(a[md]>no)	return search(st,md-1,no);
	else	return search(md+1,end,no);
}

int main(){
	int n, cno=1, i, q, sum, idx, no, ans, j, diff;
	while(scanf("%d",&n)!=EOF){
		if(n==0)	break;
		a=vi(n);
		loop(i,n)	scanf("%d",&a[i]);
		sort(a.begin(),a.end());
		scanf("%d",&q);
		printf("Case %d:\n",cno++);
		loop(i,q){
			diff=INT_MAX;
			scanf("%d",&sum);
			loop(j,n){
				no=a[j];
				idx=search(0,n-1,sum-no);
				if(idx!=0 && (idx-1)!=j){
					if(diff>abs(sum-(no+a[idx-1]))){
						diff=abs(sum-(no+a[idx-1]));
						ans=no+a[idx-1];
					}
				}
				if(idx!=n && idx!=j){
					if(diff>abs(sum-(no+a[idx]))){
						diff=abs(sum-(no+a[idx]));
						ans=no+a[idx];
					}
				}
			}
			printf("Closest sum to %d is %d.\n",sum,ans);
		}
		a.clear();
	}
	return 0;
}

// For each query we can find all the pair sum and find the closest O(n^2)
// Here we are using binary search for each query assuming first number to be a[j], which makes it O(nlogn)
// Hence overall time complexity is O(mnlog(n))
