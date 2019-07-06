#include<cstdio>
#include<vector>
using namespace std;

vector<long long> a, bit;
int n;

int Lbit(int i){
	return i&(-i);
}

void update(int i, long long val){
	for(; i<=n; i+=Lbit(i))	bit[i]+=val;
	return;
}

void build(){
	for(int i=1; i<=n; i++)	update(i,a[i]);
	return;
}

long long fsum(int i){
	long long sum=0;
	for(; i>0; i-=Lbit(i))	sum+=bit[i];
	return sum;
}

int main(){
	long long no, ivl;
	char c;
	int q, neg, l, r;
	while(scanf("%d%d",&n,&q)!=EOF){
		a = vector<long long>(n+1);
		bit = vector<long long>(n+1);
		for(int i=1; i<=n; i++){
			scanf("%lld",&no);
			if(no==0)	a[i]=100*n;
			else if(no>0)	a[i]=1;
			else	a[i]=-1;
		}
		build();
		scanf("\n");
		for(int i=0; i<q; i++){
			scanf("%c %d %d\n",&c,&l,&r);
			if(c=='P'){
				no = fsum(r)-fsum(l-1);
				ivl = r-l+1;
				if(no>ivl)	printf("0");
				else{
					neg = (ivl-no)/2;
					if(neg%2==0)	printf("+");
					else	printf("-");
				}
			}
			else{
				update(l,-a[l]);
				if(r>0){	update(l,1);	a[l]=1;	}
				else if(r<0){	update(l,-1);	a[l]=-1;	}
				else{	update(l,100*n);	a[l]=100*n;	}
			}
		}
		printf("\n");
		a.clear();	bit.clear();
	}
	return 0;
}
