#include<iostream>
using namespace std;

int main(){
	int t, n, a, b, x, bb, al, in;
	cin>>t;
	while(t--){
		bb=0;		al=0;		in=0;
		cin>>n;	cin>>a;	cin>>b;
		while(n--){
			cin>>x;
			if(x%a==0)	bb++;
			if(x%b==0)	al++;
			if(x%a==0 && x%b==0)	in++;
		}
		if(bb>al)	printf("BOB\n");
		else if(bb<al)	printf("ALICE\n");
		else{
			if(in==0)	printf("ALICE\n");
			else		printf("BOB\n");
		}
	}
	return 0;
}
