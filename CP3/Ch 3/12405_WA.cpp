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
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<vb> vvb;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int main(){
	vb grass;
	int tc, n, cnt, ans, an;
	char c, str[500];
	scan(tc);
	loop(t,tc){
		scanf("%d\n",&n);
		an = n;
		if(n%3==1)
			an+=2;
		else if(n%3==2)
			an++;
		
		grass = vb(an+1,false);
		fgets(str,200,stdin);
		loop(i,n){
			c = str[i];
			grass[i+1]= (c=='.' ? true : false);
		}
		//loop(i,n)
			//printf("%d",(int)grass[i]);
		//newline;
		cnt=2;
		ans=0;	
		while(cnt<an){
			if(grass[cnt] || grass[cnt-1] || grass[cnt+1])
				ans++;
			cnt+=3;
		}
		printf("Case %d: ",t+1);
		print(ans);
		newline;
	}
	return 0;
}

// This approach is wrong, it puts scarecrow on 2...5...8...12.....
// And then removes all the scarecrow which has all left, itself and right not required
// It fails on ##..
// My strategy gives 2, correct answer 1
