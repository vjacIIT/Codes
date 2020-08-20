#include<iostream>
#include<stdlib.h>
using namespace std;

int ct=0;
bool f=false;

struct node{
	int v, h;
	node *lt;
	node *rt;
	node *pt;
};

int ht(node *root){
	int h1, h2;
	if(root==NULL)	return -1;
	h1 = ht(root->lt);
	h2 = ht(root->rt);
	if(h1>h2)	return h1+1;
	else return h2+1;
}

node *crNode(int v, node *pt){
	node *root;
	root = (node*)malloc(sizeof(node));
	root->v = v;
	root->lt = NULL;
	root->rt = NULL;
	root->h = 0;
	root->pt = pt;
	return root;
}

bool srch(node *root, int v){
	if(root==NULL)	return false;
	else if(root->v==v)	return true;
	else if(root->v>v)	return srch(root->lt,v);
	else 	return srch(root->rt, v);
}

bool blcd(int h1, int h2){
	if(h1-h2>1 || h2-h1>1)	return false;
	return true;
}

node *rr(node *root){
	if(root->pt!=NULL && root->pt->rt==root)		root->pt->rt = root->lt;
	else if(root->pt!=NULL)		root->pt->lt = root->lt;
	root->lt->pt = root->pt;
	root->pt = root->lt;
	root->lt = root->lt->rt;
	if(root->lt!=NULL)	root->lt->pt = root;
	root->pt->rt = root;
	return root->pt;	
}

node *ll(node *root){
	if(root->pt!=NULL && root->pt->rt==root)	root->pt->rt = root->rt;
	else if(root->pt!=NULL)		root->pt->lt = root->rt;
	root->rt->pt = root->pt;
	root->pt = root->rt;
	root->rt = root->rt->lt;
	if(root->rt!=NULL)	root->rt->pt = root;
	root->pt->lt = root;
	return root->pt;
}

node *add(node *root, int v, node *pt){
	bool s;
	int h1, h2;
	s = srch(root, v);
	if(s)		return root;
	else if(root==NULL){
		f = true;
		ct++;
		root = crNode(v, pt);
		return root;
	}
	else if(root->v>v)	root->lt = add(root->lt, v, root);
	else root->rt = add(root->rt, v, root);
	h1 = ht(root->lt);
	h2 = ht(root->rt);
	if(!blcd(h1,h2)){
			if(h1>h2){				// means we have added a root on the left
				if(ht(root->lt->lt)>ht(root->lt->rt)){				// means we have added on the left of left					
					root = rr(root);
					root->rt->h = root->rt->h-1;
				}
				else{
					root->lt = ll(root->lt);
					root = rr(root);
					root->h = root->h+1;
					root->lt->h = root->lt->h-1;
					root->rt->h = root->rt->h-1;
				}
			}
			else{
					if(ht(root->rt->rt)>ht(root->rt->lt)){
						root = ll(root);
						root->lt->h = root->lt->h-1;
					}
					else{
						root->rt = rr(root->rt);
						root = ll(root);
						root->h = root->h+1;
						root->lt->h = root->lt->h-1;
						root->rt->h = root->rt->h-1;
					}
			}
	}
	else if(h1>h2)	root->h = h1+1;
	else		root->h = h2+1; 	
	return root;
}

int main(){
	int *a, *b, n, m;
	node *root;
	root = NULL;
	cin>>n;
	cin>>m;
	a = new int[n];
	b = new int[m];
	for(int i=0; i<n; i++)	cin>>a[i];
	for(int j=0; j<m; j++)	cin>>b[j];
	while(ct<n+m-1){
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				root = add(root, a[i]+b[j], NULL);
				if(f){
					cout<<i<<" "<<j<<endl;
					f=false;
				}
				if(ct==n+m-1)	break;
			}
			if(ct==n+m-1)	break;
		}
	}
	
	return 0;
}
