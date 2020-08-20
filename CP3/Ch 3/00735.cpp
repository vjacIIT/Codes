#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

#define loop(i,n)	for(int i=0; i<n; i++)
#define mp	make_pair
#define pb	push_back
#define ins	insert

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<ii> vii;


int main(){
	set<iii> s;
	int n, l, sum, per;
	vi a, h(3);
	loop(i,61){
		if(i<=20)	a.pb(i);
		else if(i<=40){
			if(i%2==0 || i%3==0)	a.pb(i);
		}
		else{
			if(i%3==0 || i==50)	a.pb(i);
		}
	}
	l=a.size();
	while(scanf("%d",&n)!=EOF){
		if(n<=0){	printf("END OF OUTPUT\n");	break;	}
		per=0;
		loop(i,l){
			loop(j,l){
				loop(k,l){
					sum=a[i]+a[j]+a[k];
					if(sum==n){
						h[0]=a[i];	h[1]=a[j];	h[2]=a[k];
						sort(h.begin(),h.end());
						s.ins(mp(h[0],mp(h[1],h[2])));
						per++;
					}	
				}
			}
		}
		sum=s.size();
		if(per!=0){
			printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n",n,sum);
			printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n",n,per);
		}
		else	printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n",n);
		printf("**********************************************************************\n");
		s.clear();
	}
	return 0;
}
