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


int main() {
	
	//MyStruct g;for (size_t i = 0; i < _Size; i++) v.push_back(_Size);
	//cout << q(g);

	vector<vector<int>> v = Input();
	Print(v);

	return 0;
}