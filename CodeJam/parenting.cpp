#include<cstdio>
#include<vector>
using namespace std;

vector<vector<int>> gph;
vector<vector<int>> v;
vector<int> color;
vector<bool> vtd;
bool poss;
int n;

bool overlap(int n1, int n2){
	int s1=v[n1][0], e1=v[n1][1], s2=v[n2][0], e2=v[n2][1];
	if(s2<=s1 && e2>s1)
		return true;
	if(s2>=s1 && s2<e1)
		return true;
	return false;
}

void search(int nd, int clr){						// clr which needs to be put on all children of n
	int node;
	for(int i=0; i<gph[nd].size(); i++){
		node = gph[nd][i];
		if(!vtd[node]){
			vtd[node] = true;
			color[node] = clr;
			search(node,1-clr);					// parent color clr, all children with color 1-clr
			if(!poss)
				return;
		}
		else if(color[node]!=clr){
			poss = false;
			return;	
		}
	}
	return;
}

void dfs(){
	for(int i=0; i<n; i++){
		if(!vtd[i]){
			vtd[i] = true;
			color[i] = 1;						// means 'J'
			search(i,0);						// put all the childrens with color 0 'C'
			if(!poss)
				return;
		}
	}
}

char mycolor(int i){
	return i==1 ? 'J' : 'C';
}

int main(){
	int tc;
	scanf("%d",&tc);
	for(int t=1; t<=tc; t++){
		poss = true;
		scanf("%d",&n);
		v = vector<vector<int>>(n,vector<int>(2));
		gph = vector<vector<int>>(n);
		color = vector<int> (n,-1);						// -1 means no color
		vtd = vector<bool>(n,false);
		for(int i=0; i<n; i++)
			scanf("%d%d",&v[i][0],&v[i][1]);
		
		for(int i=0; i<n; i++){
			for(int j=i+1; j<n; j++){
				if(overlap(i,j)){						// if intervals overlap make an edge
					gph[i].push_back(j);
					gph[j].push_back(i);
				}
			}
		}
		
		/*for(int i=0; i<n; i++){
			printf("FOR %d -> ",i);	
			for(int j=0; j<gph[i].size(); j++)
				printf("%d ",gph[i][j]);
			printf("\n");
		}*/
		
		dfs();
		printf("Case #%d: ",t);
		if(!poss)
			printf("IMPOSSIBLE");
		else
			for(int i=0; i<n; i++)
				printf("%c",mycolor(color[i]));
		printf("\n");
		v.clear();
		gph.clear();
		color.clear();
		vtd.clear();
	}
	return 0;
}

// If vertex coloring with 2 colors is possible then possible solution is there
// This works, but it seems like O(nlogn) is also there
