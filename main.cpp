#include "CPython.h"


using namespace std;

struct MyStruct {
	int n;
	string s;
};

template<typename T>
bool q(T t) {
	return is_arithmetic<T>::value;
}

//__declspec(deprecated("** this is a deprecated function **")) void func2(int) {}


int main() {
	
	int a = 1, b = 3;
	
	a in b;

	return 0;
}