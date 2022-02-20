#include<cstdio>
#include<algorithm>
using namespace std;

int v[5][5];
int n, k;

bool lastRow(){							// n^2 time
	static bool seen[6];
	for(int c=0; c<n; c++){
		for(int r=1; r<=5; r++)
			seen[r]=false;
		for(int r=0; r<n-1; r++){
			if(seen[v[r][c]])
				return false;
			seen[v[r][c]] = true;
		}
		for(int r=1; r<=5; r++){
			if(!seen[r]){
				v[n-1][c] = r;
				break;
			}
		}
	}
	
	int trace=0;
	for(int i=0; i<n; i++)
		trace+=v[i][i];
	if(trace==k)
		return true;
	return false;
}

bool solve(int depth){
	if(depth==n-1){
		if(lastRow())
			return true;
		else
			return false;
	}
	
	for(int c=1; c<=n; c++)
		v[depth][c-1] = c;
	
	bool val = true;
	while(val){
		if(solve(depth+1))
			return true;
		val = next_permutation(v[depth],v[depth] + n);
	}
	
	return false;
}

void print(){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(j)
				printf(" ");
			printf("%d",v[i][j]);
		}
		printf("\n");
	}	
}

int main(){
	int tc;
	scanf("%d",&tc);
	for(int t=1; t<=tc; t++){
		scanf("%d%d",&n,&k);
		if(solve(0)){
			printf("Case #%d: POSSIBLE\n",t);
			print();
		}
		else
			printf("Case #%d: IMPOSSIBLE\n",t);		
	}
	return 0;
}

// Pass for partial n = 5, time complexity is O((n!)^(n-1)*n^2) i.e. around 10^7
