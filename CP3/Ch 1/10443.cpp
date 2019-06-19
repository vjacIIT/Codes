#include<cstdio>
using namespace std;

int r, c;

bool big(char a, char b){
	if(a=='R' && b=='S')	return true;
	if(a=='P' && b=='R')	return true;
	if(a=='S' && b=='P')	return true;
	return false;	
}

bool valid(int i, int j){
	if(i>=0 && i<r && j>=0 && j<c)	return true;
	return false;
}

int main(){
	char **old,**now,ch;
	int tc,nt,lineno=1;
	scanf("%d",&tc);
	while(tc--){
		if(lineno!=1)	printf("\n");
		lineno++;
		scanf("%d%d%d\n",&r,&c,&nt);
		old = new char*[r];
		now = new char*[r];
		for(int i=0; i<r; i++){
			old[i]=new char[c];
			now[i]=new char[c];
		}
		
		for(int i=0; i<r; i++){
			for(int j=0; j<c; j++){
				scanf("%c",&old[i][j]);
				now[i][j]=old[i][j];
			}
			scanf("\n");
		}
		
		while(nt--){
			for(int i=0; i<r; i++){
				for(int j=0; j<c; j++){
					ch = old[i][j];
					if(valid(i,j-1) && big(ch,old[i][j-1]))	now[i][j-1]=ch;
					if(valid(i,j+1) && big(ch,old[i][j+1]))	now[i][j+1]=ch;
					if(valid(i-1,j) && big(ch,old[i-1][j]))	now[i-1][j]=ch;	
					if(valid(i+1,j) && big(ch,old[i+1][j]))	now[i+1][j]=ch;
				}
			}
			for(int i=0; i<r; i++){
				for(int j=0; j<c; j++)	old[i][j]=now[i][j];
			}
		}
		
		for(int i=0; i<r; i++){
			for(int j=0; j<c; j++)	printf("%c",old[i][j]);
			printf("\n");
		}
		
		for(int i=0; i<r; i++){
			delete []old[i];
			delete []now[i];
		}
		delete []old;
		delete []now;
	}
	return 0;
}
