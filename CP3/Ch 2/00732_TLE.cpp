#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

char str1[30], str2[30];
char stk[60];
int l;

void func(int npsh, int npop, string s){
	if(npop>npsh || npsh>l || npop>l)	return;
	if(npsh+npop==2*l){
		char str3[l];
		int tp=-1, cnt=0, i=0;	
		while(cnt!=2*l){
			if(s[cnt]=='i'){
				tp++;	stk[tp]=str1[i];	i++;
			}
			else{	str3[cnt-i]=stk[tp];	tp--;	}
			cnt++;
		}
		if(!strcmp(str3,str2)){	for(int i=0; i<2*l-1; i++)	printf("%c ",s[i]);	printf("%c\n",s[2*l-1]);	}
		return;
	}
	func(npsh+1,npop,s+'i');
	func(npsh,npop+1,s+'o');
	return;
}

int main(){
	char str3[30], str4[30];
	while(scanf("%s\n",str1)!=EOF){
		scanf("%s\n",str2);			printf("[\n");	l = strlen(str1);
		strcpy(str3,str1);		sort(str3, str3+strlen(str3));		
		strcpy(str4,str2);		sort(str4,str4+strlen(str4));
		if(strlen(str1)!=strlen(str2) || strcmp(str3,str4)!=0){	printf("]\n");	continue;	}
		func(0,0,"");
		printf("]\n");
	}
}

// This program makes TLE, we need to find all the possible options and check if it is possible
// Concept is right, we just need to optimise
