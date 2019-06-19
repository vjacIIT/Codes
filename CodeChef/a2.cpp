#include<iostream>
using namespace std;

int main(){
	int tc, k;
	bool flg;
	long long int rest, input;
	scanf("%d",&tc);
	while(tc--){
		rest = 1;
		flg=true;
		scanf("%d",&k);
		while(k--){
			scanf("%lld",&input);
			if(input>rest)	flg=false;
			else{
				rest = rest-input;
				rest +=rest;
			}
		}
		if(!flg || rest!=0)	printf("No\n");
		else	printf("Yes\n");
	}
	return 0;
}
