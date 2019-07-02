#include<bits/stdc++.h>
using namespace std;

struct arry{
	int v, px, py;		// helps in storing the parents 
};

int mx(int a, int b){
	if(a>b)	return a;
	return b;
}

int main(){
	int l1, l2;
	string::reverse_iterator it;
	arry **ar;
	string s1, s2, sb;
	cin>>s1>>s2;
	l1 = s1.size();
	l2 = s2.size();
	ar = new arry*[l1+1];
	for(int i=0; i<l1+1; i++)	ar[i]=new arry[l2+1];
	for(int i=0; i<=l1; i++)
		for(int j=0; j<=l2; j++){
			ar[i][j].v=0;
			ar[i][j].px=0;
			ar[i][j].py=0;
		}
	
	for(int i=0; i<l1; i++){		// for array s1
		for(int j=0; j<l2; j++){	// for array s2
			if(s2[j]==s1[i]){			// elements are same, then add 1 to diagonal and store
				ar[i+1][j+1].v=ar[i][j].v+1;
				ar[i+1][j+1].px = i;		// parent storing
				ar[i+1][j+1].py = j; 
			}
			else{
				ar[i+1][j+1].v=mx(ar[i][j+1].v, ar[i+1][j].v);
				if(ar[i+1][j+1].v==ar[i][j+1].v){
					ar[i+1][j+1].px=i;
					ar[i+1][j+1].py=j+1;
				}
				else{
					ar[i+1][j+1].px = i+1;
					ar[i+1][j+1].py = j;
				}
			}
		}		
	}
	// Last element (ar[l1][l2]) stores the length of maximum common subsequence
	cout<<ar[l1][l2].v<<endl;
	while(l1>0 && l2>0){	
		if(ar[l1][l2].px==l1-1 && ar[l1][l2].py==l2-1){
			sb.push_back(s1[l1-1]);
			l1-=1;
			l2-=1;
		}
		else{
			if(ar[l1][l2].px==l1-1)	l1--;
			else	l2--;
		};
		
	}
	for(it=sb.rbegin(); it!=sb.rend(); it++)	cout<<*it;
	cout<<endl;
	return 0;
}
