#include<cstdio>
#include<cstring>
using namespace std;

int *ar, *bit, n;

int Lset(int i){
	return (i&(-i));
}

void update(int i, int val){
	for(; i<=n; i+=Lset(i))	bit[i]+=val;
	return;
}

int fsum(int i){
	int sum=0;
	for(; i>0; i-=Lset(i))	sum+=bit[i];
	return sum;
}

int main(){
	char c, str[50];
	int cse=0, l, r;
	while(scanf("%d",&n)!=EOF){
		if(n==0)	break;
		if(cse)	printf("\n");
		printf("Case %d:\n",++cse);
		ar = new int[n+1];		ar[0]=0;
		bit = new int[n+1];		bit[0]=0;
		for(int i=1; i<=n; i++)	scanf("%d\n",ar+i);
		for(int i=1; i<=n; i++)	update(i,ar[i]);
		while(fgets(str,20,stdin)){
			if(!strcmp(str,"END\n"))	break;
			sscanf(str,"%c %d %d",&c,&l,&r);
			if(c=='M'){
				l = fsum(l-1);	r=fsum(r);
				printf("%d\n",r-l);
			}
			else{
				update(l,r-ar[l]);	ar[l]=r;
			}
		}
		delete []ar;	delete []bit;
	}
	return 0;
}
