#include<cstdio>
#include<cstring>
using namespace std;

int prt[26], rank[26];

int fint(char c){
	return c-'A';
}

int fprt(int i){
	if(prt[i]==i)	return i;
	prt[i]=fprt(prt[i]);
	return prt[i];					// simple path compression
}

void combine(int i1, int i2){
	if(rank[i1]>rank[i2]){
		prt[i2]=i1;	return;
	}
	else{
		prt[i1]=i2;
		rank[i1]==rank[i2] ? rank[i2]++:rank[i2]+=0;
		return;
	}
}

int main(){
	bool psnt[26];
	char str[200], pts[100], b1, b2, cm, c1, c2;
	int tc, l, t, a, i1, i2;
	scanf("%d\n",&tc);
	while(tc--){
		t=0;	a=0;	
		for(int i=0; i<26; i++){	rank[i]=0;	psnt[i]=false;	prt[i]=i;	}
		
		while(fgets(str,100,stdin)){
			if(str[0]=='*')	break;
			sscanf(str,"%c%c%c%c%c",&b1,&c1,&cm,&c2,&b2);
			i1 = fint(c1);	i2=fint(c2);
			i1 = fprt(i1);	i2 = fprt(i2);
			combine(i1,i2);
		}
		
		scanf("%s\n",pts);	l=strlen(pts);
		for(int i=0; i<l; i++){
			if(pts[i]==',')	continue;
			psnt[pts[i]-'A']=true;
		}
		
		for(int i=0; i<26; i++){
			if(psnt[i] && prt[i]==i){
				if(rank[i]==0)	a++;
				else	t++;
			}
		}
		printf("There are %d tree(s) and %d acorn(s).\n",t,a);
	}
	return 0;
}

// Note that input graph is a forest hence each component is a tree with no cycles
