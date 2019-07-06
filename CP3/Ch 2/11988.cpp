#include<cstdio>
#include<list>
#include<iterator>
using namespace std;

int main(){
	char c;
	list<char> lst;
	list<char>::iterator it;
	it = lst.begin();
	while(scanf("%c",&c)!=EOF){
		if(c=='\n'){
			for(it=lst.begin(); it!=lst.end(); it++)	printf("%c",*it);
			printf("\n");	lst.clear();
			it=lst.begin();
		}
		else{
			if(c=='[')	it=lst.begin();
			else if(c==']')	it=lst.end();
			else	lst.insert(it,c);
		}
	}	
	return 0;
}
