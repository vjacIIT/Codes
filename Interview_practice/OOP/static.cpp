#include<cstdio>
using namespace std;

class A{
	public:
		static int v;
		A(){
			v++;
		}
		static int getV(){				// static member function
			return v;
		}
};
int A::v = 0;

int main(){
	A a, b, c;
	printf("%d\n",A::v);
	printf("%d\n",A::getV());
	return 0;
}
