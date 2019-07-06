#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

vector<queue<pair<int,int>>> q(2);				// q[0] for left and q[1] for right
int t1, t2;								

void time(int c){
	t1 = q[c].empty() ? 100001:q[c].front().second;				// time of first car at current side	
	t2 = q[(c+1)%2].empty() ? 100001:q[(c+1)%2].front().second;	// time of first car at opposite side
}

int main(){
	vector<int> v;
	char str[10];
	int tc, sf, ct, m, t, tm, c, size;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d%d%d",&sf,&ct,&m);			// size of ferry, crossing time and number of cars coming
		v = vector<int>(m);
		for(int i=0; i<m; i++){
			scanf("%d %s\n",&t,str);
			strcmp(str,"left")==0 ? q[0].push(make_pair(i,t)):q[1].push(make_pair(i,t));  
		}
		t=0;	c=0;						// stores current time, c stores the side
		while(!(q[0].empty() && q[1].empty())){
			time(c);	size=0;				// number of cars
			if(t1<=t){						// there is car at the current side
				while(size<sf && t1<=t){
					v[q[c].front().first]=t+ct;
					q[c].pop();	size++;
					t1 = q[c].empty() ? 100001:q[c].front().second;
				}
			}
			else{							// no car at current side
				if(t1<=t2){					// new car arrives at current side first
					t=t1;
					while(size<sf && t1==t){
						v[q[c].front().first]=t+ct;
						q[c].pop();	size++;
						t1 = q[c].empty() ? 100001:q[c].front().second;
					}
				}
				else{						// we need to go to other side
					if(t2>t)	t=t2;
				}
			}
			t+=ct;	c++;	c%=2;
		}
		for(int i=0; i<m; i++)	printf("%d\n",v[i]);
		if(tc)	printf("\n");
	}
	return 0;
}
