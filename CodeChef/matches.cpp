#include<iostream>
using namespace std;

int nt;
int flg;

long int big(long int a, long int b){
	long int bg;	
	bg = (a>b) ? a:b;
	return bg;
}

long int sml(long int a, long int b){
	long int sm;
	sm = (a<b) ? a:b;
	return sm;
}

void gcd(long int s, long int b){
	if(s==0)	return;
	nt++;
	if(b/s>1)	return ;
	return gcd(b%s,s);
}

int main(){
	int tc;
	long int n, m, b, s;
	scanf("%d",&tc);
	while(tc--){
		flg = -1;	// it is on neither side
		nt=0;
		scanf("%ld%ld",&n,&m);
		b = big(m,n);
		s = sml(m,n);
		gcd(s,b);
		//cout<<flg<<endl;
		if(nt%2==1)	printf("Ari\n");
		else	printf("Rich\n");
	}
	return 0;
}
