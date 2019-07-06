#include<cstdio>
#include<cstring>
using namespace std;

char str1[30], str2[30];
char stk[60], p[60];
int l, tp;

void func(int npsh, int npop, int idx){
	if(npsh==l && npop==l){
		for(int j=0; j<idx; j++){
			if(j)	printf(" ");
			printf("%c",p[j]);
		}
		printf("\n");	return;
	}
	if(npsh<l){
		tp++;	stk[tp]=str1[npsh];	p[idx]='i';	func(npsh+1,npop,idx+1);	tp--;
	}
	if(npsh>npop){
		if(stk[tp]==str2[npop]){
			tp--;	p[idx]='o';	func(npsh,npop+1,idx+1);	tp++;	stk[tp]=str2[npop];
		}
	}
	return;
}

int main(){
	while(scanf("%s\n",str1)!=EOF){
		scanf("%s\n",str2);			printf("[\n");	l = strlen(str1);	tp=-1;
		if(strlen(str1)==strlen(str2))	func(0,0,0);
		printf("]\n");
	}
}

// This worked in time 0.01s
// Some optimisation are done here
// As an element is popped we need to check whether it matches to string 2 or not
// No of pushed elements are always >= npop
