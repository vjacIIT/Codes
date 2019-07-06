#include<cstdio>
#include<cmath>
using namespace std;

int jolly(int a, int b, int n){
	return abs(a-b)<n ? abs(a-b):0;
	
}

int main(){
	bool *pnt, flg;
	int *ar, n, no;
	while(scanf("%d",&n)!=EOF){
		flg=true;
		ar = new int[n];
		pnt = new bool[n];
		for(int i=0; i<n; i++){	scanf("%d",ar+i);	pnt[i]=false;	}
		for(int i=0; i<n-1; i++)	pnt[jolly(ar[i],ar[i+1],n)]=true;
		for(int i=1; i<n; i++){
			if(!pnt[i]){	flg=false;	break;	}
		}
		
		if(flg)	printf("Jolly\n");
		else	printf("Not jolly\n");
		delete []ar;
		delete []pnt;
	}
	return 0;
}
