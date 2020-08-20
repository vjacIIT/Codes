#include<cstdio>
#include<cmath>
using namespace std;

int p, q, r, s, t, u;

double eval(double n){
	double val=0.0;
	val+= p*exp(-n);
	val+= q*sin(n);
	val+= r*cos(n);
	val+= s*tan(n);
	val+= t*n*n;
	val+= u;
	return val;
}

int main(){
	double mx, mn, val, x;
	while(scanf("%d%d%d%d%d%d",&p,&q,&r,&s,&t,&u)!=EOF){
		mx = eval(0.0);
		mn = eval(1.0);
		if(mx<0.0 || mn>0.0){
			printf("No solution\n");
			continue;
		}
		mn = 0.0;
		mx = 1.0;
		for(int i=0; i<40; i++){
			x = (mn+mx)/2.0;
			val = eval(x);
			if(val>0.00)
				mn = x;
			else
				mx = x;
		}	
		printf("%0.4f\n",x);
	}
	return 0;
}
