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
typedef vector<vb>	vvb;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int row[8];			// row number for column i
vvi v(92,vi(8));
int cnt=0;

bool check(int r, int c){
	int rd, cd;
	loop(i,c){
		if(row[i]==r)	return false;
		rd = abs(row[i]-r);		cd = abs(i-c);
		if(rd==cd)	return false;
	}
	return true;
}

void dfs(int i){		// filling the i'th column
	if(i==8){	
		loop(j,8)	v[cnt][j]=row[j];	
		cnt++;
		return;
	}
	loop(j,8){					// j stores the row number
		if(check(j,i)){
			row[i]=j;
			dfs(i+1);
		}
	}
	return;
}

int main(){
	int d, h, r[8], cse=0;
	char str[200];
	dfs(0);
	while(scanf("%d%d%d%d%d%d%d%d",&r[0],&r[1],&r[2],&r[3],&r[4],&r[5],&r[6],&r[7])!=EOF){
		d = INT_MAX;	cse++;
		loop(j,8)	r[j]-=1;
		loop(i,92){
			h=0;
			loop(j,8)	h+= r[j]!=v[i][j] ? 1:0 ;
			d = min(d,h);
		}
		printf("Case %d: %d\n",cse,d);
	}
	return 0;
}
