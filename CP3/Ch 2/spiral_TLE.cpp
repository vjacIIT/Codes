#include<cstdio>
using namespace std;

int ar[21][21];

char direction(char c){
	if(c=='U')	return 'L';		else if(c=='L')	return 'D';		else if(c=='D')	return 'R';		else	return 'U';
}

void spiral(int i, int j, char dtn, int steps, bool flg){
	int fsteps=steps;
	if(steps==21)	return;
	if(dtn=='D')	while(fsteps--){	ar[i+1][j]=ar[i][j]+1;	i++;	}
	if(dtn=='L')	while(fsteps--){	ar[i][j-1]=ar[i][j]+1;	j--;	}	
	if(dtn=='U')	while(fsteps--){	ar[i-1][j]=ar[i][j]+1;	i--;	}
	if(dtn=='R')	while(fsteps--){	ar[i][j+1]=ar[i][j]+1;	j++;	}
	if(!flg)	flg=true;
	else{	flg=false; 	steps++;	}
	spiral(i,j,direction(dtn),steps,flg);
	return;
}

int main(){
	for(int i=0; i<21; i++)	for(int j=0; j<21; j++)	ar[i][j]=0;
	ar[10][10]=1;		spiral(10,10,'U',1,false);			// up, left, down, right
	for(int i=0; i<21; i++){	for(int j=0; j<21; j++)	printf("%d\t",ar[i][j]);		printf("\n"); }
	return 0;
}

// First Tried to make spiral for UVA 10920, it gave TLE as it is O(n^2) for each test case
