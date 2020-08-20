#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int rr, rc, cnt;
vector<int> row(8,-1);

bool check(int r, int c){
	int i, d1, d2;
	if(row[c]!=-1)	return false;
	for(i=0; i<c; i++){
		if(row[i]==r)	return false;
		d1=abs(c-i);	d2=abs(row[i]-r);
		if(d1==d2)	return false;	
	}
	return true;
}

void permute(int c){
	int i;
	if(c==8){					// reached end
		if(row[rc]==rr){
			if(cnt<10)	printf(" ");
			printf("%d      ",cnt);
			cnt++;
			for(i=0; i<8; i++){
				if(i)	printf(" ");
				printf("%d",row[i]+1);
			}
			printf("\n");
		}
	}
	for(i=0; i<8; i++){
		if(check(i,c)){
			row[c]=i;
			permute(c+1);
			row[c]=-1;
		}
	}
	return;
}

int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d%d",&rr,&rc);
		rr--;	rc--;	cnt=1;
		printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n\n");
		permute(0);
		if(tc)	printf("\n");
	}
	return 0;
}
