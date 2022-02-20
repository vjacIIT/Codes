#include<bits/stdc++.h>
using namespace std;

char counter(char c){
	if(c=='E')	return 'S';
	return 'E';
}

int main(){
	string s;
	int tc,n;
	scanf("%d",&tc);
	for(int i=1; i<=tc; i++){
		scanf("%d\n", &n);
		printf("Case #%d: ",i);
		cin>>s;
		for(int j=0; j<2*n-2; j++)	printf("%c",counter(s[j]));
		printf("\n");
	}
	return 0;
}
