#include<cstdio>
using namespace std;

char **sml, **big;
int N, n, ans0, ans90, ans180, ans270;

void scan(){
	big = new char*[N];		for(int i=0; i<N; i++)	big[i]=new char[N];
	sml = new char*[n];		for(int i=0; i<n; i++)	sml[i]=new char[n];
	for(int i=0; i<N; i++){	for(int j=0; j<N; j++)	scanf("%c",&big[i][j]);	scanf("\n");	}
	for(int i=0; i<n; i++){	for(int j=0; j<n; j++)	scanf("%c",&sml[i][j]);	scanf("\n");	}
	return;
}

void rotate(){
	int count0, count90, count180, count270;
	ans0=0;		ans90=0;	ans180=0;	ans270=0;
	for(int i=0; i<=N-n; i++){
		for(int j=0; j<=N-n; j++){
			count0=0;	count90=0;	count180=0;	count270=0;
			for(int k=i; k<i+n; k++){
				for(int w=j; w<j+n; w++){
					if(big[k][w]==sml[k-i][w-j])	count0++;
					if(big[k][w]==sml[n-1-w+j][k-i])	count90++;
					if(big[k][w]==sml[n-1-k+i][n-1-w+j])	count180++;
					if(big[k][w]==sml[w-j][n-1-k+i])	count270++;
				}
			}
			if(count0==n*n)	ans0++;
			if(count90==n*n)	ans90++;
			if(count180==n*n)	ans180++;
			if(count270==n*n)	ans270++;
		}
	}
}

void del(){
	for(int i=0; i<N; i++)	delete[]big[i];		for(int i=0; i<n; i++)	delete[]sml[i];
	delete []big;	delete []sml;
	return;
}

int main(){
	while(scanf("%d%d\n",&N,&n)!=EOF){
		if(n==0 && N==0)	break;
		scan();		rotate();
		printf("%d %d %d %d\n",ans0,ans90,ans180,ans270);
		del();
	}
	return 0;
}
