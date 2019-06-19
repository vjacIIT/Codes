#include<cstdio>
#include<algorithm>
using namespace std;

int extra_knights(int n){
	int r = n%4;
	if(r==1)	return 2;
	else if(r==2 || r==3)	return 4;
	else	return 0;
}

int main(){
	bool swapped;
	int ans,m,n;
	while(scanf("%d%d",&m,&n)!=EOF){
		if(m==0 && n==0)	break;
		swapped = false;
		if(m>n){		// row must be smaller than column
			swap(m,n);
			swapped=true;
		}
		if(m==1)	ans=n;
		else if(m==2)	ans=(n/4)*4 + extra_knights(n);
		else	ans=(m*n+1)/2;
		if(swapped)	printf("%d knights may be placed on a %d row %d column board.\n",ans,n,m);
		else	printf("%d knights may be placed on a %d row %d column board.\n",ans,m,n);
	}
	return 0;
}

// This program logic is not done by me
// Try to think for the logic for extra_knights
