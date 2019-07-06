#include<cstdio>
#include<bitset>
using namespace std;

bitset<1000001> bs;
bool flg;

void func(int st, int end){
	if(!flg){
		for(int i=st; i<end; i++){
			if(i<1000001){
				if(bs[i]!=1)	bs[i]=1;
				else	flg=true;
			}
		}
	}
}

int main(){
	int n, m, st, end, ivl;
	while(scanf("%d%d",&n,&m)!=EOF){
		if(n==0 && m==0)	break;
		bs.reset();		flg=false;
		for(int i=0; i<n; i++){
			scanf("%d%d",&st,&end);
			func(st,end);	
		}
		for(int i=0; i<m; i++){
			scanf("%d%d%d",&st,&end,&ivl);
			while(st<1000001){
				func(st,end);
				st+=ivl;		end+=ivl;
			}
		}
		if(flg)	printf("CONFLICT\n");
		else	printf("NO CONFLICT\n");
	}
	return 0;
}
