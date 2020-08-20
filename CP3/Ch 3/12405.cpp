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
	vb saved;
	int tc, n, cnt, ans;
	char c, str[500];
	scan(tc);
	loop(t,tc){
		scanf("%d\n",&n);
		saved = vb(n+5,false);
		saved[0] = true;
		fgets(str,200,stdin);
		Loop(i,n+1,n+5)
			saved[i] = true;
		loop(i,n){
			c = str[i];
			saved[i+1]= (c=='.' ? false : true);				// if # then already saved
		}
		//loop(i,n)
			//printf("%d",(int)grass[i]);
		//newline;
		cnt=1;
		ans=0;
		while(cnt<=n){
			if(saved[cnt]){
				cnt++;
				continue;
			}
			saved[cnt]=true;
			saved[cnt+1]=true;
			saved[cnt+2]=true;
			cnt+=3;
			ans++;
		}
		printf("Case %d: ",t+1);
		print(ans);
		newline;
	}
	return 0;
}
