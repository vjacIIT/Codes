#include<cstdio>
#include<cstring>
#include<iostream>
#include<map>
#include<algorithm>
#include<iterator>
using namespace std;

int main(){
	map<string,int> mp;
	map<string,int>::iterator it;
	string s;
	char str[50];
	int tc, l, cnt;
	float f;
	scanf("%d\n\n",&tc);
	while(tc--){
		cnt=0;	
		while(fgets(str,40,stdin)){
			if(!strcmp(str,"\n"))	break;
			l = strlen(str);	s.clear();	cnt++;
			for(int i=0; i<l-1; i++)	s+=str[i];
			it = mp.find(s);
			if(it!=mp.end())	mp[s]++;
			else	mp[s]=1;
		}
		for(it=mp.begin(); it!=mp.end(); it++){
			f = (1.0*(it->second))/cnt;		s=it->first;
			printf("%s %0.4f\n",s.c_str(),100*f);
		}
		mp.clear();
		if(tc)	printf("\n");	
	}
	return 0;
}

// First I used vector to sort the strings, but then I came to know that map already sorts like set
// Although time remains same
