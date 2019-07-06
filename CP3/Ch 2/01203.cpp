#include<cstdio>
#include<cstring>
#include<set>
using namespace std;

int main(){
	int pd[5000];
	set<pair<int,int>> st;
	char str[60], s[10];
	int id, period, k, q;
	while(fgets(str,50,stdin)){
		if(str[0]=='#'){
			scanf("%d",&q);
			auto it = st.begin();
			while(q--){
				auto it = st.begin();
				period = it->first;		id = it->second;
				printf("%d\n",id);	st.insert(make_pair(period+pd[id],id));
				st.erase(it);
			}
			st.clear();
			return 0;
		}
		sscanf(str,"%s %d %d",s,&id,&period);
		st.insert(make_pair(period,id));			
		pd[id]=period;
	}
	return 0;
}
