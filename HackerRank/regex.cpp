#include<cstdio>
#include<iostream>
#include<regex>								// regular expression
using namespace std;

int main(){
	string str;
	while(true){
		cin>>str;
		if(str.compare("exit")==0)
			break;
		//regex e("abc.");					// any character at the place of .
		//regex e("abc*");					// 0 or more c
		//regex e("abc+");					// 1 or more c
		//regex e("abc?");					// 0 or 1 c
		//regex e("ab[cd]");					// [..] any of the character in the box (only 1)
		//regex e("ab[cd]{3,5}");				// [..] any of the character 3 to 5 times
		//regex e("ab[^cd]");						// [..] any of the character except c or d
		//regex e("abc|de[fg]");						// OR expression
		//regex e("(abc)de\\1");							// \1 First group (abc) repeat
		regex e(".*@gmail\\.com$");							// $ for the ending
		
		bool match = regex_match(str,e);
		//bool match = regex_search(str,e);					// searches in whole string str
		cout<<(match ? "Matched" : "Not Matched")<<"\n\n";
	}
	return 0;
}
