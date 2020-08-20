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
typedef vector<int> vi;
typedef vector<vi>	vvi;
typedef vector<bool> vb;

int dis(int i, int j, int o){
	int r=o/5, c=o%5;
	return (abs(i-r)+abs(j-c));
}

int fmin(int i, int j, int o1, int o2, int o3, int o4, int o5){
	int mn=INT_MAX;
	mn=min(mn,dis(i,j,o1));	mn=min(mn,dis(i,j,o2));	mn=min(mn,dis(i,j,o3));
	mn=min(mn,dis(i,j,o4));	mn=min(mn,dis(i,j,o5));	return mn;	
}

int main(){
	vvi m;
	vi ans(5);
	int tc, n, r, c, v, d, sum;
	scanf("%d",&tc);
	while(tc--){
		m=vvi(5,vi(5,0));
		scanf("%d",&n);
		loop(i,n){
			scanf("%d%d%d",&r,&c,&v);
			m[r][c]=v;
		}
		d=INT_MAX;
		Loop(o1,0,21){
			Loop(o2,o1+1,22){
				Loop(o3,o2+1,23){
					Loop(o4,o3+1,24){
						Loop(o5,o4+1,25){
							sum=0;
							loop(i,5){
								loop(j,5){
									if(m[i][j])	sum+=m[i][j]*fmin(i,j,o1,o2,o3,o4,o5);
								}
							}
							if(d>sum){	
								d=sum;	ans[4]=o5;
								ans[0]=o1;	ans[1]=o2;	ans[2]=o3;	ans[3]=o4;
							}
						}
					}
				}
			}
		}
		loop(i,5){
			m[i].clear();
			if(i)	printf(" ");
			printf("%d",ans[i]);
		}
		printf("\n");	m.clear();
	}
	return 0;
}

// This problem can be done using backtracking, i.e. without these Loops at all, using recursive function
