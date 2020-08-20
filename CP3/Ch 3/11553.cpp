/*
Problem milds up to this (taken from red green code):
Given a grid of random integers, pick one number from each row such that the sum of your selected numbers is as small as possible, and no two of your numbers are from the same column.
*/

// Alice has no control over game as she has to choose all the rows
// Everything depends on Bob, how he chooses col to reduce the score

#include<cstdio>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

#define loop(i,n)	for(int i=0; i<n; i++)
#define Loop(i,a,n)	for(int i=a; i<n; i++)
#define mp	make_pair
#define pb	push_back

typedef long long ll;
typedef vector<int>	vi;
typedef pair<int,int> ii;
typedef vector<ii>	vii;
typedef vector<bool> vb;
typedef vector<vi> vvi;

int main(){
	vi col;
	vvi m;
	int tc, val, Min, n;
	scanf("%d",&tc);
	while(tc--){
		Min=INT_MAX;
		scanf("%d",&n);
		m=vvi(n,vi(n));		col=vi(n);
		loop(i,n){
			col[i]=i;
			loop(j,n)	scanf("%d",&m[i][j]);
		}
		do{
			val=0;
			loop(i,n)	val+=m[i][col[i]];
			Min=min(Min,val);
		}while(next_permutation(col.begin(),col.end()));				
		// each value is the column number from each row we have taken
		// Ex- col=[3,1,2,4], we took col 3 for row 1, col 1 for row 2, col 2 for row 3 and col 4 for row 4
		printf("%d\n",Min);
		loop(i,n)	m[i].clear();	col.clear();
	}
}

// There is a dp solution for this also

