#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

vector<vector<int>> graph(300000);			// maximum 300000 vertices
vector<bool> vis;
vector<bool> inPath;			// either that vertex is in path u-v
vector<int> prt;				// stores the parent
long int cnt;
vector<pair<long int,long int>> value;			// no of vertices , sum 

void dfs(int u, int v){			// u changes, v is the final goal
	vis[u]=true;
	if(u==v)	return;
	for(auto it=graph[u].begin(); it!=graph[u].end(); it++){
		if(!vis[*it]){
			prt[*it]=u;
			dfs(*it,v);
		}
	}
	return;
}

void dfs3(int i){
	vis[i]=true;
	cnt++;
	for(auto it=graph[i].begin(); it!=graph[i].end(); it++){
		if(!vis[*it])	dfs3(*it);
	}
	return;
}

long int dfs2(int i){
	value.clear();
	int l;
	for(auto it=graph[i].begin(); it!=graph[i].end(); it++){
		if(!vis[*it]){
			cnt=0;
			dfs3(*it);
			value.push_back(make_pair(cnt,0));		// num of vertices
		}
	}
	cnt=1;		
	l = value.size();	
	if(l!=0)	value[l-1].second=1;
	for(int i=l-2; i>=0; i--)	value[i].second=value[i+1].first+value[i+1].second;
	for(int i=0; i<l; i++)	cnt+=value[i].first*value[i].second;
	return cnt;
}

int main(){
	long int ans;
	int tc, n, q, u, v;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d%d",&n,&q);
		vis = vector<bool> (n,false);
		inPath = vector<bool> (n,false);			// initialization
		prt = vector<int> (n,-1);
		
		for(int i=0; i<n-1; i++){
			scanf("%d%d",&u, &v);
			u--;		v--;					// input graph
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		
		for(int i=0; i<q; i++){
			scanf("%d%d",&u,&v);
			u--;		v--;
			dfs(u,v);							// dfs on the graph for parent finding
			
			prt[u]=u;
			while(prt[v]!=v){
				inPath[v]=true;					// use of parent to find vertices in path
				v=prt[v];
			}
			inPath[v]=true;
			
			for(int i=0; i<n; i++){
				if(!inPath[i])	vis[i]=false;		// not in path vis=false
			}
			
			ans=0;			
			for(int i=0; i<n; i++){
				if(inPath[i])	ans+=dfs2(i);
			}
			
			printf("%ld\n",ans);
			for(int i=0; i<n; i++){	inPath[i]=false;	vis[i]=false;	prt[i]=-1;}
		}
		for(int i=0; i<n; i++)	graph[i].clear();
		vis.clear();
		inPath.clear();
		prt.clear();
	}	
	return 0;
}
