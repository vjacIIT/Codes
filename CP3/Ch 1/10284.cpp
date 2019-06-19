#include<cstdio>
#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

bool ar[8][8];
vector<vector<pair<bool,char>>>	placement(8,vector<pair<bool,char>>(8));

bool isInteger(char c){
	int i=c-'0';
	return (i<9);
}

bool valid(int i, int j){
	if(i>=0 && i<=7 && j>=0 && j<=7)	return true;
	return false;
}

void UDLR(int row, int column, int rflg, int cflg){
	while(valid(row,column) && !placement[row][column].first){
		ar[row][column]=false;
		row+=rflg;
		column+=cflg;
	}
	return;
}

void knight(int row, int column){
	if(valid(row,column))	ar[row][column]=false;
}

int main(){
	int row,column,cnt;
	char str[100],c;
	while(scanf("%s\n",str)!=EOF){
		cnt=0;
		for(int i=0; i<8; i++){
			for(int j=0; j<8; j++){
				placement[i][j].first=false;
				placement[i][j].second='.';		
				ar[i][j]=true;		// saved
			}
		}
		row=0;	column=0;
		for(int i=0; i<strlen(str); i++){
			if(str[i]=='/'){
				row++;
				column=0;
			}
			else{
				if(isInteger(str[i]))	column+=str[i]-'0';
				else{
					placement[row][column].first=true;
					placement[row][column].second=str[i];		
					ar[row][column]=false;	// unsafe	
					column++;
				}
			}	
		}
		for(int i=0; i<8; i++){
			for(int j=0; j<8; j++){
				if(placement[i][j].first){
					c = placement[i][j].second;
					if(c=='p'){				// black pawn
						if(valid(i+1,j-1))	ar[i+1][j-1]=false;
						if(valid(i+1,j+1))	ar[i+1][j+1]=false;
					}
					else if(c=='P'){		// white pawn
						if(valid(i-1,j-1))	ar[i-1][j-1]=false;
						if(valid(i-1,j+1))	ar[i-1][j+1]=false;
					}
					else if(c=='R' || c=='r'){			// rookie, up, down, left, right
						UDLR(i-1,j,-1,0);	UDLR(i+1,j,1,0);	UDLR(i,j-1,0,-1);	UDLR(i,j+1,0,1);
					}
					else if(c=='N' || c=='n'){
						knight(i-1,j-2);	knight(i-1,j+2);	knight(i+1,j-2);	knight(i+1,j+2);
						knight(i-2,j-1);	knight(i+2,j-1);	knight(i-2,j+1);	knight(i+2,j+1);
					}
					else if(c=='B' || c=='b'){
						UDLR(i-1,j-1,-1,-1);	UDLR(i-1,j+1,-1,1);		UDLR(i+1,j-1,1,-1);		UDLR(i+1,j+1,1,1);	
					}
					else if(c=='Q' || c=='q'){
						UDLR(i-1,j,-1,0);	UDLR(i+1,j,1,0);	UDLR(i,j-1,0,-1);	UDLR(i,j+1,0,1);
						UDLR(i-1,j-1,-1,-1);	UDLR(i-1,j+1,-1,1);		UDLR(i+1,j-1,1,-1);		UDLR(i+1,j+1,1,1);
					}
					else{
						if(valid(i-1,j-1))	ar[i-1][j-1]=false;
						if(valid(i-1,j+1))	ar[i-1][j+1]=false;
						if(valid(i+1,j-1))	ar[i+1][j-1]=false;
						if(valid(i+1,j+1))	ar[i+1][j+1]=false;
						if(valid(i,j-1))	ar[i][j-1]=false;
						if(valid(i,j+1))	ar[i][j+1]=false;
						if(valid(i-1,j))	ar[i-1][j]=false;
						if(valid(i+1,j))	ar[i+1][j]=false;
					}	
				}
			}
		}
		for(int i=0; i<8; i++){
			for(int j=0; j<8; j++)	if(ar[i][j])	cnt++;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
