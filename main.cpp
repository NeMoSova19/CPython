#include "CPython.h"


using namespace std;

struct MyStruct {
	int n;
	string s;
};

template<typename T>
bool q(T t) {
	return std::is_class<T>::value;
}


//__declspec(deprecated("** this is a deprecated function **")) void func2(int) {}


int main() {
	
	vector<int> a = Input(4);
	Print(a, 1, 2, 3, "hello world");

	return 0;
}