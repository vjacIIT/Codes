#include<cstdio>
#include<iostream>
using namespace std;

int r, c, **a;
char **m;

bool isValid(int i, int j){
	if(i>=0 && j>=0 && i<=r-1 && j<=c-1)	return true;
	return false;
}

int count(int i, int j){
	int cnt=0;
	if(isValid(i-1,j) && m[i-1][j]=='*')	cnt++;
	if(isValid(i+1,j) && m[i+1][j]=='*')	cnt++;
	if(isValid(i,j-1) && m[i][j-1]=='*')	cnt++;
	if(isValid(i,j+1) && m[i][j+1]=='*')	cnt++;
	if(isValid(i-1,j-1) && m[i-1][j-1]=='*')	cnt++;
	if(isValid(i+1,j-1) && m[i+1][j-1]=='*')	cnt++;
	if(isValid(i-1,j+1) && m[i-1][j+1]=='*')	cnt++;
	if(isValid(i+1,j+1) && m[i+1][j+1]=='*')	cnt++;
	return cnt;
}

int main(){
	int cnt=1, lineno=1;
	char ch;
	while(scanf("%d%d\n",&r,&c)!=EOF){
		if(r==0 && c==0)	break;
		if(lineno!=1)	printf("\n");
		lineno++;
		m = new char*[r];
		a = new int*[r];
		for(int i=0; i<r; i++){
			m[i]=new char[c];
			a[i] = new int[c];
		}
		for(int i=0; i<r; i++){
			for(int j=0; j<=c; j++){
				scanf("%c",&ch);
				if(ch=='\n')	continue;
				m[i][j]=ch;	
				if(m[i][j]=='*')	a[i][j]=-1;
				else	a[i][j]=0;
			}
		}
		for(int i=0; i<r; i++){
			for(int j=0; j<c; j++){
				if(a[i][j]!=-1){
					a[i][j]=count(i,j);
				}
			}
		}
		printf("Field #%d:\n",cnt);
		cnt++;
		for(int i=0; i<r; i++){
			for(int j=0; j<c; j++){
				if(a[i][j]>=0)	printf("%d",a[i][j]);
				else	printf("*");
			}
			printf("\n");
		}
		delete []a;
		delete []m;
	}
	return 0;
}
