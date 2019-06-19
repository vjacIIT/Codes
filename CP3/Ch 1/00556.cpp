#include<cstdio>
#include<cstdlib>
#include<chrono>
#include<thread>
using namespace std;

int **mtx, row, column, cnt[5];
bool flg;
char str[100];

void initialize(){
	for(int i=0; i<5; i++)	cnt[i]=0;
	flg=false;
	mtx = new int*[row];
	for(int i=0; i<row; i++)	mtx[i]=new int[column];
		
	for(int i=0; i<row; i++){
		scanf("%s\n",str);	
		for(int j=0; j<column; j++)	mtx[i][j]= str[j]=='1' ? -1:0;
	}
	return;
}

void dinitialize(){
	for(int i=0; i<row; i++)	delete []mtx[i];
	delete []mtx;
	return;	
}

char take(char cdtn, char dtn){					// current direction and take right, left, or back
	if(dtn=='r'){
		if(cdtn=='r') return 'd';	if(cdtn=='l') return 'u';	if(cdtn=='u') return 'r';	return 'l';
	}
	if(dtn=='l'){
		if(cdtn=='r') return 'u';	if(cdtn=='l') return 'd';	if(cdtn=='u') return 'l';	return 'r';
	}
	if(dtn=='b'){
		if(cdtn=='r') return 'l';	if(cdtn=='l') return 'r';	if(cdtn=='u') return 'd';	return 'u';
	}
}

void nextState(int &i, int &j, char dtn){
	if(dtn=='u')	i--;	if(dtn=='d')	i++;	if(dtn=='l')	j--;	if(dtn=='r')	j++;
	return;
}

bool blocked(int i, int j, char dtn){			// blocked in direction given or not
	nextState(i,j,dtn);
	if(i>=row || i<0 || j>=column || j<0 || mtx[i][j]==-1)	return true;
	else	return false;
}

bool rightBlocked(int i, int j, char dtn){
	dtn = take(dtn,'r');		// new direction
	return blocked(i,j,dtn) ? true:false;
}

bool leftBlocked(int i, int j, char dtn){
	dtn = take(dtn,'l');
	return blocked(i,j,dtn) ? true:false;
}

void go(int i, int j, char dtn){
	if(flg && i==row-1 && j==0)	return;
	flg=true;
	if(!rightBlocked(i,j,dtn)){					// we can go in right direction
		dtn=take(dtn,'r');				// take right
		nextState(i,j,dtn);
	}
	else if(!blocked(i,j,dtn))	nextState(i,j,dtn);					// go in the same direction
	else if(!leftBlocked(i,j,dtn)){
		dtn=take(dtn,'l');
		nextState(i,j,dtn);
	}
	else{										// go back
		dtn=take(dtn,'b');
		nextState(i,j,dtn);
	}
	mtx[i][j]++;
	go(i,j,dtn);
	return;
}

int digits(int n){
	int nodigits=0;
	if(n==0)	return 1;
	while(n>0){
		nodigits++;
		n=n/10;
	}
	return nodigits;
}

int main(){
	int d;
	while(scanf("%d%d",&row,&column)){
		if(row==0 || column==0)	break;
		initialize();
		go(row-1,0,'r');			// current i,j and direction
		for(int i=0; i<row; i++){
			for(int j=0; j<column; j++)	if(mtx[i][j]!=-1)	cnt[mtx[i][j]]++;
		}
		for(int i=0; i<5; i++){
			d=3-digits(cnt[i]);
			for(int j=0; j<d; j++)	printf(" ");
			printf("%d",cnt[i]);
		}
		printf("\n");
		dinitialize();
	}
	return 0;
}
