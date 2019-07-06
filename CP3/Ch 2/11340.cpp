#include<cstdio>
#include<iostream>
#include<map>
using namespace std;

string two(int n){
	string s="";
	if(n<10)	s+='0';
	s+=to_string(n);
	return s;
}

int main(){
	char c;
	map<char,int> m;
	int tc, k, nl, value;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d\n",&k);
		while(k--){	scanf("%c%d\n",&c,&value);	m[c]=value;	}
		value=0;
		scanf("%d\n",&nl);
		while(nl>0){
			while(scanf("%c",&c)){
				if(c=='\n'){	nl--;	break;	}
				else if(m.find(c)!=m.end())	value+=m[c];
			}
		}
		printf("%d.%s$\n",value/100,two(value%100).c_str());
		m.clear();
	}
	return 0;
}
