#include<iostream>
#include<vector>
using namespace std;

vector<pair<int,char>> s;

void permute(int l, int cnt, string str){
	if(cnt==0){
		for(int i=0; i<str.length(); i++)	printf("%c",str[i]);
		printf("\n");
		return;
	}
	for(int i=0; i<l; i++){
		if(s[i].first!=0){
			s[i].first--;
			permute(l,cnt-1,str+s[i].second);
			s[i].first++;
		}
	}
}

int main(){
	int l,tc,small[26],capital[26],cnt;
	char c;
	for(int i=0; i<26; i++){
		small[i]=0;
		capital[i]=0;
	}
	scanf("%d\n",&tc);
	while(tc--){
		while(scanf("%c",&c)!=EOF){
			if(c=='\n'){
				l=0;	cnt=0;
				for(int i=0; i<26; i++){	
					if(capital[i]!=0){
						cnt+=capital[i];
						s.push_back(make_pair(capital[i],char(i+65)));
						l++;
					}
					if(small[i]!=0){
						cnt+=small[i];	
						s.push_back(make_pair(small[i],char(i+97)));
						l++;
					}
				}
				permute(l,cnt,"");			// different characters,total characters
				s.clear();
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

// This program worked, although it's worst complexity is still O(n!), but it takes care of repetitions
