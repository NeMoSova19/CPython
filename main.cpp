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
	
	queue<queue<int>> v = Input(3);

	//for (size_t i = 0; i < 3; i++)
	//{
	//	set<int> s;
	//	for(size_t j = 0; j < 4; j++){
	//		s.insert((int)Input());
	//	}
	//	v.insert(s);
	//}

	//Print(v);

	return 0;
}