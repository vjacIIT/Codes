// As we go in depth of search we print string (subset)
// As we backtrack we pop out each element
// Works if elements are not unique

#include<bits/stdc++.h>
using namespace std;

vector <pair<char,int>> vec;

void pSubset(string s, int ind){		// starting from index ind to the end
	for(int i=ind; i<vec.size(); i++){	// it starts form index not from 0
		if(vec[i].second!=0){
			vec[i].second--;
			s=s+vec[i].first;	
			cout<<s<<endl;
			pSubset(s,i);
			s.erase(s.end()-1);
			vec[i].second++;
		}
	}
	return;
}

// As the relative order doen't matter in subsets, we started from index ind
// In printing all permutations there was no index term

int main(){
	string s;
	cin>>s;
	int a[26];
	for(int i=0; i<26; i++)	a[i]=0;
	for(int i=0; i<s.length(); i++)	a[s[i]-'a']++;
	for(int i=0; i<s.length(); i++){
		if(a[i]!=0){
			vec.push_back(make_pair(char(i+97),a[i]));
		}
	}
	s.erase();
	pSubset(s,0);	
	return 0;
}
