#include<cstdio>
using namespace std;

char old[5][5];
char now[5][5];

char cchar(int n){
	return n==0 ? '0':'1';
}

int cint(char c){
	return c=='0' ? 0:1;
}

char sum(int i, int j){
	int s = cint(old[i+1][j])+cint(old[i-1][j])+cint(old[i][j+1])+cint(old[i][j-1]);
	return cchar(s%2);
}

int nzeros(){
	int nz=0;
	for(int i=1; i<4; i++){	
		for(int j=1; j<4; j++)	if(old[i][j]=='0')	nz++;
	}
	return nz;
}

int func(){
	int nz, count=0;
	nz = nzeros();
	while(nz!=9){
		count++;
		for(int i=1; i<4; i++){
			for(int j=1; j<4; j++)	now[i][j]=sum(i,j);
		}
		for(int i=1; i<4; i++){
			for(int j=1; j<4; j++)	old[i][j]=now[i][j];
		}
		nz=nzeros();
	}
	return count-1;
}

void initialize(){
	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){	
			old[i][j]='0';	now[i][j]='0';
		}
	}
	return;
}

int main(){
	int tc, cnt;
	scanf("%d\n\n",&tc);
	while(tc--){
		initialize();
		for(int i=1; i<4; i++){
			for(int j=1; j<4; j++)	scanf("%c",&old[i][j]);
			scanf("\n");
		}
		scanf("\n");
		cnt = func();
		printf("%d\n",cnt);
	}
	return 0;
}
