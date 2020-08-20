#include<cstdio>
#include<vector>
using namespace std;

int n;
bool match;
int led[]={ 126, 48, 109, 121, 51, 91, 95, 112, 127, 123 };
vector<vector<int>> istr;

void solve(int no, int i, int fused){
	if(i==n){					// we have found one match
		match=true;	return;	
	}
	int bit1, bit2, bit3;
	for(int j=0; j<7; j++){
		bit1 = led[no]&(1<<j);
		bit2 = istr[i][6-j];
		bit3 = fused&(1<<j);
		if(bit3 && bit2)
			return;					// should be fused, but still glowing
		if(!bit1){
			if(bit2)	
				return;				// if need not to glow, but still glowing
		}
		else
			if(!bit2)
				fused|=(1<<j);
	}
	solve(no-1,i+1,fused);
	return;
}

int main(){
	char c;
	while(scanf("%d",&n)!=EOF){
		match=false;
		if(!n)	break;
		scanf("\n");
		istr = vector<vector<int>>(n,vector<int>(7));
		for(int i=0; i<n; i++){
			if(i)	scanf("%c",&c);
			for(int j=0; j<7; j++){
				scanf("%c",&c);
				c=='Y'	? istr[i][j]=1:istr[i][j]=0;
			}
		}
		for(int i=9; i>=n-1; i--)
			solve(i,0,0);									// i gives the starting first value
		
		for(int i=0; i<n; i++)	istr[i].clear();	
		istr.clear();
		if(match)	printf("MATCH\n");
		else	printf("MISMATCH\n");
	}
	return 0;
}
