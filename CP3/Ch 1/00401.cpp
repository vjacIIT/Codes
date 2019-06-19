#include<iostream>
#include<cstring>
#include<map>
using namespace std;

map<char,char>	reverse;

bool isPalindrome(char *str, int l){
	for(int i=0; i<l/2; i++){
		if(str[i]!=str[l-i-1])	return false;
	}
	return true;
}

bool isMirror(char *str, int l){
	for(int i=0; i<=l/2; i++){
		if(reverse[str[i]]=='*' || reverse[str[i]]!=str[l-i-1])	return false;
	}
	return true;
}

int main(){
	bool pal, mir;
	int l,lineno=1;
	char str[200],ch;
	reverse['1']='1';	reverse['4']='*';	reverse['6']='*';	reverse['7']='*';	reverse['8']='8';	reverse['9']='*';
	for(int i=65; i<91; i++){
		ch=char(i);
		if(ch=='A' || ch=='H' || ch=='I' || ch=='M' || ch=='O' || ch=='T' || ch=='U' || ch=='V' || ch=='W' || ch=='X' || ch=='Y')	reverse[ch]=ch;
		else if(ch=='E'){
			reverse[ch]='3';
			reverse['3']=ch;
		}
		else if(ch=='J' || ch=='L'){
			reverse['L']='J';
			reverse['J']='L';
		}
		else if(ch=='S'){
			reverse[ch]='2';
			reverse['2']=ch;
		}
		else if(ch=='Z'){
			reverse[ch]='5';
			reverse['5']=ch;
		}
		else	reverse[ch]='*';
	}
	while(scanf("%s\n",str)!=EOF){
		//if(lineno!=1)	printf("\n");
		//lineno++;
		l=strlen(str);
		for(int i=0; i<l; i++)	if(str[i]=='0' || str[i]=='o')	str[i]='O';
		pal=isPalindrome(str,l);
		mir=isMirror(str,l);
		printf("%s -- is ",str);
		if(pal && mir)	printf("a mirrored palindrome.\n\n");
		if(!pal && mir)	printf("a mirrored string.\n\n");
		if(pal && !mir)	printf("a regular palindrome.\n\n");
		if(!pal && !mir)	printf("not a palindrome.\n\n");
	}
	return 0;
}
