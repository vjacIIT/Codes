#include<cstdio>
#include<iostream>
using namespace std;

int *tr;
int *lzy;
string s;

int lt(int ti){
	return (ti<<1)+1;
}

int rt(int ti){
	return (ti<<1)+2;
}

int btr(int ti, int l, int r){
	int mid = (l+r)/2;
	if(l==r)	return s[l]-'0';
	tr[lt(ti)]=btr(lt(ti),l,mid);
	tr[rt(ti)]=btr(rt(ti),mid+1,r);
	return tr[lt(ti)]+tr[rt(ti)];
}

int inv(int i){
	return i==0 ? 2:0;
}

void inverse(int ti){
	if(lzy[lt(ti)]==0 || lzy[lt(ti)]==2)	lzy[lt(ti)]=inv(lzy[lt(ti)]);
	else	lzy[lt(ti)]*=-1;	
	if(lzy[rt(ti)]==0 || lzy[rt(ti)]==2)	lzy[rt(ti)]=inv(lzy[rt(ti)]);
	else	lzy[rt(ti)]*=-1;
}

void updatelazy(int ti, int l, int r){
	if(lzy[ti]!=0){
		if(lzy[ti]==-1){								// make all 0
			if(l<r){
				lzy[lt(ti)]=-1;	lzy[rt(ti)]=-1;
			}
			tr[ti]=0;
		}
		else if(lzy[ti]==1){							// make all 1
			if(l<r){
				lzy[lt(ti)]=1;	lzy[rt(ti)]=1;
			}
			tr[ti]=r-l+1;
		}
		else{											// invert all
			tr[ti]=r-l+1-tr[ti];
			if(l<r)	inverse(ti);
		}
		lzy[ti]=0;
	}
	return;
}

int update(char c, int i, int j, int l, int r, int ti){
	updatelazy(ti,l,r);
	int mid=(l+r)/2;
	if(i>r || j<l)	return tr[ti];
	if(i<=l && j>=r){
		if(c=='F'){					// all 1
			tr[ti]=r-l+1;
			if(l<r){	lzy[lt(ti)]=1;	lzy[rt(ti)]=1;	}
		}
		if(c=='E'){					// all 0
			tr[ti]=0;
			if(l<r){	lzy[lt(ti)]=-1;	lzy[rt(ti)]=-1;	}
		}
		if(c=='I'){					// invert all
			tr[ti]=r-l+1-tr[ti];
			if(l<r)	inverse(ti);
		}
		return tr[ti];
	}
	tr[lt(ti)]=update(c,i,j,l,mid,lt(ti));
	tr[rt(ti)]=update(c,i,j,mid+1,r,rt(ti));
	return tr[lt(ti)]+tr[rt(ti)];
}

int query(int i, int j, int l, int r, int ti){
	updatelazy(ti,l,r);
	int mid=(l+r)/2, lsum, rsum;
	if(i>r || j<l)	return 0;
	if(i<=l && j>=r)	return tr[ti];
	lsum = query(i,j,l,mid,lt(ti));
	rsum = query(i,j,mid+1,r,rt(ti));
	return lsum+rsum;
}

int main(){
	char str[100], qt;
	int tc,l,t,q,st,end,ques;
	scanf("%d",&tc);
	for(int cse=1; cse<=tc; cse++){
		s.clear();	printf("Case %d:\n",cse);	ques=1;
		scanf("%d",&l);
		while(l--){
			scanf("%d\n%s\n",&t,str);
			while(t--)	s+=str;
		}
		l = s.length();	
		lzy=new int[4*l];	for(int i=0; i<4*l; i++)	lzy[i]=0;
		tr = new int[4*l];	tr[0]=btr(0,0,l-1);
		scanf("%d\n",&q);
		while(q--){	
			scanf("%c %d %d\n",&qt,&st,&end);
			if(qt!='S')	tr[0]=update(qt,st,end,0,l-1,0);
			else{	printf("Q%d: %d\n",ques,query(st,end,0,l-1,0));	ques++;	}
		}
		delete []tr;	delete []lzy;
	}

	return 0;
}

// This passed in 0.8s, as we have used lazy prop
