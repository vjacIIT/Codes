#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;

int r, c, cnt, pcnt;
char str[40000];
vector<vector<int>> vv;

void decompose(int sr, int sc, int er, int ec){
	if(sr>er || sc>ec)
		return;
	int mr, mc, cnt0=0, cnt1=0;
	mr = er-sr+1;
	mc = ec-sc+1;
	for(int i=sr; i<=er; i++){
		for(int j=sc; j<=ec; j++){
			cnt1+=vv[i][j];
			cnt0+=1-vv[i][j];
		}
	}
	if(pcnt!=0 && pcnt%50==0)
		printf("\n");
	pcnt++;
	if(cnt1==mr*mc){
		printf("1");
		return;
	}
	else if(cnt0==mr*mc){
		printf("0");
		return;
	}

	printf("D");
	mr=(sr+er)/2;
	mc=(sc+ec)/2;	
	decompose(sr,sc,mr,mc);
	decompose(sr,mc+1,mr,ec);
	decompose(mr+1,sc,er,mc);
	decompose(mr+1,mc+1,er,ec);
	return;
}

void combine(int sr, int sc, int er, int ec){
	if(cnt==strlen(str) || sr>er || sc>ec)
		return;
	int mr, mc;
	mr = (er+sr)/2;
	mc = (ec+sc)/2;
	if(str[cnt]=='D'){
		cnt++;
		combine(sr,sc,mr,mc);
		combine(sr,mc+1,mr,ec);
		combine(mr+1,sc,er,mc);
		combine(mr+1,mc+1,er,ec);
		return;
	}
	for(int i=sr; i<=er; i++)
		for(int j=sc; j<=ec; j++)
			vv[i][j]=str[cnt]-'0';
	cnt++;
	return;
}

int main(){
	char tp, strg[4000];
	while(fgets(strg,25,stdin)){
		pcnt=0;
		if(strg[0]=='#')
			break;
		sscanf(strg,"%c%d%d\n",&tp,&r,&c);
		vv = vector<vector<int>>(r,vector<int>(c));
		if(tp=='B'){
			cnt=0;
			while(cnt<r*c){
				fgets(strg,40000,stdin);
				for(int i=0; i<strlen(strg)-1; i++){
					str[cnt]=strg[i];
					cnt++;
				}
			}
			for(int i=0; i<r; i++)
				for(int j=0; j<c; j++)
					vv[i][j]=str[i*c + j]-'0';
			printf("D%4d%4d\n",r,c);
			decompose(0,0, r-1,c-1);
			printf("\n");
		}
		else{
			fgets(strg,40000,stdin);
			for(int i=0; i<strlen(strg)-1; i++)
				str[i]=strg[i];
			cnt=0;
			printf("B%4d%4d\n",r,c);
			combine(0,0, r-1, c-1);
			for(int i=0; i<r; i++){
				for(int j=0; j<c; j++){
					printf("%d",vv[i][j]);
					pcnt++;
					if(pcnt%50==0)
						printf("\n");
				}
			}
			if(pcnt%50)
				printf("\n");
		}
	}
	return 0;
}
