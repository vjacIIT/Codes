#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
	vector<int> v;
	int ch, sp, sv;
	pair<int,int> w_i;
	while(scanf("%d%d",&ch,&sp)!=EOF){
		priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> myq;
		for(int i=0; i<ch; i++)
			myq.push(make_pair(0,i));
		v = vector<int>(sp);
		for(int i=0; i<sp; i++)
			scanf("%d",&v[i]);
		sort(v.begin(),v.end(),greater<int>());

		for(int i=0; i<sp; i++){
			w_i = myq.top();
			myq.pop();
			myq.push(make_pair(w_i.first+v[i],w_i.second));
		}
		while(!myq.empty()){
			w_i = myq.top();
			printf("%d %d\n",w_i.first,w_i.second);
			myq.pop();
		}
	}
	return 0;
}

// Wrong approach, didn't think that each chamber can have at most 2 specimen
