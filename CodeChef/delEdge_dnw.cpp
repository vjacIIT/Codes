// Input a tree and values to each node
// delete an edge so that absolute difference of sum of the two components is min 

#include<iostream>
#include<vector>
#include<limits.h>
#include<set>
#include<iterator>
using namespace std;

vector<bool> vis;
vector<long int> val;
vector<vector<int>> gr(100000);		// graph
vector<long int> ssum;		// stores weight of subtree including it's own weight
set<pair<long int,int>> st;		// contains subset sum and node value
vector<int> prt;
	
long int dfs(long int a){
	long int sum, l,i=0;
	sum = val[a];
	l = gr[a].size();
	vis[a]=true;
	while(l--){
		if(!vis[gr[a][i]])	sum+=dfs(gr[a][i]);
		i++;
	}
	ssum[a]=sum;		// if a is removed from it's parent, sum=sum of subtree+it's value
	return sum;
}

void dfs2(int a){
	int l,i=0;
	set<pair<long int,int>>::iterator it2;
	l = gr[a].size();
	while(l--){
		if(!vis[gr[a][i]]){
			it2 = st.find(make_pair(ssum[gr[a][i]],gr[a][i]));
			st.erase(it2);
			vis[gr[a][i]]=true;
			dfs2(gr[a][i]);
		}
		i++;
	}
	return;
}

int main(){
	long int n, v, v1, v2, sval, k, X, tc;
	set<pair<long int,int>>::iterator it, it2;
	cin>>tc;
	while(tc--){
		k=1;
		cin>>n>>X;
		for(int i=0; i<n; i++){
			cin>>v;
			val.push_back(v);
			vis.push_back(false);
			ssum.push_back(INT_MIN);
			prt.push_back(0);
		}
		for(int i=1; i<n; i++){
			cin>>v1>>v2;
			if(v1<v2)	prt[v2-1]=v1-1;
			else	prt[v1-1]=v2-1;
			gr[v1-1].push_back(v2-1);
			gr[v2-1].push_back(v1-1);
		}
		sval = dfs(0);		// sum of all the values	
		// means if root is removed form it's hypothetical parent what will be the sum of it's subtree including the root
		for(int i=0; i<n; i++)	vis[i]=false;
		for(int i=0; i<n; i++)	st.insert(make_pair(ssum[i],i));	
		while(!st.empty()){
			it = st.begin();		// gives the minimum
			if((it->first)<-k*X){
				sval = sval-(it->first)-k*X;
				k++;
				vis[it->second]=true;
				v = prt[it->second];
				//cout<<v<<endl;
				while(vis[v]!=true){			// because subtree sum of it's parent will change
					it2 = st.find(make_pair(ssum[v],v));
					st.erase(it2);
					vis[v]=true;	// we are not going to remove it's parent 
					v=prt[v];
				}
				dfs2(it->second);		// subtree nodes has to be visited
				st.erase(it);
			}
			else	break;
		}
		cout<<sval<<endl;
		vis.clear();
		val.clear();
		for(int i=0; i<n; i++)	gr[i].clear();
		//gr.clear();
		ssum.clear();
		st.clear();
	}
	return 0;
}
