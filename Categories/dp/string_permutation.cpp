//Logic is choose any one letter and permute rest of the string
// This program considers all the letters to be different
// Set is used to check for repetitions
// Even if All the characters are same it will take O(n*n!) time

#include<bits/stdc++.h>
using namespace std;

set<string> st;

void permute(string s, string chosen){
	if(s.empty()){			// reached end
		if(st.find(chosen)==st.end()){	// string is new, else it found earlier
			cout<<chosen<<endl;
			st.insert(chosen);
		}
		return;
	}
	for(int i=0; i<s.size(); i++){		// choose any of the letter of string and permute
		char c = s[i];
		s.erase(i,1);		// index i remove 1 element
		chosen+=c;
		permute(s,chosen);
		s.insert(i,1,c);		// after permuting for c, put it back
		chosen.erase(chosen.end()-1); 	// erase last element
	}
	return;
}

int main(){
	string s;
	cin>>s;
	permute(s,"");
	return 0;
}
