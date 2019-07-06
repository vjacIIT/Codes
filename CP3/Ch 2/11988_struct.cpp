#include<cstdio>
#include<cstring>
using namespace std;

struct node{
	char c;
	node *next;
};

node *root, *end, *mid;

node *crNode(char c){
	node *nd;	nd = new node;
	nd->c = c;	nd->next=NULL;
	return nd;
}

int main(){
	int i, l;
	char c;
	char str[100000];
	node *temp;
	while(scanf("%s",str)!=EOF){
		i=0;	l=strlen(str);		root=NULL;	end=NULL;	mid=NULL;
		while(str[i]=='[' || str[i]==']')	i++;
		c='e';						// insert at the end
		while(i<l){
			if(str[i]=='[')	c='s';				// inset at the start	
			else if(str[i]==']')	c='e';
			else{
				temp=crNode(str[i]);
				if(c=='s'){
					temp->next = root;
					root=temp;	mid=root;
					c='m';
				}
				else if(c=='m'){							// insert in middle
					temp->next = mid->next;
					mid->next = temp;
					mid=temp;
				}
				else{
					if(root==NULL){
						end=temp;
						root=end;
					}
					else{
						end->next = temp;
						end=temp;	end->next=NULL;
					}
				}
			}
			i++;
		}
		while(root!=NULL){	printf("%c",root->c);	root=root->next;	}
		printf("\n");
	}
	return 0;
}

// So three cases were possible, either insert at end, middle and starting
// All the cases are seperately handled
// Best way is to use list, easy and bug free, but list implementation is slower
// 0.09s with structure and 0.21s with list
