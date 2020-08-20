#include<cstdio>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

#define loop(i,n)	for(int i=0; i<n; i++)
#define pb	push_back
#define mp	make_pair

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii>	vii;
typedef vector<double>	vd;

int main(){
	int mn, mx, m;
	char str[250];
	vvi a;
	while(scanf("%d\n",&m)!=EOF){
		a=vvi(m,vi(m));
		loop(i,m){
			fgets(str,200,stdin);
			loop(j,m)	a[i][j]=str[j]-'0';
		}
		mx=-1;
		loop(i,m){
			loop(j,m){
				if(a[i][j]==1){					// start from position 1
					mn=INT_MAX;
					loop(x,m){
						loop(y,m){
							if(a[x][y]==3)	mn=min(mn,abs(y-j)+abs(x-i));
						}
					}
					mx=max(mx,mn);
				}
			}
		}
		printf("%d\n",mx);
		loop(i,m)	a[i].clear();	a.clear();
	}
	return 0;
}
