#include<iostream>
using namespace std;

bool *svd;

int findleft(int l){
	for(int i=l-1; i>=0; i--)	if(svd[i])	return i;
	
}

int findright(int r, int n){
	for(int i=r+1; i<=n+1; i++)	if(svd[i])	return i;
}

int main(){
	int n, b, l, r;
	while(scanf("%d%d",&n,&b)!=EOF){
		if(n==0 && b==0)	break;
		svd = new bool[n+2];	for(int i=0; i<n+2; i++)	svd[i]=true;
		for(int i=0; i<b; i++){
			scanf("%d%d",&l,&r);
			for(int i=l; i<=r; i++)	svd[i]=false;
			l=findleft(l);		r=findright(r,n);
			l==0 ? printf("* "):printf("%d ",l);
			r==n+1 ? printf("*\n"):printf("%d\n",r);
		}
		printf("-\n");
		delete []svd;
	}
}

// TLE, because each time we are passing through the whole array
