#include<vector>
#include<cstdio>
#include<set>
using namespace std;

#define loop(i,n)	for(int i=0; i<n; i++)
#define Loop(i,a,n)	for(int i=a; i<n; i++)
#define mp	make_pair
#define pb	push_back

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int main(){
	int qr, qc, r, c, cnt=0, n, k;
	set<ii> mtx;
	scanf("%d%d",&n,&k);
	scanf("%d%d",&qr,&qc);
	loop(i,k){
		scanf("%d%d",&r,&c);
		mtx.insert(mp(r,c));
	}
	r=qr+1;	c=qc;
	while(r<=n && mtx.find(mp(r,c))==mtx.end()){	cnt++;	r++;	}
	r=qr-1;	c=qc;
	while(r>0 && mtx.find(mp(r,c))==mtx.end()){	cnt++;	r--;	}
	r=qr;	c=qc+1;
	while(c<=n && mtx.find(mp(r,c))==mtx.end()){	cnt++;	c++;	}
	r=qr;	c=qc-1;
	while(c>0 && mtx.find(mp(r,c))==mtx.end()){	cnt++;	c--;	}
	r=qr+1;	c=qc+1;
	while(r<=n && c<=n && mtx.find(mp(r,c))==mtx.end()){	cnt++;	r++;	c++;	}
	r=qr-1;	c=qc-1;
	while(r>0 && c>0 && mtx.find(mp(r,c))==mtx.end()){	cnt++;	r--;	c--;	}
	r=qr+1;	c=qc-1;
	while(r<=n && c>0 && mtx.find(mp(r,c))==mtx.end()){	cnt++;	r++;	c--;	}
	r=qr-1;	c=qc+1;
	while(r>0 && c<=n && mtx.find(mp(r,c))==mtx.end()){	cnt++;	r--;	c++;	}
	printf("%d\n",cnt);
	return 0;
}

// We cannot use matrix as it's space complexity will be too high
