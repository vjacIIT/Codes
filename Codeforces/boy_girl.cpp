#include<bits/stdc++.h>
using namespace std;

int main(){
	int a[26], l, ch, cnt=0;
	for(int i=0; i<26; i++)	a[i]=0;
	string c;
	cin>>c;
	l = c.length();
	for(int i=0; i<l; i++){
		ch = c[i]-97;
		a[ch]+=1;
	}
	for(int i=0; i<26; i++)
		if(a[i]!=0)		cnt++;
	if(cnt%2==0)	printf("CHAT WITH HER!\n");
	else 			printf("IGNORE HIM!\n");	
	return 0;
}
