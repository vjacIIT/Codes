#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;

int main(){
	bool equal[26];
	int tc,no,up[26],down[26],ch1,ch2;
	char str1[6],str2[6],wt[5];
	scanf("%d\n",&tc);
	while(tc--){
		for(int i=0; i<26; i++){
			down[i]=0;
			up[i]=0;
			equal[i]=false;
		}
		no=0;
		for(int i=0; i<3; i++){
			scanf("%s %s %s",str1,str2,wt);
			if(!(strcmp(wt,"up")) || !(strcmp(wt,"down")))	no++;
			for(int j=0; j<strlen(str1); j++){
				ch1=str1[j]-'A';	
				ch2=str2[j]-'A';
				if(!strcmp(wt,"up")){
					if(!equal[ch1])	down[ch1]++;					// right one is up, and left one is down
					if(!equal[ch2])	up[ch2]++;
				}
				else if(!strcmp(wt,"down")){				// right one is down, left one is up
					if(!equal[ch1])	up[ch1]++;
					if(!equal[ch2])	down[ch2]++;
				}
				else{
					equal[ch1]=true;				// means it will not be the answer, as it is a true coin
					equal[ch2]=true;
				}
			}
		}
		for(int i=0; i<26; i++){
			if(!equal[i] && abs(up[i]-down[i])==no){
				no=i;
				break;
			}
		}
		printf("%c is the counterfeit coin and it is ",char(no+65));
		if(up[no]>0)	printf("light.\n");
		else	printf("heavy.\n");
	}
	return 0;
}

// This program is giving wrong answer, don't know why, showing correct answer on udebug
// Concept is that the wrong alphabet will always be lighter or heavier, so each time up or down comes it's up or down value increases 
// So if it is lighter then up[alphabet]=no, if it is heavy then down[alphabet]=no
