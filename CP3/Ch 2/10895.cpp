#include<cstdio>
#include<vector>
using namespace std;

vector<vector<pair<int,int>>> g;

int main(){
	vector<int>	h;
	int m, n, no, val, s;			// rows, column
	while(scanf("%d%d",&m,&n)!=EOF){
		g = vector<vector<pair<int,int>>>(n+1);
		for(int i=1; i<=m; i++){
			scanf("%d",&no);
			h = vector<int>(no);
			for(int j=0; j<no; j++)	scanf("%d",&h[j]);			// stores column no
			for(int j=0; j<no; j++){	
				scanf("%d",&val);
				g[h[j]].push_back(make_pair(i,val));
			}
			h.clear();
		}
		printf("%d %d\n",n,m);
		for(int i=1; i<=n; i++){
			s = g[i].size();	printf("%d",s);
			for(int j=0; j<s; j++)	printf(" %d",g[i][j].first);	printf("\n");
			for(int j=0; j<s; j++){	
				printf("%d",g[i][j].second);	
				if(s-j-1)	printf(" ");
			}
			printf("\n");
		}
		g.clear();
	}
	return 0;
}
