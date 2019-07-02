// This is the better approach of using a set. First store all the vertices in the set with infinity distance (INT_MAX), then relax in order until the set is empty 
// Set sorts according to the first parameter in it, which is distance in it

#include<bits/stdc++.h>
using namespace std;

struct node{
	int v, w;
	node *link;
};

set<pair<int, int>> st;				// global set
node **lst;
int *d, n, m, *prt;		// stores the distance and parent vertices

node *crNode(int v, int w){
	node *root;
	root = (node*)malloc(sizeof(node));
	root->v = v;
	root->w = w;
	root->link = NULL;
	return root;
}

node *addNode(node *root, int v, int w){
	node *nd;
	if(root==NULL){
		root = crNode(v, w);
		return root;
	}
	nd = crNode(v, w);
	nd->link = root;
	root = nd;
	return root;
}

void relax(int u, int v, int w){
	if(d[u]!=INT_MAX && d[u]+w<d[v]){		// d[u] = INT_MAX if u is unreachable from the source s
		st.erase(make_pair(d[v], v));		// d[v] can be INT_MAX or any specific value
		st.insert(make_pair(d[u]+w, v));
		d[v]=d[u]+w;
		prt[v]=u;
		return;
	}
	return;
}

void dijkstra(int s){
	node *pt;
	set<pair<int, int>>::iterator it;		// iterator of type pair<int, int>
	d[s]=0;
	st.erase(make_pair(INT_MAX, s));		//erase the source vertex and replace its distance by 0
	st.insert(make_pair(0, s));
	while(!st.empty()){				// untill the set becomes empty (i.e. we have computed distance of all the vertices from source s), we will keep poping out the elements
		it = st.begin();				// this node's distance have been calculated or it is unreachable from source s
		pt = lst[it->second];			// stores the pointer, second is the vertex
		while(pt!=NULL){
			relax(it->second, pt->v, pt->w);
			pt=pt->link;
		}
		st.erase(it);		// erasing the node
	}
	return;
}

int main(){
	int t, x, y, e, s;
	cin>>t;
	while(t--){
		scanf("%d%d", &n, &m);
		d = new int[n];
		prt = new int[n];
		lst = new node*[n];
		for(int i=0; i<n; i++){
			lst[i]=NULL;
			d[i]=INT_MAX;
			prt[i]=-1;
		}
		
		for(int i=0; i<m; i++){
			scanf("%d%d%d", &x, &y, &e);
			lst[x]=addNode(lst[x], y, e);
			lst[y]=addNode(lst[y], x, e);
		}
		cin>>s;			// As the set sorts the pair in ascending order according to the first element, therefore we have put distance as the first parameter and vertex as the second parameter
		for(int i=0; i<n; i++)	st.insert(make_pair(INT_MAX, i));		// intially st is the set containing all the vertices with distance INT_MAX
		dijkstra(s);
		for(int i=0; i<n; i++)	cout<<d[i]<<" ";
		cout<<endl;
		st.clear();
	}
	return 0;
}
