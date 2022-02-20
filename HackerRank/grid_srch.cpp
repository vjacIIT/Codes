#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

#define loop(i,n)	for(int i=0; i<n; i++)
#define Loop(i,a,n)	for(int i=a; i<n; i++)
#define mp	make_pair
#define pb	push_back

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<vi> vvi;

int main(){
	bool flg1, flg2;
	vvi big, sm;
	char str[2000];
	int tc, R, C, r, c;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d%d\n",&R,&C);
		big=vvi(R,vi(C));
		loop(i,R){
			scanf("%s\n",str);
			loop(j,C)	big[i][j]=str[j]-'0';
		}
		scanf("%d%d",&r,&c);
		sm=vvi(r,vi(c));
		loop(i,r){
			scanf("%s\n",str);
			loop(j,c)	sm[i][j]=str[j]-'0';
		}
		
		loop(i,R-r+1){
			loop(j,C-c+1){
				flg1=true;
				Loop(k,i,i+r){
					Loop(w,j,j+c){
						if(big[k][w]!=sm[k-i][w-j]){
							flg1=false;	break;
						}
					}
					if(!flg1)	break;
				}
				if(flg1)	break;
			}
			if(flg1)	break;
		}
		flg1==true	? printf("YES\n"):printf("NO\n");
	}
	return 0;
}

// It worked, it is a brute force solution
// Even R,r,C,c<=1000, it worked don't know why
