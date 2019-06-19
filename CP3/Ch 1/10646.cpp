#include<iostream>
#include<vector>
#include<iterator>
using namespace std;

int value(char c){
	if(c=='A' || c=='T' || c=='K' || c=='Q' || c=='J')	return 10;
	else return c-'0';
}

int main(){
	vector<pair<char,char>> vec;	// value,suit
	vector<pair<char,char>>::iterator it;
	char str[3];
	int tc,y,x,topindex;
	scanf("%d\n",&tc);
	for(int w=1; w<=tc; w++){
		y=0;
		for(int i=0; i<52; i++){
			scanf("%s",str);
			vec.push_back(make_pair(str[0],str[1]));
		}
		topindex=26;
		for(int j=0; j<3; j++){
			x = value(vec[topindex].first);
			y+=x;
			topindex -=(11-x);
		}
		if(y-1<=topindex)	topindex=y-1;
		else	topindex = 25+y-topindex;
		printf("Case %d: %c%c\n",w,vec[topindex].first,vec[topindex].second);
		vec.clear();
	}
	return 0;
}
