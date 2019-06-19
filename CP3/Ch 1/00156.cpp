#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<iterator>
#include<iostream>
using namespace std;

int main(){
	map<string,string> dictionary;		// sorted to actual
	map<string,bool> take;
	set<string>::iterator it;
	set<string>	sstring;
	set<string> astring;
	string s1,s2;
	char str[20],c;
	while(scanf("%s",str)!=EOF){
		c=str[0];
		if(c=='#')	break;
		s1=str;
		s2=str;
		transform(s1.begin(),s1.end(),s1.begin(),::tolower);
		sort(s1.begin(),s1.end());
		it=sstring.find(s1);
		if(it==sstring.end()){
			take[s1]=true;
			sstring.insert(s1);
			dictionary[s1]=s2;
		}
		else	take[s1]=false;
		s1.clear();
		s2.clear();		
	}
	while(!sstring.empty()){
		it = sstring.begin();
		s1=*it;
		if(take[s1]){
			s2=dictionary[s1];
			astring.insert(s2);
		}
		sstring.erase(it);
	}
	while(!astring.empty()){
		it=astring.begin();		s1=*it;
		for(int i=0; i<s1.length(); i++)	printf("%c",s1[i]);
		printf("\n");
		astring.erase(it);
	}
	return 0;
}
