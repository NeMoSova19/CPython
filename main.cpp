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
	
	

	vector<vector<vector<int>>> v = Input(2);

	Print(v);

	return 0;
}