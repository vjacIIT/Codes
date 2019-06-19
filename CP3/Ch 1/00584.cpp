#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

bool isInteger(char c){
	if(c=='X' || c=='/')	return false;
	return true;
}

int main(){
	bool special[12];				
	char str[100],newline;
	int score[12][2], ans, no1, no2, lineno=1;
	while(scanf("%[^\n]s",str)!=EOF){			// scans until new line
		scanf("%c",&newline);
		if(lineno!=1)	printf("%d\n",ans);
		lineno++;
		if(str=="Game Over")	break;
		for(int i=0; i<12; i++){
			special[i]=false;
			for(int j=0; j<2; j++)	score[i][j]=0;
		}
		ans=0;	no1=0;	no2=0;
		for(int i=0; i<strlen(str); i++){
			if(str[i]==' ')	continue;
			if(isInteger(str[i])){
				score[no1][no2]=str[i]-'0';
				if(no2==0)	no2++;
				else{
					no1++;	no2=0;
				}
			}
			else{
				if(str[i]=='X')	score[no1][no2]=10;
				else	score[no1][no2]=10-score[no1][no2-1];
				special[no1]=true;
				no1++;	no2=0;
			}
		}
		for(int i=0; i<10; i++){
			if(special[i]){
				ans+=10;
				if(score[i][0]==10){
					if(score[i+1][0]==10)	ans+=10+score[i+2][0];
					else	ans+=score[i+1][0]+score[i+1][1];
				}
				else	ans+=score[i+1][0];
			}
			else	ans+=score[i][0]+score[i][1];
		}
	}
	return 0;
}
