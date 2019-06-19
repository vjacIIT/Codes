#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<iterator>
using namespace std;

set<int> pal;
int p[655];

bool isPalindrome(string n){
	int l = n.length()-1;
	for(int i=0; i<=l/2; i++){
		if(n[i]!=n[l-i])	return false;
	}
	return true;
}


int bsearch(int n, int st, int end){
	int mid = (st+end)/2;
	if(st>end)	return p[end];
	else if(p[mid]==n)	return p[mid-1];
	else if(p[mid]>n)	return bsearch(n,st,mid-1);
	else	return bsearch(n,mid+1,end);
}

int main(){
	int tc=0, n;
	for(int i=100; i<=1000; i++){
		for(int j=100; j<=1000; j++){
			if(isPalindrome(to_string(i*j)))	pal.insert(i*j);
		}
	}
	for(auto it=pal.begin(); it!=pal.end(); it++){
		p[tc]=*it;
		tc++;
	}
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		printf("%d\n",bsearch(n,0,654));
	}
	return 0;
}
