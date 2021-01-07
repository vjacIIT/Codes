/*
	Find the longest common substring
*/

#include<cstdio>
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int main(){
	int ans=INT_MIN;
	string s1, s2;
	cin>>s1>>s2;
	vector<vector<int>> LCSuffix = vector<vector<int>>(s1.size()+1,vector<int>(s2.size()+1));
	for(int i=0; i<=s1.size(); i++){
		for(int j=0; j<=s2.size(); j++){
			if(i==0 || j==0)
				LCSuffix[i][j] = 0;
			else if(s1[i-1]==s2[j-1])
				LCSuffix[i][j] = 1+LCSuffix[i-1][j-1];
			else
				LCSuffix[i][j] = 0;
			ans = max(ans,LCSuffix[i][j]);
		}
	}
	cout<<"Longest common substring "<<ans<<endl;
	return 0;
}

/*
	LCSuffix(i,j) = Longest common suffix with string s1 is s1.substr(0,i) and s2 is s2.substr(0,j)
	LCSuffix(i,j) = if(s1[i-1]==s2[j-1])
						LCSuffix[i][j] = 1+LCSuffix[i-1][j-1]
					else
						LCSuffix[i][j] = 1
	Longest common substring = max(LCSuffix[i][j])	for all i, j
*/
