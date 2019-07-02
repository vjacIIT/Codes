#include<iostream>
#include<limits.h>
using namespace std;

int n, **d;
bool *vis;

int tsp(int ind, int cnt){
	if(cnt==n)	return d[ind][0];
	int min = INT_MAX, min2;
	vis[ind]=true;
	for(int i=0; i<=n; i++){
		if(!vis[i]){
			min2=d[ind][i]+tsp(i,cnt+1);
			vis[i]=false;
			min = (min2<min) ? min2:min;
		}
	}
	return min;
}

int main(){
	int tc,min;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		d = new int*[n+1];
		vis = new bool[n+1];
		for(int i=0; i<=n; i++)	d[i]=new int[n+1];
		for(int i=0; i<=n; i++){
			vis[i]=false;
			for(int j=0; j<=n; j++){
				if(i!=j)	scanf("%d",&d[i][j]);
				else	d[i][j]=0;
			}
		}
		min = tsp(0,0);
		printf("%d\n",min);
		for(int i=0; i<=n; i++)	delete []d[i];
		delete []d;
		delete []vis;
	}
	return 0;
}

// This program is not O(2^n), this is infact O(n!) because it has not stored the already find states
