// Given a string s and pattern p, check whether p exists in s or not  (Basically KMP Algorithm)

#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

vector<int> cnt_table;
string s, p;

void create_table(){
	int i=1, j=0;
	while(i<p.size()){
		if(p[i]==p[j]){						// characters match, increase the count
			cnt_table[i]=j+1;
			i++;
			j++;
		}
		else{
			if(j==0)						// character doesn't match even with the first character of pattern
				i++;
			else							// j-1 characters matched, hence j = cnt where prefix=suffix for j-1
				j=cnt_table[j-1];
		}
	}
	return;
}

int find_pattern(){
	int i=0, j=0;
	while(i<s.size()){
		if(s[i]==p[j]){
			i++;
			j++;
		}
		else{
			if(j==0)
				i++;
			else
				j=cnt_table[j-1];
		}
		if(j==p.size())
			return i-j;
	}
	return -1;
}

int main(){
	int index;
	cin>>s>>p;
	cnt_table = vector<int>(p.size(),0);
	create_table();
	index = find_pattern();
	if(index>=0)
		cout<<"Pattern found at index "<<index<<endl;
	else
		cout<<"Pattern not found\n";
	return 0;
}

/* 
	Basic idea is not going back again when we find that s[i]!=p[j] while doing brute force
	
	We store the length for each index j in p[j] such that prefix = suffix in the substring p.substr(0,j+1);

	cnt_table[i] = length with suffix = prefix till i'th index

	NOTE: This can be used to find number of times pattern comes in the string, Time_Complexity O(m+n)
*/
