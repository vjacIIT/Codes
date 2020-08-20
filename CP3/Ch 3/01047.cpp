#include<cstdio>
#include<vector>
using namespace std;

#define loop(i,n)	for(int i=0; i<n; i++)
#define Loop(i,a,n)	for(int i=a; i<n; i++)
#define pb	push_back
#define mp	make_pair

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii>	vii;
typedef vector<vi>	vvi;
typedef vector<bool> vb;

int Lbit(int i){
	return i&(-i);			// gives the least significant set bit
}

int count(int i){
	int n=0;
	for(; i>0; i-=Lbit(i))	n++;
	return n;
}

int main(){
	vi t, ins_cal, cal;
	int tl, n, m, ni, z, sum, mx, tmp, best, tc=0, a, b;							
	while(scanf("%d%d",&tl,&n)!=EOF){		// total and actually built
		if(tl==0 && n==0)	break;
		t=vi(tl);	loop(i,tl)	scanf("%d",&t[i]);
		
		scanf("%d",&m);					// total number of intersections
		ins_cal=vi(m,0);		cal=vi(m);
		loop(i,m){
			scanf("%d",&ni);			// number of intersecting zones
			loop(j,ni){
				scanf("%d",&z);	z--;
				ins_cal[i]|=(1<<z);		// zones taking part in intersection
			}
			scanf("%d",&cal[i]);		// intersection value
		}
		
		mx=-1;
		loop(i,(1<<tl)){					// all subsets
			if(count(i)==n){				// actually build
				sum=0;
				loop(j,tl){
					if(i&(1<<j))	sum+=t[j];	// if we have that zone
				}
				loop(j,m){					// removing intersecting zones
					tmp=count(ins_cal[j]&i);
					if(tmp>1)	sum-=(tmp-1)*cal[j];
				}
				if(sum>mx){
					best=i;
					mx=sum;
				}
				else if(sum==mx){			// we need to take the min zone no
					loop(k,tl){
						a=(i&(1<<k));
						b=(best&(1<<k));
						if(a!=b){
							if(a>0)	best=i;	
						}
						break;
					}
				}
			}
		}
		printf("Case Number  %d\n",++tc);
		printf("Number of Customers: %d\nLocations recommended:",mx);
		loop(i,tl){
			if(best&(1<<i))
				printf(" %d",i+1);
		}
		printf("\n\n");	t.clear();	ins_cal.clear();	cal.clear();
	}
	return 0;
}

// This code is copied by me from pspencil@github, this was very hard problem for me
// Hard in the sense for thinking for implementation, what to do was fine but how to do was not clear
// Most important thing is that it has a lot of bit manipulation as well as thinking
