#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cstring>
using namespace std;

vector<vector<string>> vec(128);		// max 100 words
vector<pair<string,int>> helper;
set<string> sorted;
map<string,int>	idx;

bool mycompare(const string s1, const string s2){
	if(lexicographical_compare(s1.begin(),s1.end(),s2.begin(),s2.end()))	return true;
	return false;
}

bool mycompare2(const pair<string,int> a, const pair<string,int> b){
	string s1=a.first, s2=b.first;
	if(lexicographical_compare(s1.begin(),s1.end(),s2.begin(),s2.end()))	return true;
	return false;
}

int main(){
	int tc,no,oldno,l,lineno=1,help;
	string s, s2;
	char c;
	s="";
	scanf("%d\n\n",&tc);
	while(tc--){
		no=0;
		if(lineno!=1)	printf("\n");
		lineno++;
		while(scanf("%c",&c)!=EOF){
			if(c=='\n'){
				sort(s.begin(),s.end());
				auto it = sorted.find(s);
				if(sorted.find(s)==sorted.end()){		// new sorted word
					sorted.insert(s);
					idx[s]=no;
					vec[no].push_back(s2);
					no++;
				}
				else{						// string already present
					oldno = idx[s];
					vec[oldno].push_back(s2); 
				}
				s.clear();
				s2.clear();
				scanf("%c",&c);
				help=0;
				if(c=='\n'){
					for(int i=0; i<100; i++){
						no=vec[i].size();
						if(no>1){
							sort(vec[i].begin(),vec[i].end(),mycompare);
							helper.push_back(make_pair(vec[i][0],i));
							help++;
						}
					}
					sort(helper.begin(),helper.end(),mycompare2);
					for(int z=0; z<help; z++){
						int i=helper[z].second;
						no=vec[i].size();
						if(no>1){
							for(int j=0; j<no; j++){
								for(int k=j+1; k<no; k++)	printf("%s = %s\n",vec[i][j].c_str(),vec[i][k].c_str());		
							}
						}
					}
					
					for(int i=0; i<128; i++)	vec[i].clear();
					sorted.clear();
					idx.clear();
					helper.clear();
					break;
				}
				else{
					s2+=c;
					if(c!=' ')	s+=c;
				}
			}
			else{
				s2+=c;
				if(c!=' ')	s+=c;
			}
		}
	}
	return 0;
}

// Tried my best but wrong answer, correct anwer on udebug
