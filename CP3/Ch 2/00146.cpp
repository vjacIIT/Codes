#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	char c;
	string s, cs;
	while(scanf("%c",&c)!=EOF){
		if(c=='#')	break;
		else if(c=='\n'){
			cs = s;
			sort(cs.begin(),cs.end());
			next_permutation(s.begin(),s.end());
			if(cs==s)	printf("No Successor\n");
			else	printf("%s\n",s.c_str());
			s.clear();	cs.clear();			
		}
		else	s+=c;
	}
	return 0;
}
