#include<cstdio>
using namespace std;

int main(){
	bool flg;
	int n, abcde, fghij, tmp, used, cno=0;
	while(scanf("%d",&n)!=EOF){
		if(n==0)	break;
		if(cno)	printf("\n");
		cno++;
		flg=false;
		for(int fghij=1234; fghij<=98765/n; fghij++){
			abcde = fghij*n;				// ensures that abcdef is a 5 digit number
			used = (fghij<10000);			// if fghij is a 4 digit number, used = 1;
			tmp = abcde;
			while(tmp){	used |= 1<<(tmp%10);	tmp/=10;	}	// bit value for identification
			tmp = fghij;
			while(tmp){	used |= 1<<(tmp%10);	tmp/=10;	}
			if(used==(1<<10)-1){				// there is no overflow for used
				flg=true;
				printf("%d / ",abcde);		if(fghij<10000)	printf("0");
				printf("%d = %d\n",fghij,n);
			}
		}
		if(!flg)	printf("There are no solutions for %d.\n",n);
	}
	return 0;
}
