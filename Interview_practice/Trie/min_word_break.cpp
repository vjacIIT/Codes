// Given a dictionary and one string, break the string using spaces 
// such that:
//			MIN spaces are required and each individual string belongs to dictionary
//			print the MIN breaks needed


#include<cstdio>
#include<iostream>
#include<climits>
#include<cmath>
using namespace std;

class TrieNode{
	public:
		TrieNode* children[26];
		bool end;
		int noChild;
		static int minBreak;
		TrieNode(){
			for(int i=0; i<26; i++)
				children[i]=nullptr;
			noChild=0;
			end=false;
		}
		
		void insert(TrieNode &root, string &str){
			TrieNode* temp = &root;
			for(int i=0; i<str.size(); i++){
				int ind = str[i]-'a';
				if(temp->children[ind]==nullptr){
					temp->children[ind] = new TrieNode;
					temp->noChild++;
				}
				temp = temp->children[ind];
			}
			temp->end = true;
			return;
		}
		
		bool find(TrieNode &root, string &str){
			TrieNode* temp = &root;
			for(int i=0; i<str.size(); i++){
				int ind = str[i]-'a';
				if(temp->children[ind]==nullptr)
					return false;
				temp = temp->children[ind];
			}
			return temp->end;
		}
		
		bool delete_node(TrieNode* node, string &str, int index){
			if(index==str.size()){
				if(node->end){
					node->end = false;
					if(node->noChild==0){
						delete node;
						return true;
					}
					else
						return false;
				}
				else
					return false;
			}
			
			int ind = str[index]-'a';
			if(node->children[ind]==nullptr)
				return false;
			
			bool check = delete_node(node->children[ind], str, index+1);
			if(check){
				if(index==0){
					node->children[ind]=nullptr;
					return true;
				}
				if(node->noChild==1 && node->end==false){
					delete node;
					return true;
				}
				else{
					node->noChild--;
					node->children[ind]=nullptr;
					return false;
				}
			}
			else
				return false;
		}
		
		int min_break(TrieNode* root, string s, int index, int noBreak){
			if(index==s.size())
				return noBreak-1;
			
			TrieNode* node = root;
			for(int i=index; i<s.size(); i++){
				int ind = s[i]-'a';
				if(node->children[ind]==nullptr)
					return INT_MAX-s.size();
				node = node->children[ind];
				if(node->end){
					ind = min_break(root,s,i+1,noBreak+1);
					minBreak = min(minBreak,ind);
				}
			}
			return minBreak;
		}
};

int TrieNode::minBreak=INT_MAX;

int main(){
	TrieNode root;
	string s;
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>s;
		cout<<s<<" ";
		root.insert(root,s);		
	}
	cin>>s;
	cout<<"\n"<<s<<endl;
	n = root.min_break(&root,s,0,0);
	printf("%d\n",TrieNode::minBreak);
	return 0;
}

// Idea is to break at every possible word and then do recursion
// Store the current number of Breaks and return when you reach end
