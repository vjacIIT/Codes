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

int n, m, bud;
vi w;

// <int,int> ==== first = area size, second = budget
ii kadane(int alen){
	ii ans = ii(INT_MIN,INT_MIN);
	int clen=0, csum=0, carea;
	loop(i,n){
		csum+=w[i];
		clen++;
		// in the budget
		if(csum	<= bud){
			carea = clen*alen;
			if(carea>ans.first){
				ans.first = carea;
				ans.second = csum;
			}
			else if(carea==ans.first && csum<ans.second){
				ans.second=csum;
			}
		}
		// exceeds the budget, decrease the clen 1 by 1
		else{
			while(csum>bud){
				csum-=w[i+1-clen];
				clen--;
			}
			if(csum	<= bud){
				carea = clen*alen;
				if(carea>ans.first){
					ans.first = carea;
					ans.second = csum;
				}
				else if(carea==ans.first && csum<ans.second){
					ans.second=csum;
				}
			}
		}
	}
	return ans;
}

int main(){
	int tc;
	ii ans;
	scan(tc);
	loop(t,tc){
		ans = ii(INT_MIN, INT_MIN);
		scanf("%d%d%d",&n,&m,&bud);
		vvi ground = vvi(n,vi(m));
		loop(i,n){
			loop(j,m){
				scan(ground[i][j]);
				if(j)
					ground[i][j]+=ground[i][j-1];	
			}
		}
		loop(l,m){
			Loop(r,l,m){
				w = vi(n);
				loop(k,n){
					w[k]=ground[k][r]-(l>0 ? ground[k][l-1] : 0);
				}
				ii o = kadane(r-l+1);
				if(o.first > ans.first){
					ans.first = o.first;
					ans.second= o.second;
				}
				else if(o.first==ans.first && o.second<ans.second)
					ans.second=o.second;
			}
		}
		printf("Case #%d: %d %d\n",t+1,ans.first, ans.second);
		
	}
	return 0;
}

// Idea is to do a maximum sum subarray while saving the size and sum as well
// If sum exeeds the budget, decrease the sum by decreasing the size of the array 1 by 1