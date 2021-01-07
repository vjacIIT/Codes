// Given an array of strings, print them in lexographical order

#include<cstdio>
#include<iostream>
using namespace std;

class TrieNode{
	public:
		TrieNode* children[26];
		int numChild;
		bool end;
		TrieNode(){
			for(int i=0; i<26; i++)
				children[i]=nullptr;
			end=false;
			numChild = 0;
		}
		
		void insert(TrieNode &root, string &str){
			TrieNode* temp = &root;
			for(int i=0; i<str.size(); i++){
				int index = str[i]-'a';
				if(temp->children[index]==nullptr){
					temp->numChild++;
					temp->children[index] = new TrieNode;
				}
				temp = temp->children[index];
			}
			temp->end = true;
			return;
		}
		
		bool search(TrieNode &root, string &str){
			TrieNode* temp = &root;
			for(int i=0; i<str.size(); i++){
				int index = str[i]-'a';
				if(temp->children[index]==nullptr)
					return false;
				temp = temp->children[index];
			}
			return temp->end;
		}
		
		bool delete_node(TrieNode* node, string &str, int index){
			if(index==str.size()){
				if(node->end){
					node->end = false;
					if(node->numChild==0){
						delete node;
						return true;
					}
					else
						return false;
				}
				else												// string doesn't exists
					return false;
			}
			
			int ind = str[index]-'a';
			if(node->children[ind]==nullptr)						// string doesn't exists
				return false;
			
			bool check = delete_node(node->children[ind],str,index+1);
			if(check){
				if(index==0){
					node->children[ind]=nullptr;
					return true;
				}
				if(node->numChild==1 && node->end==false){
					delete node;
					return true;
				}
				else{
					node->numChild--;
					node->children[ind]=nullptr;
					return false;
				}
			}
			else
				return false;
		}
		
		void print(TrieNode* node, string s){
			int a = 'a';
			if(node->end)
				cout<<s<<"\n";
			for(int i=0; i<26; i++){
				if(node->children[i]!=nullptr)
					print(node->children[i], s+char(a+i));
			}
			return;
		}
};

int main(){
	TrieNode root;
	string s;
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>s;
		root.insert(root,s);
	}
	root.print(&root,"");
	return 0;
}

// Insert all the strings in a trie, then do preorder traversal in trie
