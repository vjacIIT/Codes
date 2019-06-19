#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

char p1[5],p2[5],chld[5];
bool ppos,parentfound,fp1;						// if both -ve then +ve is not possible 

void printChild(char s1, char s2, bool fparent){				// helps in finding parent also
	ppos=true;
	int i=0;
	char ap1[4],ap2[4];
	if(s1=='-' && s2=='-')	ppos=false;
	while(p1[i]!=s1){	ap1[i]=p1[i];	i++;	}	ap1[i]='\0';
	i=0;
	while(p2[i]!=s2){	ap2[i]=p2[i];	i++;	}	ap2[i]='\0';
	if( ( !strcmp(ap1,"A") && (!strcmp(ap2,"A") || !strcmp(ap2,"O")) ) || (!strcmp(ap1,"O") && !strcmp(ap2,"A")) ){
		if(fparent){
			if(!ppos){
				if(!strcmp(chld,"A-") || !strcmp(chld,"O-")){
					if(!parentfound)	printf("{");
					else	printf(", ");
					if(fp1)	printf("%s",p1);
					else	printf("%s",p2);
					parentfound=true;
				}
			}
			else if(!strcmp(chld,"A+") || !strcmp(chld,"A-") || !strcmp(chld,"O+") || !strcmp(chld,"O-")){
				if(!parentfound)	printf("{");
				else	printf(", ");
				if(fp1)	printf("%s",p1);
				else	printf("%s",p2);
				parentfound=true;
			}
		}
		else{
			if(!ppos)	printf(" {A-, O-}");
			else	printf(" {A+, A-, O+, O-}");
		}
	}
	else if( (!strcmp(ap1,"A") && !strcmp(ap2,"B")) || (!strcmp(ap1,"B") && !strcmp(ap2,"A")) ){
		if(fparent){
			if(!ppos){
				if(!strcmp(chld,"A-") || !strcmp(chld,"B-") || !strcmp(chld,"AB-") || !strcmp(chld,"O-")){
					if(!parentfound)	printf("{");
					else	printf(", ");
					if(fp1)	printf("%s",p1);
					else	printf("%s",p2);
					parentfound=true;
				}
			}
			else if(!strcmp(chld,"A+") || !strcmp(chld,"A-") || !strcmp(chld,"B+") || !strcmp(chld,"B-") || !strcmp(chld,"AB+") || !strcmp(chld,"AB-") || !strcmp(chld,"O+") || !strcmp(chld,"O-")){
				if(!parentfound)	printf("{");
				else	printf(", ");
				if(fp1)	printf("%s",p1);
				else	printf("%s",p2);
				parentfound=true;
			}
		}
		else{
			if(!ppos)	printf(" {A-, B-, AB-, O-}");
			else	printf(" {A+, A-, B+, B-, AB+, AB-, O+, O-}");
		}
	}
	else if( ( (!strcmp(ap1,"A") || !strcmp(ap1,"B")) && !strcmp(ap2,"AB") ) || ( !strcmp(ap1,"AB") && (!strcmp(ap2,"A") || !strcmp(ap2,"B")) ) ){
		if(fparent){
			if(!ppos){
				if(!strcmp(chld,"A-") || !strcmp(chld,"B-") || !strcmp(chld,"AB-")){
					if(!parentfound)	printf("{");
					else	printf(", ");
					if(fp1)	printf("%s",p1);
					else	printf("%s",p2);
					parentfound=true;
				}
			}
			else if(!strcmp(chld,"A+") || !strcmp(chld,"A-") || !strcmp(chld,"B+") || !strcmp(chld,"B-") || !strcmp(chld,"AB+") || !strcmp(chld,"AB-")){
				if(!parentfound)	printf("{");
				else	printf(", ");
				if(fp1) printf("%s",p1);
				else	printf("%s",p2);
				parentfound=true;
			}
		}
		else{
			if(!ppos)	printf(" {A-, B-, AB-}");
			else	printf(" {A+, A-, B+, B-, AB+, AB-}");
		}
	}
	else if( ( !strcmp(ap1,"B") && (!strcmp(ap2,"B") || !strcmp(ap2,"O")) ) || (!strcmp(ap1,"O") && !strcmp(ap2,"B")) ){
		if(fparent){
			if(!ppos){
				if(!strcmp(chld,"B-") || !strcmp(chld,"O-")){
					if(!parentfound)	printf("{");
					else	printf(", ");
					if(fp1)	printf("%s",p1);
					else	printf("%s",p2);
					parentfound=true;
				}
			}
			else if(!strcmp(chld,"B+") || !strcmp(chld,"B-") || !strcmp(chld,"O+") || !strcmp(chld,"O-")){
				if(!parentfound)	printf("{");
				else	printf(", ");
				if(fp1) printf("%s",p1);
				else	printf("%s",p2);
				parentfound=true;
			}
		}
		else{
			if(!ppos)	printf(" {B-, O-}");
			else	printf(" {B+, B-, O+, O-}");
		}
	}
	else if(!strcmp(ap1,"O") && !strcmp(ap2,"O")){
		if(fparent){
			if(!ppos){
				if(!strcmp(chld,"O-")){
					if(!parentfound)	printf("{");
					else	printf(", ");
					if(fp1)	printf("%s",p1);
					else	printf("%s",p2);
					parentfound=true;
				}
			}
			else if(!strcmp(chld,"O+") || !strcmp(chld,"O-")){
				if(!parentfound)	printf("{");
				else	printf(", ");
				if(fp1) printf("%s",p1);
				else	printf("%s",p2);
				parentfound=true;
			}
		}
		else{
			if(!ppos)	printf(" O- ");					// This is the only case in which no {} is required
			else	printf(" {O+, O-}");
		}
	}
	else if(!strcmp(ap1,"AB") && !strcmp(ap2,"AB")){
		if(fparent){
			if(!ppos){
				if(!strcmp(chld,"A-") || !strcmp(chld,"B-") || !strcmp(chld,"AB-")){
					if(!parentfound)	printf("{");
					else	printf(", ");
					if(fp1)	printf("%s",p1);
					else	printf("%s",p2);
					parentfound=true;
				}
			}
			else if(!strcmp(chld,"A+") || !strcmp(chld,"A-") || !strcmp(chld,"B+") || !strcmp(chld,"B-") || !strcmp(chld,"AB+") || !strcmp(chld,"AB-")){
				if(!parentfound)	printf("{");
				else	printf(", ");
				if(fp1) printf("%s",p1);
				else	printf("%s",p2);
				parentfound=true;
			}
		}
		else{
			if(!ppos)	printf(" {A-, B-, AB-}");
			else	printf(" {A+, A-, B+, B-, AB+, AB-}");
		}
	}
	else{
		if(fparent){
			if(!ppos){
				if(!strcmp(chld,"A-") || !strcmp(chld,"B-")){
					if(!parentfound)	printf("{");
					else	printf(", ");
					if(fp1)	printf("%s",p1);
					else	printf("%s",p2);
					parentfound=true;
				}
			}
			else if(!strcmp(chld,"A+") || !strcmp(chld,"A-") || !strcmp(chld,"B+") || !strcmp(chld,"B-")){
				if(!parentfound)	printf("{");
				else	printf(", ");
				if(fp1) printf("%s",p1);
				else	printf("%s",p2);
				parentfound=true;
			}
		}
		else{
			if(!ppos)	printf(" {A-, B-}");
			else	printf(" {A+, A-, B+, B-}");
		}
	}
	return;
}


void findParent(char s1, char s2){
	if(s1=='?'){
		fp1=true;
		p1[0]='A';	p1[1]='+';	p1[2]='\0';	p1[3]='\0';
		printChild('+',s2,true);
		p1[0]='A';	p1[1]='-';	p1[2]='\0';	p1[3]='\0';
		printChild('-',s2,true);
		
		p1[0]='B';	p1[1]='+';	p1[2]='\0';	p1[3]='\0';
		printChild('+',s2,true);
		p1[0]='B';	p1[1]='-';	p1[2]='\0';	p1[3]='\0';
		printChild('-',s2,true);

		p1[0]='A';	p1[1]='B';	p1[2]='+';	p1[3]='\0';
		printChild('+',s2,true);
		p1[0]='A';	p1[1]='B';	p1[2]='-';	p1[3]='\0';
		printChild('-',s2,true);
		
		p1[0]='O';	p1[1]='+';	p1[2]='\0';	p1[3]='\0';
		printChild('+',s2,true);
		p1[0]='O';	p1[1]='-';	p1[2]='\0';	p1[3]='\0';
		printChild('-',s2,true);

		if(!parentfound)	printf("IMPOSSIBLE %s %s\n",p2,chld);
		else	printf("} %s %s\n",p2,chld);
	}
	else{
		fp1=false;
		printf("%s ",p1);
		p2[0]='A';	p2[1]='+';	p2[2]='\0';	p1[3]='\0';
		printChild(s1,'+',true);
		p2[0]='A';	p2[1]='-';	p2[2]='\0';	p1[3]='\0';
		printChild(s1,'-',true);
		
		p2[0]='B';	p2[1]='+';	p2[2]='\0';	p1[3]='\0';
		printChild(s1,'+',true);
		p2[0]='B';	p2[1]='-';	p2[2]='\0';	p1[3]='\0';
		printChild(s1,'-',true);

		p2[0]='A';	p2[1]='B';	p2[2]='+';	p2[3]='\0';
		printChild(s1,'+',true);
		p2[0]='A';	p2[1]='B';	p2[2]='-';	p2[3]='\0';
		printChild(s1,'-',true);
		
		p2[0]='O';	p2[1]='+';	p2[2]='\0';	p1[3]='\0';
		printChild(s1,'+',true);
		p2[0]='O';	p2[1]='-';	p2[2]='\0';	p1[3]='\0';
		printChild(s1,'-',true);

		if(!parentfound)	printf("IMPOSSIBLE %s\n",chld);
		else	printf("} %s\n",chld);
	}
}

int main(){
	int tc=1;
	char s1,s2;
	while(scanf("%s %s %s",p1,p2,chld)!=EOF){
		if(p1[0]=='E')	break;
		printf("Case %d: ",tc);
		tc++;
		ppos=true;
		s1=p1[strlen(p1)-1];
		s2=p2[strlen(p2)-1];
		if(chld[0]=='?'){
			printf("%s %s",p1,p2);
			printChild(s1,s2,false);
			printf("\n");
		}
		else{
			parentfound=false;
			findParent(s1,s2);
		}
	}
	return 0;
}
