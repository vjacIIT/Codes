#include<cstdio>
using namespace std;

int main(){
	int tc,np,no,nd,ar[101],st,end,*player;
	bool flg;
	scanf("%d",&tc);
	while(tc--){
		flg=false;			// determine if game has ended or not
		for(int i=0; i<101; i++)	ar[i]=-1;	// no path from i'th square
		
		scanf("%d%d%d",&np,&no,&nd);	// players,obstacles,dices_roll
		
		player = new int[np];			// stores position of each player
		for(int i=0; i<np;	i++)	player[i]=1;	// start position
		
		for(int i=0; i<no; i++){
			scanf("%d%d",&st,&end);		
			ar[st]=end;					// stores the position of obstacles
		}
		
		for(int i=0; i<nd; i++){
			scanf("%d",&no);
			if(!flg){
				player[i%np]+=no;
				if(player[i%np]>=100){
					player[i%np]=100;
					flg=true;		// game ended;
				}
				if(!flg && ar[player[i%np]]!=-1)	player[i%np]=ar[player[i%np]];
				if(player[i%np]>=100){
					player[i%np]=100;
					flg=true;		// game ended;
				}
			}		
		}
		for(int i=0; i<np; i++)	printf("Position of player %d is %d.\n",i+1,player[i]);
		delete []player;
	}
	return 0;
}
