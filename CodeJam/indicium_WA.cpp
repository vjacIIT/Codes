#include<cstdio>
#include<vector>
using namespace std;

int main(){
	vector<vector<int>> v;
	int tc, n, k;
	scanf("%d",&tc);
	for(int t=1; t<=tc; t++){
		scanf("%d%d",&n,&k);
		v = vector<vector<int>>(n,vector<int>(n));
		if((k%n)!=0){
			printf("Case #%d: IMPOSSIBLE\n",t);
			continue;
		}
		k = k/n;
		for(int r=k+1; r<=k+n; r++){
			for(int c=k+1; c<=k+n; c++){
				v[r-k-1][n-1-(c-k-1)] = (r + (c-k-1))%n;
			}
		}
		printf("Case #%d: POSSIBLE\n",t);
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(j)
					printf(" ");
				if(v[i][j]==0)
					v[i][j] = n;
				printf("%d",v[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}

// This is absolute wrong solution, it assumes that if k%n!=0 then impossible, but k=14 n=4 is possible
