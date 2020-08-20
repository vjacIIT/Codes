// Given an array of n numbers from 1 to n in random order, we can pick any 3 diff indices
// Now we can swap them in cyclic order, we need to find min number of operations required to sort them if possible
// Also print the order of operations done


// So the idea is to find the cycle, means at a[1] = 3, then at a[3] = 4, a[4] = 7 and a[7] = 1 ---> this is a 4 cycle
// Odd cycles can be solved
// If there are even no of even cycles, then there is a solution else not possible

#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
#include<cmath>
#include<climits>
#include<iostream>
using namespace std;

#define loop(i,n)	for(int i=0; i<n; i++)
#define Loop(i,a,n)	for(int i=a; i<n; i++)
#define newline		printf("\n")
#define scan(n)		scanf("%d",&n)
#define print(n)	printf("%d",n)
#define mp	make_pair
#define pb	push_back
const int Mod = 1e9+7;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<ll,ll> llll;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<vb> vvb;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<llll> vllll;

int main(){
	int triplets[100000][3];
	int doublets[100000][2];
	vi a, cycle;
	vb vis;
	int tc, cnt, temp, t, d, n, k;
	scan(tc);
	while(tc--){
		t = 0;
		d = 0;
		scan(n);
		scan(k);
		a = vi(n+1,0);
		vis = vb(n+1,false);
		Loop(i,1,n+1)
			scan(a[i]);
		Loop(i,1,n+1){
			if(a[i]!=i && !vis[i]){
				vis[i]=true;
				cnt = 1;
				temp = a[i];
				cycle.pb(i);
				while(temp!=i){
					vis[temp]=true;
					cycle.pb(temp);
					temp = a[temp];
					cnt++;
				}
				temp=0;										// cnt stores the size of cycle
				while(temp<cnt-2){
					triplets[t][0] = i;
					triplets[t][1] = cycle[temp+1];
					triplets[t][2] = cycle[temp+2];
					temp+=2;
					t++;
				}
				if(cnt%2==0){								// even length cycle, hence 2 indices left
					doublets[d][0] = i;
					doublets[d][1] = cycle[cnt-1];
					d++;
				}
				cycle.clear();
			}
		}
		if(k<t+d || d%2==1)									// odd doublets cannot be sorted
			printf("-1\n");
		else{
			printf("%d\n",t+d);
			loop(i,t)
				printf("%d %d %d\n",triplets[i][0],triplets[i][1],triplets[i][2]);
			temp=0;
			while(temp<d){
				printf("%d %d %d\n",doublets[temp][0],doublets[temp][1],doublets[temp+1][0]);
				printf("%d %d %d\n",doublets[temp][0],doublets[temp+1][1],doublets[temp+1][0]);
				temp+=2;
			}
		}
	}
	return 0;
}
