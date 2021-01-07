#include<cstdio>
using namespace std;

class A{
	public:
		int a=10;
		void f1() const{
			printf("Constant member function\n");
			//a = 100;					-> cannot change value of a inside a const member function
			printf("%d\n",a);			// this is fine, it can be done
		}
		void f2(){
			printf("Not a constant member function\n");
		}
};

int main(){
	const A a;
	a.f1();
	//a.f2();				// Compilation error
	return 0;
}

// const object can access only const member functions
