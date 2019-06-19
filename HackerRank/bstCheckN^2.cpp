// Given root of binary tree, we need to check that tree is BST or not
 
// Concept: Check if all the values on the left subtree are smaller than the current node value and all the values on the right subtree are greater than the current node value and also that this holds for left as well as right subtree, then it is a BST.

#include<iostream>
using namespace std;

struct node{
	int data;
	node *left, *right;
};

bool isSmaller(node *root, int data){
	if(root==NULL)	return true;
	if(root->data>=data)	return false;
	return (isSmaller(root->left,data) && isSmaller(root->right,data));
}

bool isGreater(node *root, int data){
	if(root==NULL)	return true;
	if(root->data<=data)	return false;
	return (isGreater(root->left,data) && isGreater(root->right,data));
}

bool checkBst(node *root){
	if(root==NULL)	return true;
	if(isSmaller(root->left,root->data) && isGreater(root->right,root->data) && checkBst(root->left) && checkBst(root->right))	return true;
	return false;
}

node *crNode(int data){
	node *root;
	root = new node;
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
	t = checkBst(root);
	if(t)	printf("Yes\n");
	else printf("No\n");
}

// Time complexity is O(n^2) in this, as it is doing isSmaller()/isGreater in O(n) time on each node
// There is overlapping intervals, we are checking same thing again and again
