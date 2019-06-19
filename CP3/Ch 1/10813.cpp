#include<cstdio>
#include<vector>
using namespace std;

int main(){
	bool win;
	vector<pair<int,int>> vec(76);		//	r,c for each number
	int row[5],column[5],d1,d2,tc,no,r,c,ans;
	scanf("%d",&tc);
	while(tc--){
		win=false;
		for(int i=0; i<5; i++){
			row[i]=0;
			column[i]=0;
		}
		row[2]=1;	column[2]=1;
		d1=1;	d2=1;	ans=0;
		for(int i=0; i<76; i++)	vec[i]=make_pair(-1,-1);	
		for(int i=0; i<5; i++){
			for(int j=0; j<5; j++){
				if(!(i==2 && j==2)){
					scanf("%d",&no);
					vec[no]=make_pair(i,j);
				}
			}
		}
		for(int i=0; i<75; i++){
			scanf("%d",&no);
			r = vec[no].first;		c=vec[no].second;
			if(!win){
				ans++;
				if(r!=-1){
					row[r]++;
					column[c]++;
					if(r==c)	d1++;
					if(r+c==4)	d2++;
					if(row[r]==5 || column[c]==5 || d1==5 || d2==5)	win=true;
				}
			}
		}
		printf("BINGO after %d numbers announced\n",ans);
	}
	return 0;
}
