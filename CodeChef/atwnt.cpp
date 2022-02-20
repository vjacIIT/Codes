#include<cstdio>
#include<vector>
#include<map>
using namespace std;

vector<int> nochild(1e5+2,0), weight(1e5+2,0), oneChild(1e5+2,0);
vector<vector<int>> graph(1e5+2);
vector<map<int,int>> dp(1e5+2);

int solve(int node, int task){
	if(nochild[node]==1)
		node=oneChild[node];
	if(task%weight[node]==0)
		return 0;
	if(nochild[node]==0)
		return 0;
	if(task%nochild[node]!=0)
		return task;
	int ans=0, nd, freq;
	for(auto x:dp[node]){
		nd=x.first;
		freq=x.second;
		if(task%nd==0)
			ans+=((task/nd)*freq);
		if(task<nd)
			break;
	}
	return task-ans;
}

void dfs(int node){
	int child, freq, nd, nchild=nochild[node], hnode;
	if(nchild==0){	
		dp[node][1]++;										// map [node][1] to frequency
		return;
	}
	if(nchild==1){
		hnode=node;
		while(nochild[hnode]==1)
			hnode=graph[hnode][0];
		
		while(nochild[node]==1){
			oneChild[node]=hnode;
			node=graph[node][0];
		}
		dfs(node);
		return;
	}
	for(int i=0; i<nchild; i++){
		child = graph[node][i];
		dfs(child);
		if(nochild[child]==1)
			child=oneChild[child];
		for(auto x:dp[child]){
			nd = x.first;
			freq = x.second;
			if(nd*nchild>1e6)
				break;
			dp[node][nd*nchild]+=freq;
		}
	}
	return;
}

int gcd(int a, int b){
	if(a==0)
		return b;
	return gcd(b%a,a);
}

int dfs2(int node){
	//printf("node %d\t nochild %d\n",node,nochild[node]);
	if(nochild[node]==0)
		return weight[node] = 1;
	int ans=1, g;
	for(int i=0; i<nochild[node]; i++){
		g = gcd(ans,dfs2(graph[node][i]));
		ans = (ans*weight[graph[node][i]])/g;				// lcm of weight[child] each child
	}
	return weight[node] = (nochild[node]*ans);
}


int main(){
	int n, q, node, task, temp;
	scanf("%d",&n);
	//nochild = vector<int>(n+1,0);			// no of children of each node
	//graph = vector<vector<int>>(n+1);
	//dp = vector<map<int,int>>(n+1);
	//weight = vector<int>(n+1,0);
	for(int i=1; i<n; i++){
		scanf("%d",&temp);
		nochild[temp]++;							// also can be found using graph[i].size
		graph[temp].push_back(i+1);
	}
	dfs2(1);
	dfs(1);
	scanf("%d",&q);
	for(int i=0; i<q; i++){
		scanf("%d%d",&node,&task);
		printf("%d\n",solve(node,task));
	}
	return 0;
}
