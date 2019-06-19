#include<iostream>
using namespace std;

int fDirection(int x, int y){
	if(x==0 || y==0)	return 0;
	if(x<0 && y>0)	return 7;
	else if(x>0 && y>0)	return 9;
	else if(x<0 && y<0)	return 1;
	else return 3;
}

int main(){
	int k,x,y,result,n,m;
	while(scanf("%d",&k)){
		if(k==0)	break;
		scanf("%d%d",&n,&m);
		while(k--){
			scanf("%d%d",&x,&y);
			result = fDirection(x-n,y-m);
			if(result==0)	printf("divisa\n");
			else if(result==7)	printf("NO\n");
			else if(result==9)	printf("NE\n");
			else if(result==1)	printf("SO\n");
			else printf("SE\n");
		}
	}
}
