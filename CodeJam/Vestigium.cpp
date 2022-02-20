#include<cstdio>
#include<set>
#include<vector>
using namespace std;

int main(){
	int tc, n, cr, cc, tr;
	set<int> s;
	vector<vector<int>> v;
	scanf("%d",&tc);
	for(int t=1; t<=tc; t++){
		cr = 0;
		cc = 0;
		tr = 0;
		scanf("%d",&n);
		v = vector<vector<int>> (n,vector<int>(n));
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				scanf("%d",&v[i][j]);
				if(i==j)
					tr+=v[i][j];
			}
		}
		
		for(int r=0; r<n; r++){
			for(int c=0; c<n; c++){
				s.insert(v[r][c]);
			}
			if(s.size()!=n)
				cr++;
			s.clear();
		}
		
		for(int c=0; c<n; c++){
			for(int r=0; r<n; r++){
				s.insert(v[r][c]);
			}
			if(s.size()!=n)
				cc++;
			s.clear();
		}
		printf("Case #%d: %d %d %d\n",t,tr,cr,cc);
		v.clear();
	}
	return 0;
}
