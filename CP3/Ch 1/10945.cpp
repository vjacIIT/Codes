#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

bool palindrome(string str, int l){
	for(int i=0; i<l/2; i++){
		if(str[i]!=str[l-i-1])	return false;
	}
	return true;
}

int main(){
	string str="";
	int l;
	char sr[200], c;
	while(scanf("%[^\n]s",sr)!=EOF){
		l=0;
		scanf("\n");
		for(int i=0; i<strlen(sr); i++){
			c=sr[i];
			if(c=='.' || c==',' || c=='!' || c=='?' || c==' ')	continue;
			str+=c;
			l++;
		}
		if(str=="DONE")	break;
		transform(str.begin(), str.end(), str.begin(), ::tolower);
		if(palindrome(str,l))	printf("You won't be eaten!\n");
		else	printf("Uh oh..\n");
		str.clear();	
	}
	return 0;
}
