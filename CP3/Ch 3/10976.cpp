#include<cstdio>
#include<vector>
using namespace std;

#define loop(i,n)	for(int i=0; i<n; i++)
#define mp	make_pair
#define pb	push_back

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int gcd(int s, int b){
	if(s==0)	return b;
	return gcd(b%s,s);
}

int main(){
	vii a;
	int l, y, n, f, num, den;
	while(scanf("%d",&n)!=EOF){
		for(int y=n+1; y<=2*n; y++){
			num=y-n;	den=n*y;
			f=gcd(num,den);
			num/=f;		den/=f;
			if(num==1)	a.pb(mp(den,y));		
		}
		l=a.size();		printf("%d\n",l);
		loop(y,l)	printf("1/%d = 1/%d + 1/%d\n",n,a[y].first,a[y].second);
		a.clear();
	}
	return 0;
}
