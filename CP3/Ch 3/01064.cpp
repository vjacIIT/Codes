#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
#include<climits>
using namespace std;

#define loop(i,n)	for(int i=0; i<n; i++)
#define Loop(i,a,n)	for(int i=a; i<n; i++)
#define pb	push_back
#define mp	make_pair

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vi> vvi;
typedef vector<bool> vb;

struct packet{
	int no, st, end;
} pkt[1000];

struct packet_compare{
	bool operator()(int i, int j){
		return pkt[i].st < pkt[j].st;
	}
};

struct message{
	int end;
	set<int,packet_compare> pack;
} msg[5];

int remove(message& m, int& end){
	int nr_data=0;
	set<int,packet_compare>::iterator p1=m.pack.begin(), p2=m.pack.end();
	for(; p1!=p2; ++p1){
		if(end<pkt[*p1].st)	break;
		nr_data+=pkt[*p1].end-pkt[*p1].st+1;
		end=pkt[*p1].end+1;
	}
	if(nr_data)	m.pack.erase(m.pack.begin(),p1);
	return nr_data;
}

int main(){
	vi order, msglen;
	int n, m, mno, st, end, msize, cse=0, b, buff_max, nr_out, nr_data;
	while(scanf("%d%d",&n,&m)!=EOF){
		if(n==0 && m==0) break;
		buff_max=INT_MAX;
		msglen=vi(n);	order=vi(n);
		loop(i,n){	scanf("%d",&msglen[i]);	order[i]=i;	}
		loop(i,m){
			scanf("%d%d%d",&pkt[i].no,&pkt[i].st,&pkt[i].end);
			pkt[i].no--;
		}
		do{
			b=0;	msize=0;	nr_out=0;
			loop(i,n){			// starting header for each message
				msg[i].end=1;
				msg[i].pack.clear();			
			}
			loop(i,m){
				mno=pkt[i].no;	st=pkt[i].st;	end=pkt[i].end;
				message& m = msg[mno];
				if(m.end==st && mno==order[nr_out]){			// we can transport this directly
					m.end=end+1;
					nr_data=remove(m, m.end);
					if(nr_data)	b-=nr_data;
					if(m.end==msglen[mno]+1){			//<----------------------------------------------------------------------------------
						for(nr_out++; nr_out<n; nr_out++){								//													|
							message& mm = msg[order[nr_out]];							//	I don't know use of this loop					|
							if(nr_data=remove(mm,mm.end))								//													|
								b-=nr_data;												//													|
							if(mm.end<msglen[mno]+1)	break;							//													|
						}																//													|
					}																	//													|
				}																		//													|
				else{																	//													|
					m.pack.insert(i);													//													|
					b+=end-st+1;														//													|
				}																		//													|
				msize=max(msize,b);														//													|
			}																			//													|
			buff_max=min(msize,buff_max);												//													|
		}while(next_permutation(order.begin(),order.end()));	// message may pass in any order											|
		printf("Case %d: %d\n\n",++cse,buff_max);													//										|
		order.clear();	msglen.clear();																//										|
	}																								//										|
	return 0;																						//										|
}																									//										|
																									//										|
// This whole solution is copied by me from: http://sound-system-79.blogspot.com/2015/05/uva-1064-network.html								|
// This problem although seemed simple, was very hard. I was not able to understand what is the logic when one message is fully transferred -
