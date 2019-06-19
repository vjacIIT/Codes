#include<cstdio>
using namespace std;

bool findP(char a, char b){
	if(a=='P' || b=='P')	return true;
	return false;
}

int main(){
	char *at;
	int tc,l,dreq,np,nproxy;
	scanf("%d",&tc);
	while(tc--){
		np=0;	nproxy=0;
		scanf("%d\n",&l);
		at = new char[l];
		for(int i=0; i<l; i++)	scanf("%c",at+i);
		if(l%4==0)	dreq=(3*l)/4;
		else	dreq=(3*l)/4 + 1;

		for(int i=0; i<l; i++){
			if(at[i]=='P')	np++;
		}
		
		for(int i=2; i<l-2; i++){
			if(at[i]=='A'){
				if(findP(at[i-1],at[i-2]) && findP(at[i+1],at[i+2]))	nproxy++;	
			}
		}
		
		if(np+nproxy>=dreq){
			if(np>=dreq)	printf("0\n");
			else	printf("%d\n",dreq-np);
		}
		else	printf("-1\n");
		
	}
	return 0;
}
