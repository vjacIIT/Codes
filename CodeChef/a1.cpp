#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	bool **ar;
	int tc, n, m, *coin;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d%d",&n,&m);	// number of denominations and the sum we want to make
		ar = new bool*[n+1];
		coin = new int[n];
		for(int i=0; i<=n; i++)	ar[i]=new bool[m+1];
		for(int i=0; i<=n; i++)	ar[i][0]=true;		// when sum=0, always possible
		for(int i=1; i<=m; i++)	ar[0][i]=false;		// when no coins left and still sum left
		for(int i=0; i<n; i++)	scanf("%d",coin+i);
		sort(coin,coin+n);
		for(int i=1; i<=n; i++){
			for(int j=1; j<=m; j++){
				if(j>=coin[i-1])	ar[i][j]=ar[i-1][j]||ar[i-1][j-coin[i-1]];
				else	ar[i][j]=ar[i-1][j];
			}
		}
		if(ar[n][m])	printf("Yes\n");
		else	printf("No\n");
		for(int i=0; i<=n; i++)	delete []ar[i];
		delete []ar;
		delete []coin;
	}
	return 0;
}
