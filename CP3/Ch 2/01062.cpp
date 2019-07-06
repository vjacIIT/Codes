#include<cstdio>
#include<cstring>
using namespace std;

char a[27][1001];
int tp[27];						// top of each stack

bool canPut(int sno, char c){			// stack no
	char lc = a[sno][tp[sno]];
	return lc-c>=0 ? true:false;
}		// either we can put 'c' in stack no sno

int main(){
	char str[1000];
	int cno=1,nstk;
	bool flg;
	while(scanf("%s\n",str)!=EOF){
		if(!strcmp(str,"end"))	break;
		nstk=0;		for(int i=0; i<27; i++)	tp[i]=-1;
		for(int i=0; i<strlen(str); i++){
			flg=false;
			for(int j=0; j<nstk; j++){
				if(canPut(j,str[i])){
					tp[j]++;	a[j][tp[j]]=str[i];
					flg=true;	break;
				}
			}
			if(!flg){	
				tp[nstk]=0;	a[nstk][0]=str[i];
				nstk++;		if(nstk>25)	break;
			}
		}
		printf("Case %d: %d\n",cno,nstk);
		cno++;
	}
}


// This is a greedy approach, I have no proof of this
// Just I have tried that we can insert within the stacks made before
// If we cannot insert make a new stack and insert in that
