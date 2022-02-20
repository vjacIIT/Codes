#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#include<set>
#include<climits>
#include<iostream>
#include<cmath>
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
typedef vector<vb>	vvb;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vll> vvll;

vi vsum;

// if size(the maximum sum subarray in vsum) <=n great
// otherwise do it for every i=0 to n-1
int sizeCheck=0;

// from which index to start and how many steps to go in vsum array
int kadane(int st, int tsize){
	int csum=0, csize=0, ans=INT_MIN;
	Loop(i,st,tsize+st){
		csum+=vsum[i];
		csize++;
		if(csum > ans){
			ans=csum;
			sizeCheck=csize;
		}
		if(csum<0){
			csum=0;
			csize=0;
		}
	}
	return ans;
}


int main(){
	int tc, n, maxSum, ans;
	scan(tc);
	while(tc--){
		ans=INT_MIN;
		scan(n);
		vvi matrix = vvi(2*n,vi(2*n+1,0));
		loop(i,n){
			Loop(j,1,n+1){
				scan(matrix[i][j]);
				loop(x,2)
					loop(y,2)
						matrix[i+n*x][j+n*y] = matrix[i][j];
			}
		}

		loop(i,2*n)
			Loop(j,1,2*n+1)
				matrix[i][j]+=matrix[i][j-1];

		Loop(l,1,n+1){
			Loop(r,l,l+n){
				vsum = vi(2*n,0);
				sizeCheck=0;
				loop(i,2*n)
					vsum[i]=matrix[i][r]-matrix[i][l-1];
				// if the maximum sum subarray has size <= n
				maxSum = kadane(0,2*n);
				if(sizeCheck<=n){
					if(maxSum > ans)
						ans=maxSum;
				}
				else{
					loop(i,n){
						maxSum = kadane(i,n);
						if(maxSum > ans)
							ans=maxSum;		
					}
				}
			}
		}
		printf("%d\n",ans);
	}

	return 0;
}

// main idea is to make 2n*2n matrix then do kadane on it
// but make sure that the size of subarray of maximum sum <= n
