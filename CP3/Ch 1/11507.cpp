#include<iostream>
using namespace std;

string opp(string b){
	if(b=="+y")	return "-y";
	else if(b=="-y")	return "+y";
	else if(b=="+z")	return "-z";
	else 	return "+z";
}

string function(string a, string b){
	if(b=="No")	return a;
	else if(a=="+x")	return b;
	else if(a=="-x")	return opp(b);
	else if(a=="+y"){
		if(b=="+y")	return "-x";
		else if(b=="-y")	return "+x";
		else	return "+y";
	}
	else if(a=="-y"){
		if(b=="+y")	return "+x";
		else if(b=="-y")	return "-x";
		else return "-y";
	}
	else if(a=="+z"){
		if(b=="+z")	return "-x";
		else if(b=="-z")	return "+x";
		else 	return "+z";
	}
	else{
		if(b=="+z")	return "+x";
		else if(b=="-z")	return "-x";
		else return "-z";
	}
}

int main(){
	char *str, c;
	string result, helper;
	int l,i;
	while(scanf("%d\n",&l) && l!=0){
		result = "+x";
		helper = "";
		str = new char[3*l-4];
		i=0;
		while(scanf("%c",&c) && c!='\n'){
			str[i]=c;
			i++;
		}
		l=i;
		i=0;
		for(i=0; i<l-1; i++){
			helper +=str[i];
			helper +=str[i+1]; 
			if((i+1)%3!=0){
				i++;
				result=function(result,helper);
			}
			else	helper.clear();
		}
		printf("%c%c\n",result[0],result[1]);
		result.clear();
		delete []str;
	}
	return 0;
}
