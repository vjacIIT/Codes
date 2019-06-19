#include<iostream>
using namespace std;

int main(){
	int months, ndep, m;
	double apm, am, carvalue, *dep, dm, fxd=1.0000000000;
	while(scanf("%d%lf%lf%d",&months,&apm,&am,&ndep)){
		if(months<0)	break;
		dep = new double[100];
		for(int i=0; i<months+1; i++)	dep[i]=0.0;
		for(int i=0; i<ndep; i++){
			scanf("%d%lf",&m,&dm);
			dep[m]=dm;
		}
		for(int i=1; i<months+1; i++){
			if(dep[i]==0.0)	dep[i]=dep[i-1];
		}
		carvalue = ((double)1.0-dep[0])*(apm+am);		// after month 0 , just after taking it out
		m=1;
		apm = am/months;
		while(carvalue<=am && m<101){
			carvalue=((double)1.0-dep[m])*carvalue;
			am -= apm;
			m++;
		}
		printf("%d month",m-1);
		if(m!=2)	printf("s\n");
		else	printf("\n");
		delete []dep;
	}
	return 0;
}
