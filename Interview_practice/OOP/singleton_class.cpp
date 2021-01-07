#include<cstdio>
using namespace std;

class A{
	static A *p;						// static pointer to class
	static int v;
	A(){};								// private constructor
	public:
		static A *getInstance(){
			v++;
			if(!p)
				p = new A;
			return p;
		}
		static int getData(){
			return v;
		}
};
A* A::p = 0;
int A::v = 0;

int main(){
	A *a = a->getInstance();
	printf("%d\n",a->getData());
	return 0;
}
