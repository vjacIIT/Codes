// A dictionary of strings is given, also a string s is given
// We need to add spaces in s to construct a sentence such that each word in sentence is in dictionary
// Print all such sentences

// Example Dictionary = ['cat', 'cats', 'and', 'sand', 'dog']
// s = 'catsanddog'

// Output = ['cats and dog', 'cat sand dog']

#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
using namespace std;

map<string,vector<string>> dp;

class TrieNode{
	public:
		TrieNode* children[26];
		int noChild;
		bool end;
		TrieNode(){
			for(int i=0; i<26; i++)
				children[i]=nullptr;
			end=false;
			noChild=0;
		}
		
		void insert(TrieNode &root, string &str){
			TrieNode* node = &root;
			for(int i=0; i<str.size(); i++){
				int index = str[i]-'a';
				if(node->children[index]==nullptr){
					node->noChild++;
					node->children[index]=new TrieNode;
				}
				node = node->children[index];
			}
			node->end = true;
			return;
		}
		
		bool search(TrieNode &root, string &str){
			TrieNode* node = &root;
			for(int i=0; i<str.size(); i++){
				int index = str[i]-'a';
				if(node->children[index]==nullptr)
					return false;
				node = node->children[index];
			}
			return node->end;
		}
		
		bool delete_node(TrieNode* node, string &str, int index){
			if(index==str.size()){
				if(node->end){
					node->end=false;
					if(node->noChild==0){
						delete node;
						return true;
					}
					return false;
				}
				return false;										// string doesn't exist
			}
			
			int ind = str[index]-'a';
			if(node->children[ind]==nullptr)						// string doesn't exist
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
			return false;
		}
		
		vector<string> wordBreak(TrieNode* root, string str){
			vector<string> results, temp;
			
			if(dp.find(str)!=dp.end())
				return dp[str];
			
			if(str==""){
				results.push_back("");
				return results;
			}
			
			string sentence = "";
			TrieNode* node = root;
			for(int i=0; i<str.size(); i++){
				int ind = str[i]-'a';
				if(node->children[ind]==nullptr)
					return dp[str]=results;
				node = node->children[ind];
				sentence += str[i];
				if(node->end){
					temp = wordBreak(root, str.substr(i+1));
					for(int j=0; j<temp.size(); j++){
						string c = temp[j]=="" ? "":" ";
						results.push_back(sentence+c+temp[j]);
					}
				}
			}
			dp[str]=results;
			return results;
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
	cin>>s;
	dp[s] = root.wordBreak(&root,s);
	for(int i=0; i<dp[s].size(); i++)
		cout<<dp[s][i]<<endl;
	
	return 0;
}

/*
	Idea is to break the string at every possible word in dictionary
	When we reach end we print the sentence

	TLE because we are doing same computation again and again
	How?	Dict=['a', 'aa'], 	s = 'aaaa'
	We do				'a a' + All possible spaces in "aa" (i.e. 'aa' , 'a a')
						'aa' + All possible spaces in "aa"

	Hence we check if dp["aa"] is already filled, if yes return it's value
	Else we find dp["aa"] = All possible sentences (vector of strings) and return it
*/
