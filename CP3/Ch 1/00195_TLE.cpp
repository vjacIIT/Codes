
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<iterator>
#include<set>
using namespace std;

set<string>	permutation;

void permute(string s, string n, int l){
	int idx=0;
	if(l==0){
		if(permutation.find(n)==permutation.end()){
			permutation.insert(n);
			for(int i=0; i<n.length(); i++)	printf("%c",n[i]);
			printf("\n");
		}
		return;
	}
	string::iterator it2;
	char c;
	for(auto it=s.begin(); it!=s.end(); it++){
		c=*it;
		it2=it;
		s.erase(it);
		permute(s,n+c,l-1); 
		s.insert(s.begin()+idx,c);
		idx++;
	}
	return;
}

int main(){
	int l,tc,small[26],capital[26];
	char c;
	string s;
	for(int i=0; i<26; i++){
		small[i]=0;
		capital[i]=0;
	}
	scanf("%d\n",&tc);
	while(tc--){
		while(scanf("%c",&c)!=EOF){
			if(c=='\n'){
				for(int i=0; i<26; i++){
					for(int j=0; j<capital[i]; j++)	s+=char(i+65);
					for(int j=0; j<small[i]; j++)	s+=char(i+97);
				}
				permute(s,"",s.length());
				s.clear();
				permutation.clear();
				for(int i=0; i<26; i++){
					small[i]=0;
					capital[i]=0;	
				}
				break;
			}
			else{
				l=int(c);
				if(l>=97)	small[c-'a']++;
				else	capital[c-'A']++;
			}
		}
	}
	return 0;
}

// This program is correct but form time limit exeeded, because it takes O(n!) time, even if all characters are sames
