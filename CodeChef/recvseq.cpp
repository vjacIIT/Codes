#include<iostream>
using namespace std;

int main(){
	int n, d1, d2, d3, *ar, d, a, tc;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		ar = new int[n];
		for(int i=0; i<n; i++)	scanf("%d",ar+i);
		d1 = ar[1]-ar[0];
		d2 = ar[2]-ar[1];
		d3 = ar[3]-ar[2];
		if(d1==d2){			// first 3 are correct
			d=d1;
			a=ar[0];
		}
		else if(d2==d3){	// error in 1's value
			d=d2;
			a=ar[1]-d;
		}
		else if(d1+d2==2*d3){	// error in 2'nd value
			d=d3;
			a=ar[0];
		}
		else if(d2+d3==2*d1){	// error in 3'rd value
			d=d1;
			a=ar[0];
		}
		for(int i=0; i<n; i++)	printf("%d ",a+i*d);
		printf("\n");
		delete []ar; 
	}
	return 0;
}
