#include<bits/stdc++.h>
using namespace std;

int main(){
	string c, s;
	int l, a[26], ch;
	for(int i=0; i<26; i++)		a[i]=0;
	getline(cin, c);
	l = c.length();
	for(int i=0; i<l; i++)
		if(c[i]!='{' && c[i]!='}' && c[i]!=',' && c[i]!=' ')	s.push_back(c[i]);
	
	l = s.length();
	for(int i=0; i<l; i++){
		ch = s[i]-97;
		a[ch]+=1;
	}
	ch =0;
	for(int i=0; i<26; i++)
		if(a[i]!=0)	ch++;
	cout<<ch<<endl;
	return 0;
}
