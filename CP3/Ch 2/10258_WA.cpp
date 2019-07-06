#include<cstdio>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

struct node{
	int np, time, index;									// problem solved, penalty time and index
};

int ptime[101][10];											// 100 contestants, penalty time for each problem
bool tried[101];											// teams that have a submission
int psolved[101];											// no of problem solved by team
int totaltime[101];											// total time taken
bool  palsolved[101][10];									// problem already solved

void initialize(){
	for(int i=0; i<101; i++){
		tried[i]=false;		psolved[i]=0;	totaltime[i]=0;
		for(int j=0; j<10; j++){	ptime[i][j]=0;	palsolved[i][j]=false;	}
	}
	return;
}

int compare(const void *i, const void *j){
	node *a, *b;
	a = (node*)i;	b=(node*)j;
	if(a->np!=b->np)	return b->np-a->np;
	if(a->time!=b->time)	return a->time-b->time;
	return a->index-b->index;
}

int main(){
	char str[30], c;
	int tc, cno, pno, time, lineno=1, count;								// contestant no, problem no and time
	scanf("%d\n\n",&tc);
	while(tc--){
		initialize();
		if(lineno!=1)	printf("\n");
		lineno++;
		while(fgets(str,20,stdin)){						// '\n' is also there in str
			node v[101];
			if(!strcmp(str,"\n")){
				count=0;
				for(int i=1; i<101; i++){
					if(tried[i]){
						v[count].np=psolved[i];		v[count].index=i;	v[count].time=totaltime[i];
						count++;
					}
				}
				qsort(v,count,sizeof(node),compare);
				for(int i=0; i<count; i++)	printf("%d %d %d\n",v[i].index,v[i].np,v[i].time);
				break;				// if line is empty str has '\n'
			}
			sscanf(str,"%d %d %d %c",&cno,&pno,&time,&c);
			tried[cno]=true;
			if(palsolved[cno][pno])	continue;
			else if(c=='C' || c=='I'){
				if(c=='C'){
					totaltime[cno]+=ptime[cno][pno]+time;			// penalty time of problem + time	
					psolved[cno]++;
					palsolved[cno][pno]=true;							// solved once	
				}				
				else	ptime[cno][pno]+=20;
			}
			else	continue;
		}
	}
	return 0;
}

// We need to show those teams also which have not solved any problem but has a submission
// Corrct Answe on Udebug but wrong answer on UVA
