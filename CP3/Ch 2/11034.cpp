#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

vector<queue<int>> q(2);				// q[0] for left and q[1] for right

int main(){
	char str[10];
	int tc, sf, m, l, cnt, c;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d%d",&sf,&m);			// size of ferry and number of cars coming
		for(int i=0; i<m; i++){
			scanf("%d %s\n",&l,str);
			strcmp(str,"left")==0 ? q[0].push(l):q[1].push(l);  
		}
		c=0;	sf*=100;	cnt=0;			// c stores the side, ferry size in centimeters, count
		while(!(q[0].empty() && q[1].empty())){
			l = 0;
			while(!q[c].empty() && q[c].front()+l<=sf){	l+=q[c].front();	q[c].pop();	}
			c++;	c%=2;	cnt++;
		}
		printf("%d\n",cnt);
	}
	return 0;
}
