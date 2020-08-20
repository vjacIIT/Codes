#include<cstdio>
using namespace std;

int a, b, c;

bool sum(int x, int y, int z){
	int s=x+y+z;
	return s==a ? true:false;
}

bool mul(int x, int y, int z){
	int m=x*y*z;
	return m==b ? true:false;
}

bool sqr(int x, int y, int z){
	int s = (x*x) + (y*y) + (z*z);
	return s==c ? true:false;
}

int main(){
	bool flg;
	int tc;
	scanf("%d",&tc);
	while(tc--){
		flg=false;
		scanf("%d%d%d",&a,&b,&c);
		for(int x=-100; x<=100; x++){
			for(int y=-100; y<=100; y++){
				for(int z=-100; z<=100; z++){
					if(x==y || x==z || y==z)	continue;
					if(sum(x,y,z) && mul(x,y,z) && sqr(x,y,z)){
						flg=true;	printf("%d %d %d\n",x,y,z);	break;
					}
				}
				if(flg)	break;
			}
			if(flg)	break;
		}
		if(!flg)	printf("No solution.\n");
	}
	return 0;
}
