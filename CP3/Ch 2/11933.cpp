#include<cstdio>
using namespace std;

int n, a, b;

void divide(){
	a=0;	b=0;
	int count=0, m=1;
	while(n>0){
		if(n%2==1){
			if(count%2==0)	a+=m;
			else	b+=m;
			count++;
		}
		n/=2;
		m*=2;
	}
	return;
}

int main(){
	while(scanf("%d",&n)){
		if(n==0)	break;
		divide();
		printf("%d %d\n",a,b);
	}
	return 0;
}
