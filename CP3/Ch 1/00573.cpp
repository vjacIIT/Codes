#include<iostream>
using namespace std;

int main(){
	int h,a,s,p,day;
	double total,diff,climb;
	while(scanf("%d%d%d%d",&h,&a,&s,&p)){
		if(h==0)	break;
		total=0.0;
		climb = 1.0*a;
		day=1;
		diff = (1.0*a*p)/100;
		while(true){
			total+=climb;
			if(total>1.0*h)	break;
			total-=1.0*s;
			if(total<0.0)	break;
			day++;
			climb-=diff;
			if(climb<0)	climb=0;
		}
		if(total>1.0*h)	printf("success on day %d\n",day);
		else	printf("failure on day %d\n",day);
	}
	return 0;
}
