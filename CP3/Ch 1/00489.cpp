#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;

int main(){
	int rn, wrong,cnt;
	bool acstr[26], madestr[26], guessedbefore[26];		// one for each letter
	char str[1000];
	while(scanf("%d\n",&rn) && rn!=-1){
		wrong=0;	cnt=0;
		for(int i=0; i<26; i++){
			acstr[i]=false;
			madestr[i]=false;
			guessedbefore[i]=false;
		}
		scanf("%s\n",str);
		for(int i=0; i<strlen(str); i++)	acstr[str[i]-'a']=true;
		for(int i=0; i<26; i++){
			if(acstr[i])	cnt++;
		}

		scanf("%s\n",str);
		for(int i=0; i<strlen(str); i++){
			if(acstr[str[i]-'a']){
				if(!guessedbefore[str[i]-'a'])	cnt--;
				guessedbefore[str[i]-'a']=true;
				madestr[str[i]-'a']=true;
			}
			else if(!guessedbefore[str[i]-'a']){
				guessedbefore[str[i]-'a']=true;
				wrong++;
			}
			if(cnt==0)	break;
			if(wrong==7)	break;
		}
		if(wrong==7)	printf("Round %d\nYou lose.\n",rn);
		else{
			for(int i=0; i<26; i++){
				if(acstr[i]!=madestr[i])	wrong=7;
			}
			if(wrong==7)	printf("Round %d\nYou chickened out.\n",rn);
			else	printf("Round %d\nYou win.\n",rn);
		}
	}
	return 0;
}
