// Using the path relaxation property, we can say that if we relax the sortest path of n-1 edges in one specific order, then we get the d(u) to be the delta value, irrespective of the any number of relaxation in between

#include<bits/stdc++.h>
using namespace std;

struct node{
	int v, w;
	node *link;
};

node *crNode(int v, int w){
	node *root;
	root = new node;
	root->v = v;
	root->w = w;
	root->link = NULL;
	return root;
}

node *addNode(node *root, int v, int e){
	node *nd;
	if(root==NULL){
		root = crNode(v, e);
		return root;
	}
	nd = crNode(v,e);
	nd->link = root;
	root = nd;
	return root;
}

int *d;
int *prt, n, m;
node **lst;

void relax(int u, int v, int w){
	if(d[u]!=INT_MAX && d[u]+w<d[v]){
		d[v]=d[u]+w;
		prt[v]=u;
	}
	return;
}

void print(node *root){
	while(root!=NULL){
		printf("%d ", root->v);
		root=root->link;
	}
	cout<<"\n";
	return;
}

bool bellman_ford(int s){
	node *root;
	d[s]=0;
	
	for(int j=0; j<n; j++){		//O(n) time
		for(int i=0; i<n; i++){			//Both loop total O(m) time
			root = lst[i];			// root goes to the corresponding linked list
			while(root!=NULL){
				relax(i, root->v, root->w);
				root = root->link;
			}
		}
	}
	for(int i=0; i<n; i++){
			root=lst[i];
			while(root!=NULL){
				if(d[i]!=INT_MAX && d[i]+root->w<d[root->v])	return false;	// found a negative weight cycle
				root=root->link;
			}
	}
	return true;
}

int main(){
	int x, y, e, s;
	bool ans;
	cin>>n>>m;
	d = new int[n];
	prt = new int[n];
	lst = new node*[n];
	for(int i=0; i<n; i++){
		d[i]=INT_MAX;
		prt[i]=-1;
		lst[i]=NULL;
	}
	while(m--){
		cin>>x>>y>>e;
		lst[x]=addNode(lst[x], y, e);
		lst[y]=addNode(lst[y], x, e);
	}
	cin>>s;
	ans = bellman_ford(s);
		
	if(ans){
		for(int i=0; i<n; i++)	cout<<d[i]<<" ";
		cout<<"\n";
	}
	else	cout<<"Negative weight cycle\n";
	return 0;
}
