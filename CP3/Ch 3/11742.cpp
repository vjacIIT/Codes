#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct three{
	int a, b, d;
};

vector<int> ar;

int find(int no, int n){
	int i;
	for(i=0; i<n; i++){
		if(ar[i]==no)	return i;
	}
}

int main(){
	bool flg;
	three *cons;
	int n, m, a, b, d, cnt, i, i1, i2;
	while(scanf("%d%d",&n,&m)!=EOF){
		if(n==0 && m==0)	break;
		ar = vector<int>(n);	cnt=0;
		for(i=0; i<n; i++)	ar[i]=i;
		cons = new three[m];
		for(i=0; i<m; i++){
			scanf("%d%d%d",&a,&b,&d);
			cons[i].a = a;	cons[i].b=b;	cons[i].d=d;
		}
		do{
			flg=true;
			for(i=0; i<m; i++){
				i1 = find(cons[i].a,n);	i2=find(cons[i].b,n);
				d = abs(i1-i2);	
				if(cons[i].d<0){
					if(d<-cons[i].d){	flg=false;	break;	}
				}
				else{
					if(d>cons[i].d){	flg=false;	break;	}
				}
			}
			if(flg)	cnt++;
		}while(next_permutation(ar.begin(),ar.end()));
		printf("%d\n",cnt);
		ar.clear();	delete []cons;
	}
	return 0;
}
