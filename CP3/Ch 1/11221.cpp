#include<iostream>
#include<cstdio>
using namespace std;

char **ar;

int square(int n){
	int i=0;
	while(i*i<n)	i++;
	if(i*i==n)	return i;
	return -1;
}

bool symmetric(int l){
	char a[l][l];
	for(int i=0; i<l; i++){
		for(int j=0; j<l; j++){
			a[i][l-j-1]=ar[i][j];
			if(ar[i][j]!=ar[j][i])	return false;
		}
	}
	for(int i=0; i<l; i++){
		for(int j=0; j<l; j++){
			if(a[i][j]!=a[j][i])	return false;
		}
	}
	return true;
}

int main(){
	int tc,l,no;
	char c;
	string s="";
	scanf("%d\n",&tc);
	for(int w=1; w<=tc; w++){
		printf("Case #%d:\n",w);
		no=0;
		while(scanf("%c",&c)){
			if(c=='\n'){
				l = s.length();
				l=square(l);
				if(l==-1)	printf("No magic :(\n");
				else{
					ar = new char*[l];
					for(int i=0; i<l; i++)	ar[i]=new char[l];
					for(int i=0; i<l; i++){
						for(int j=0; j<l; j++){
							ar[i][j]=s[no];
							no++;
						}
					}
					if(symmetric(l))	printf("%d\n",l);
					else	printf("No magic :(\n");
					for(int i=0; i<l; i++)	delete[]ar[i];
					delete []ar;
				}
				s.clear();
				break;
			}
			else if(c==' ' || c==',' || c=='.' || c=='?' || c=='!' || c==')' || c=='(')	continue;
			else	s+=c;
			
		}
	}
}
