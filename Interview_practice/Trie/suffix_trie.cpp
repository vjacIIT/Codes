// Given a string s and patter p, find the number of occurences of p in s
// Can be done using KMP

#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

class TrieNode{
	public:
		TrieNode* children[26];
		vector<int> suff_index;												// stores starting index of suffix being inserted 
		TrieNode(){
			for(int i=0; i<26; i++)
				children[i]=nullptr;
		}
		
		void insert(TrieNode &root, string str, int suff_ind){
			TrieNode* node = &root;
			for(int i=0; i<str.size(); i++){
				int index = str[i]-'a';
				if(node->children[index]==nullptr)
					node->children[index] = new TrieNode;
				node = node->children[index];
				node->suff_index.push_back(suff_ind);
			}
			return;
		}
		
		void insert_suffix(TrieNode &root, string str){					// insert all suffixes of str
			for(int i=0; i<str.size(); i++)
				insert(root, str.substr(i), i);
			return;
		}
		
		int cnt_pattern(TrieNode* root, string &p){							// number of times p comes in s
			for(int i=0; i<p.size(); i++){
				int index = p[i]-'a';
				if(root->children[index]==nullptr)
					return 0;
				root = root->children[index];
			}
			// Means p is present in s
			return root->suff_index.size();									// different suffixes which had p in them
		}
};

int main(){
	int f;
	TrieNode root;
	string s, p;
	cin>>s>>p;
	root.insert_suffix(root,s);
	f = root.cnt_pattern(&root,p);
	cout<<"Frequence "<<f<<endl;
	return 0;
}
