#include<iostream>
using namespace std;

int r, c;

int value(int i, int j){
	if(i==0 || i==r-1){		// first row
		if(j==0 || j==c-1)	return 2;
		else return 3;
	}
	else if(j==0 || j==c-1){
		if(i==0 || i==r-1)	return 2;
		else return 3;
	}
	return 4;
}

int main(){
	int **ad, val, tc;
	bool flg;
	scanf("%d",&tc);
	while(tc--){
		flg = true;
		scanf("%d%d",&r,&c);
		ad = new int*[r];
		for(int i=0; i<r; i++)	ad[i]=new int[c];
		for(int i=0; i<r; i++){
			for(int j=0; j<c; j++)	ad[i][j]=value(i,j);
		}
		
		for(int i=0; i<r; i++){
			for(int j=0; j<c; j++){
				scanf("%d",&val);
				if(val>=ad[i][j])	flg=false;
			}
		}
		if(flg)	printf("Stable\n");
		else	printf("Unstable\n");
		for(int i=0; i<r; i++)	delete []ad[i];
		delete []ad;
	}
	return 0;
}
