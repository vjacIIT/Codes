/*
	Given 2 arrays a,b of n elements each
	Find max possible value of xor of a[i] with each element of b

	NOTE: Brute force solution is O(n^2)
*/

#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

vector<int> a;

class TrieNode{
	public:
		TrieNode* children[2];							// 2 children are required only
		bool end;
		TrieNode(){
			for(int i=0; i<2; i++)
				children[i]=nullptr;
			end=false;
		}
		
		// v[32] is the most significant bit
		void insert(TrieNode &root, vector<int> v){					// binary vector of length 32 bits
			TrieNode* temp = &root;
			for(int i=0; i<v.size(); i++){
				if(temp->children[v[i]]==nullptr)
					temp->children[v[i]] = new TrieNode;
				temp = temp->children[v[i]];
			}
			temp->end = true;
			return;
		}
		
		int maxXor(TrieNode &root, vector<int> v){
			TrieNode* node = &root;
			int ans=0;
			for(int i=v.size()-1; i>=0; i--){
				if(v[i]==0){									// MSB of a[i] is 0
					if(node->children[1]==nullptr)				// 1 not found
						node = node->children[0];
					else{
						ans+=(1<<i);
						node = node->children[1];
					}
				}
				else{											// MSB of a[i] is 1
					if(node->children[0]==nullptr)
						node = node->children[1];
					else{
						ans+=(1<<i);
						node = node->children[0];
					}
				}
			}
			return ans;
		}
};

int main(){
	TrieNode root;
	vector<int> v;
	int n, b, cnt;
	cin>>n;
	a = vector<int>(n);
	v = vector<int>(32);
	for(int i=0; i<n; i++)
		scanf("%d",&a[i]);
	for(int i=0; i<n; i++){
		scanf("%d",&b);
		cnt=0;
		while(cnt<32){
			v[cnt]=b%2;
			b/=2;
			cnt++;
		}
		root.insert(root,v);					// b[i] is inserted in the trie
	}
	
	for(int i=0; i<n; i++){
		b = a[i];
		cnt=0;
		while(cnt<32){
			v[cnt]=b%2;
			b/=2;
			cnt++;
		}
		printf("%d\n",root.maxXor(root,v));
	}
	return 0;
}

/*
	Insert all elements of b in a trie
	For each a[i], go in the trie and try to maximize the xor value
*/
