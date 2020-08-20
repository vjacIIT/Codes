#include<iostream>
using namespace std;

int n, *ar;
bool pr[11];

bool checkInc(){
	if(ar[0]!=1)	return false;
	for(int i=0; i<(n-1)/2; i++){
		if(ar[i]!=ar[i+1] && ar[i]+1!=ar[i+1])	return false;
	}
	return true;
}

bool present(){
	for(int i=1; i<8; i++)	if(!pr[i])	return false;
	for(int i=8; i<11; i++)	if(pr[i])	return false;
	return true;
}

bool checkPalindrome(){
	for(int i=0; i<=(n-1)/2; i++){
		if(ar[i]!=ar[n-1-i])	return false;
	}
	return true;
}

int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--){
		for(int i=0; i<11; i++)	pr[i]=false;
		scanf("%d",&n);
		ar = new int[n];
		for(int i=0; i<n; i++){
			scanf("%d",ar+i);
			pr[ar[i]]=true;
		}
		if(checkInc() && checkPalindrome() && present())	printf("yes\n");
		else	printf("no\n");
		delete []ar;
	}
	return 0;
}
