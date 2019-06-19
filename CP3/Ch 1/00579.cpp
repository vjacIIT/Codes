#include<cstdio>
#include<cstring>
using namespace std;

float positive(float degree){
	float ans;
	ans = degree>0 ? degree:-degree;
	return ans;
}

int main(){
	float hourdegree, minutedegree, degree;
	int l,hour,minute;
	char str[6];
	while(scanf("%s",str)!=EOF){
		if(!strcmp(str,"0:00"))	break;
		l = strlen(str);
		if(l==4){
			hour = str[0]-'0';
			minute = 10*(str[2]-'0')+str[3]-'0';
		}
		else{
			hour = 10*(str[0]-'0')+str[1]-'0';
			minute = 10*(str[3]-'0')+str[4]-'0';
		}
		hourdegree = 1.0*hour*30;			// degree of hours
		minutedegree = 5.5*minute;
		degree = positive(hourdegree-minutedegree);
		if(degree>180.000)	printf("%0.3f\n",360-degree);
		else	printf("%0.3f\n",degree);
	}
	return 0;
}

// Degree for one minute is 5.5 here not 6.
// Dgree for hour is normal 30.
