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
#define mp			make_pair
#define pb			push_back
#define module		int(1e9+7)

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

struct help{
	int wt, s, idx;
};

bool mycompare(help &a, help &b){
	return a.wt < b.wt;
}

int n;

void solve(){
	int ans=0;
	cin>>n;
	vector<help> vc = vector<help>(n);
	loop(i,n){
		scan(vc[i].wt);
		vc[i].idx = i;
	}
	loop(i,n)
		scan(vc[i].s);
	
	sort(vc.begin(),vc.end(),mycompare);
	int lastIndex = vc[0].idx;
	int currIndex = 1;
	while(currIndex<n){
		while(vc[currIndex].idx<=lastIndex){
			vc[currIndex].idx+=vc[currIndex].s;
			ans++;
		}
		lastIndex = vc[currIndex].idx;
		currIndex++;
	}
	cout<<ans<<endl;
}

int main(){
	int t;
	cin>>t;
	loop(i,t)
		solve();
	return 0;
}
