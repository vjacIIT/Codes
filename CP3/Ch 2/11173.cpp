#include<cstdio>
#include<iostream>
#include<bitset>
using namespace std;

int cint(char a){
	return a=='0' ? 0:1;
}

char cchar(int a){
	return a==0 ? '0':'1';
}

char myXor(char a, char b){
	int a1=cint(a);	int b1=cint(b);
	return cchar(a1^b1);
}	

int grey(int k){
	int l, ans=0, no=1;
	string s1="", s2="";
	if(k==0 || k==1)	return k;
	while(k!=0){
		s1+=cchar(k%2);
		s2+=cchar(k%2);
		k/=2;
	}
	l = s1.length();
	for(int i=l-2; i>=0; i--)	s2[i]=myXor(s1[i],s1[i+1]);
	for(int i=0; i<l; i++){
		ans+=no*cint(s2[i]);
		no*=2;
	}
	s1.clear();	s2.clear();
	return ans;
}

int main(){
	int tc, n, k;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d%d",&n,&k);
		n=grey(k);
		printf("%d\n",n);
	}
	return 0;
}

// Use formula directly ->  g = b^(b>>1)	, b is the binary and g is the gray scale
