// Concept: We need to check if the value in each node lies within the range
// Means all values at left < root->data && all values at right > root->data

#include<iostream>
#include<limits.h>
using namespace std;

struct node{
	int data;
	node *left, *right;
};

bool inRange(int data, int min, int max){
	if(data>min && data<max)	return true;
	return false;
}

bool bstCheck(node *root, int min, int max){
	if(root==NULL)	return true;
	if(inRange(root->data,min,max) && bstCheck(root->left,min,root->data) && bstCheck(root->right,root->data,max))	return true;
	return false;
}

node *crNode(int data){
	node *root = new node;
	root->data = data;
	root->left = NULL;
	root->right = NULL;
	return root;
}

node *insertNode(node *root, int data){
	if(root==NULL){
		root = crNode(data);
		return root;
	}
	else if(root->data>data)	root->left = insertNode(root->left,data);
	else	root->right = insertNode(root->right,data);
	return root;
}

void print(node *root){
	if(root==NULL)	return;
	print(root->left);
	printf("%d ",root->data);
	print(root->right);
	return;
}

int main(){
	node *root;
	root==NULL;
	bool t;
	root=insertNode(root,10);
	root=insertNode(root,15);
	root=insertNode(root,5);
	root=insertNode(root,3);
	root=insertNode(root,4);
	root=insertNode(root,13);
	//print(root);
	t = bstCheck(root,INT_MIN,INT_MAX);
	if(t)	printf("Yes\n");
	else printf("No\n");
	return 0;
}

// TIme complexit is O(n)
// This problem can be solved using inOrder traversal as inorder traveral gives sorted order in BST. 
