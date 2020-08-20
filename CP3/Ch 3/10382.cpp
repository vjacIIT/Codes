#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<double,double>> pos;				// stores starting and ending of time intervals

double fmax(double a, double b){
	return a>b ? a : b;
}

int search(double d, int s, int e){					// search in nearest starting time
	int m = (s+e)>>1;
	if(s>e)
		return e;
	if(pos[m].first==d)
		return m;
	else if(pos[m].first>d)
		return search(d,s,m-1);
	else
		return search(d,m+1,e);
}

bool mycompare(pair<double,double> a, pair<double,double> b){
	if(a.first!=b.first)
		return a.first<b.first;
	return a.second>b.second; 
}

int main(){
	vector<double> mmax;							// stores the maximum ending time seen uptil so far
	int n, s, ind, cnt, tc=1;
	double p, r, m, w, l;
	bool poss;
	while(scanf("%d%lf%lf",&n,&l,&w)!=EOF){
		pos.clear();
		mmax.clear();
		cnt=0;
		poss = false;
		for(int i=0; i<n; i++){
			scanf("%lf%lf",&p,&r);
			if(2*r<=w)
				continue;
			r *=r;
			pos.push_back(make_pair(max(0.0,p-sqrt(r-w*w/4)),p+sqrt(r-w*w/4)));
		}
		s = pos.size();
		sort(pos.begin(),pos.end(),mycompare);
		
		m = pos[0].second;
		mmax.push_back(m);
		for(int i=1; i<s; i++){
			m = fmax(m,pos[i].second);
			mmax.push_back(m);
		}
		if(s==0 || pos[0].first>0.0 || mmax[s-1]<l){
			printf("-1\n");
			continue;
		}
		
		m = mmax[0];
		ind = 0;										// index we are at to find the farthest point
		while(true){
			cnt++;
			if(m>=l){
				poss = true;
				break;
			}
			ind = search(mmax[ind],0,s-1);				// search the nearest starting time <= cmax
			if(m==mmax[ind]){							// we did't get new point
				poss = false;
				break;
			}
			m = mmax[ind];
		}
		if(poss)
			printf("%d\n",cnt);
		else
			printf("-1\n");
	}
	return 0;
}


// Idea: 
//		1. First sort based on the starting time (if same then decreasing on ending time)
//		2. Now for current ending point -> 
//				if ending point is greater than the timing required 
//					then return
//				else 
//					find the max outer we can go from all the starting points before the current point
//					and go to that point and repeat the same 
