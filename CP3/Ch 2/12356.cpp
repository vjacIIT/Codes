#include<cstdio>
#include<vector>
using namespace std;

struct node{
	int l, r;
};

int main(){
	vector<node> svd;			// left and right index which are saved
	int n, b, l, r;
	while(scanf("%d%d",&n,&b)!=EOF){
		if(n==0 && b==0)	break;
		svd = vector<node>(n+2);	
		svd[0].l=0;		svd[0].r=1;		
		svd[n+1].l=n;	svd[n+1].r=n+1;
		for(int i=1; i<n+1; i++){	svd[i].l=i-1;	svd[i].r=i+1;	}
		for(int i=0; i<b; i++){
			scanf("%d%d",&l,&r);
			svd[svd[l].l].r=svd[r].r;		svd[svd[r].r].l=svd[l].l;
			svd[l].l==0 ? printf("* "):printf("%d ",svd[l].l);
			svd[r].r==n+1 ? printf("*\n"):printf("%d\n",svd[r].r);
		}
		printf("-\n");
		svd.clear();
	}
	return 0;
}

// Like Doubly linked list, joining the l-1'th index and r+1'th index together
