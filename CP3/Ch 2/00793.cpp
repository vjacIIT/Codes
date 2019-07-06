#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;

vector<int>	prt, rnk;

void initialize(int n){
	prt = vector<int>(n+1);	
	rnk = vector<int>(n+1);
	for(int i=1; i<=n; i++){
		rnk[i]=0;	prt[i]=i;
	}
	return;
}

int fprt(int i){
	if(prt[i]==i)	return i;
	prt[i]=fprt(prt[i]);
	return prt[i];
}

void combine(int i1, int i2){
	if(rnk[i1]>rnk[i2]){	prt[i2]=i1;	return;	}
	else{
		prt[i1]=i2;	
		rnk[i1]==rnk[i2]	? rnk[i2]++:rnk[i2]+=0;
		return;
	}
}

int main(){
	char str[50], c;
	int tc, n, i1, i2, succ, lose;
	scanf("%d\n\n",&tc);
	while(tc--){
		succ=0;	lose=0;
		scanf("%d\n",&n);
		initialize(n);
		while(fgets(str,40,stdin)){
			if(!strcmp(str,"\n"))	break;
			sscanf(str,"%c %d %d\n",&c,&i1,&i2);
			if(c=='c'){
				if(i1==i2)	continue;
				i1 = fprt(i1);	i2=fprt(i2);
				combine(i1,i2);
			}
			else{
				if(i1==i2){	succ++;	continue;	}
				i1 = fprt(i1);	i2=fprt(i2);
				if(i1==i2)	succ++;
				else	lose++;
			}
		}
		printf("%d,%d\n",succ,lose);
		prt.clear();	rnk.clear();
		if(tc)	printf("\n");
	}
	return 0;
}
