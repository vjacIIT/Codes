#include<iostream>
using namespace std;

int main(){
	int t, a, b, c, mid;
	scanf("%d",&t);
	for(int i=1; i<=t; i++){
		scanf("%d%d%d",&a,&b,&c);
		mid = a;
		if((mid<b && mid<c) || (mid>b && mid>c)){
			if(mid<b && mid<c){
				if(b>c)	mid=c;
				else mid=b;
			}
			else{
				if(b>c)	mid=b;
				else	mid=c;
			}
		}
		printf("Case %d: %d\n",i,mid);
	}
	return 0;
}
