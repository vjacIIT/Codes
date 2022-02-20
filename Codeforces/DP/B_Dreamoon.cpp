#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;

int fact(int n){
	if(n<2)	return 1;
	else	return n*fact(n-1);
}

int power(int n){
	int p;
	if(n==0)	return 1;
	if(n%2==0){
		p = power(n/2);
		return p*p;
	}
	else	return 2*power(n-1);
}

int main(){
	int l, fpos=0, pos=0, nq=0, stp, np, nn, nqf, npf, nnf;
	char str[20];
	scanf("%s",str);
	scanf("\n");	
	l = strlen(str);
	for(int i=0; i<l; i++)	
		fpos+= (str[i]=='+' ? 1:-1);	
	
	scanf("%s",str);
	for(int i=0; i<l; i++){
		if(str[i]=='?')	
			nq++;
		else if(str[i]=='+')	
			pos++;
		else	
			pos--;
	}
	stp = fpos-pos;
	if((stp+nq)%2)	
		printf("%.10f\n",0.0);
	else{
		np = (stp+nq)/2;
		nn = nq-np;
		if(np<0 || nn<0)	
			printf("%.10f\n",0.0);
		else{
			nqf = fact(nq);
			npf = fact(np);
			nnf = fact(nn);
			stp = nqf/(npf*nnf);
			l = power(nq);
			printf("%.10f\n",(double)stp/l);
		}
	}
	return 0;
}
