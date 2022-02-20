#include<cstdio>
#include<vector>
using namespace std;

vector<int> prt, nochild, weight;
vector<vector<int>> graph;

int solve(int node, int task){
	int ans=0;
	if(task%weight[node]==0)
		return 0;
	if(nochild[node]==0)
		return 0;								// all tasks done
	if(task%nochild[node]!=0)
		return task;							// none of the task is done
	for(int i=0; i<nochild[node]; i++)
		ans+=solve(graph[node][i],task/nochild[node]);
		
	return ans;
}

int gcd(int a, int b){
	if(a==0)
		return b;
	return gcd(b%a,a);
}

int dfs(int node){
	//printf("node %d\t nochild %d\n",node,nochild[node]);
	if(nochild[node]==0)
		return weight[node] = 1;
	int ans=1, g;
	for(int i=0; i<nochild[node]; i++){
		g = gcd(ans,dfs(graph[node][i]));
		ans = (ans*weight[graph[node][i]])/g;				// lcm of weight[child] each child
	}
	return weight[node] = (nochild[node]*ans);
}

int main(){
	int n, q, node, task, temp;
	scanf("%d",&n);
	prt = vector<int>(n+1,1);				// 1 is parent of itself
	nochild = vector<int>(n+1,0);			// no of children of each node
	graph = vector<vector<int>>(n+1);
	weight = vector<int>(n+1,0);
	for(int i=1; i<n; i++){
		scanf("%d",&prt[i+1]);
		nochild[prt[i+1]]++;							// also can be found using graph[i].size
		graph[prt[i+1]].push_back(i+1);
	}
	dfs(1);
	vector<bool> vis = vector<bool>(n+1,false);
	for(int i=1; i<=n; i++){
		if(!vis[i]){
			vis[i] = true;
			if(nochild[i]==1){
				node = i;
				while(nochild[node]==1)
					node = graph[node][0];
				graph[i][0] = node;							// direct connection
				q = i;
				while(nochild[q]==1){
					vis[q]=true;
					temp = graph[q][0];
					graph[q][0]=node;
					q = temp;
				}
			}
		}
	}
	//for(int i=1; i<=n; i++)
		//printf("%d\n",weight[i]);
	scanf("%d",&q);
	for(int i=0; i<q; i++){
		scanf("%d%d",&node,&task);
		printf("%d\n",solve(node,task));
	}
	return 0;
}
