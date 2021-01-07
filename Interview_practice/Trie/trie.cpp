#include<cstdio>
#include<iostream>
using namespace std;

class TrieNode{
	public:
		//char c;							// no need of this
		TrieNode* children[26];
		int numChild;
		bool isEndOfWord;
		
		TrieNode(){
			for(int i=0; i<26; i++)
				children[i]=nullptr;
			isEndOfWord = false;
			numChild=0;
		}
		
		void insert(TrieNode &root, string &str){
			TrieNode* temp = &root;
			for(int i=0; i<str.size(); i++){
				int index = str[i]-'a';
				if(temp->children[index]==nullptr){
					temp->children[index] = new TrieNode;
					temp->numChild++;
				}
				temp = temp->children[index];
			}
			temp->isEndOfWord = true;
		}
		
		bool find(TrieNode &root, string &str){
			TrieNode* temp = &root;
			for(int i=0; i<str.size(); i++){
				int index = str[i]-'a';
				if(temp->children[index]==nullptr)
					return false;
				temp = temp->children[index];
			}
			return temp->isEndOfWord;
		}
		
		// 1. String doesn't exist
		// 2. String is the only string in dictionary
		// 3. String is a prefix of a longer string
		// 4. Prefix string exists of String
		
		// if delete return true we can delete the current node, else not 
		bool delete_node(TrieNode* node, string &str, int ind){
			int n = str.size();
			if(n==ind){
				if(node->isEndOfWord){
					node->isEndOfWord=false;
					if(node->numChild==0){				// no children
						delete node;
						return true;
					}
					return false;
				}
				return false;							// string not found
			}
			
			int index = str[ind]-'a';
			if(node->children[index]==nullptr)			// no string
				return false;
			bool check = delete_node(node->children[index], str, ind+1);
			if(check){									// delete return true
				if(ind==0){
					node->children[index]=nullptr;
					return true;
				}
				if(node->numChild==1 && node->isEndOfWord==false){					// had one child which was deleted, also smaller string doesn't exist
					delete node;
					return true;
				}
				else{
					node->numChild--;
					node->children[index]=nullptr;
					return false;
				}
			}
			return false;	
		}
};

int main(){
	TrieNode root;
	string s;
	int n=10;
	for(int i=0; i<n; i++){
		cin>>s;
		root.insert(root,s);
	}
	return 0;
}
