#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

bool comparator(char a, char b){
	if(tolower(a)==tolower(b))	return a<b;
	return tolower(a)<tolower(b);
}

int main(){
	int tc,l;
	char c;
	string s="";
	scanf("%d\n",&tc);
	while(tc--){
		while(scanf("%c",&c)!=EOF){
			if(c=='\n'){
				sort(s.begin(),s.end(),comparator);
				l=s.length();
				do{
					for(int i=0; i<l; i++)	printf("%c",s[i]);
					printf("\n");
				}while(next_permutation(s.begin(),s.end(),comparator));
				s.clear();		
				break;
			}
			else	s+=c;
		}
	}
	return 0;
}

// See how the comparator is used for sorting as well as next_permutation
