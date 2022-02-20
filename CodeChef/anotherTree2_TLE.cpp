#include<cstdio>
#include<vector>
#include<map>
#include<cmath>
#include<algorithm>
using namespace std;

vector<long long> nochild, weight;
vector<vector<int>> graph;
vector<map<int,int>> dp2;
vector<int> dp(4*1e8,-1);
int n, w;
bool b;

int solve(int node, long long task){
	long long ans=0;
	if(task%weight[node]==0)
		return 0;
	if(nochild[node]==0)
		return 0;								// all tasks done
	if(task%nochild[node]!=0)
		return task;							// none of the task is done
	
	if(b){
		int no = (node-1)*w + task;
		if(dp[no]!=-1)
			return dp[no];
		
		for(int i=0; i<nochild[node]; i++)
			ans+=solve(graph[node][i],task/nochild[node]);
		
		return dp[no]=ans;
	}
	else{
		if(dp2[node].find(task)!=dp2[node].end())
			return dp2[node][task];	
	
		for(int i=0; i<nochild[node]; i++)
			ans+=solve(graph[node][i],task/nochild[node]);
		
		return dp2[node][task]=ans;
	}
}

long long gcd(long a, long b){
	if(a==0)
		return b;
	return gcd(b%a,a);
}

long long dfs(int node){
	//printf("node %d\t nochild %d\n",node,nochild[node]);
	if(nochild[node]==0)
		return weight[node] = 1;
	long long ans=1, g;
	for(int i=0; i<nochild[node]; i++){
		g = gcd(ans,dfs(graph[node][i]));
		ans = (ans*weight[graph[node][i]])/g;				// lcm of weight[child] each child
	}
	return weight[node] = (nochild[node]*ans);
}

int main(){
	int q, node, task, temp;
	scanf("%d",&n);
	nochild = vector<long long>(n+1,0);			// no of children of each node
	graph = vector<vector<int>>(n+1);
	weight = vector<long long>(n+1,0);
	dp2 = vector<map<int,int>>(n+1);
	for(int i=1; i<n; i++){
		scanf("%d",&node);
		nochild[node]++;							// also can be found using graph[i].size
		graph[node].push_back(i+1);
	}
	dfs(1);
	//dp = vector<int>(1e8,-1);
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
	w = -1;
	vector<pair<int,int>> tasks;
	tasks = vector<pair<int,int>>(q);
	for(int i=0; i<q; i++){
		scanf("%d%d",&tasks[i].first,&tasks[i].second);
		w = max(w,tasks[i].second);
		//printf("%d\n",solve(node,task));
	}
	b = (long long)n*(long long)w < 4*1e8;
	for(int i=0; i<q; i++)
		printf("%d\n",solve(tasks[i].first,tasks[i].second));
	return 0;
}
