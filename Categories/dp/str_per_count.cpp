// Choose the character with non-zero count, fill in the result using depth and recurse
// Takes O(n*n!) time, but fast if repetitions are there (handles repetition without set)

#include<bits/stdc++.h>
using namespace std;

vector<pair<int,char>> cnt;	// stores frequency and character
char *result;

void permute(int depth, int length){		// depth of recursion, length of string
	if(depth==length){
		for(int i=0; i<length; i++)	cout<<result[i]<<" ";		//prints in lexicographic order
		cout<<endl;
		return;
	}
	for(int i=0; i<cnt.size(); i++){
		if(cnt[i].first!=0){			// choose the non-zero count character
			cnt[i].first--;			// decrease the count
			result[depth]=cnt[i].second;	// fil in the chosen character
			permute(depth+1,length);	// permute the rest
			cnt[i].first++;			// restoring the count
		}
	}	
	return;
	// depth tells number of character already filled up, and now we are filling the depth character
}

int main(){
	int count[26];
	for(int i=0; i<26; i++)	count[i]=0;
	string s;
	result = new char[s.length()];
	cin>>s;
	for(int i=0; i<s.length(); i++)	count[s[i]-'a']++;
	for(int i=0; i<26; i++){			// stores in lexicographic order
		if(count[i]!=0)	cnt.push_back(make_pair(count[i],i+'a'));
	}
	permute(0,s.length());
	return 0;
}
