#include "CPython.h"


using namespace std;

struct MyStruct {
	int n;
	string s;
};

template<typename T>
bool q(T t) {
	return 0;
}

template<typename T>
bool q2(T const& t) {
	return sizeof(T) == sizeof(char[]);
}


//__declspec(deprecated("** this is a deprecated function **")) void func2(int) {}


int main() {
	
	std::unordered_map<std::string, std::string> some_map =
	{
		{ "black", "white" },
		{ "cat", "dog" },
		{ "day", "night" }
	};

	vector<char> p = { 'a', 'b', 'd', 'e', 'f'};
	Print('c' in p);

	
	Print(some_map);

	return 0;
}