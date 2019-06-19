#include<iostream>
using namespace std;

int main(){
	bool safe[101];
	int m,x,y,hno,cnt,tc;
	scanf("%d",&tc);
	while(tc--){
		cnt=0;
		scanf("%d%d%d",&m,&x,&y);
		for(int i=0; i<101; i++)	safe[i]=true;
		for(int i=0; i<m; i++){
			scanf("%d",&hno);
			for(int j=hno; j<=hno+x*y; j++){
				if(j>100)	break;
				safe[j]=false;
			}
			for(int j=hno; j>=hno-x*y; j--){
				if(j<0)	break;
				safe[j]=false;
			}
		}
		for(int i=1; i<101; i++)	if(safe[i])	cnt++;
		printf("%d\n",cnt);
	}
	return 0;
}

// We can use dp to store the previous and next cop house for each house
