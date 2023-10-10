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
	
	//vector<vector<vector<int>>> v = Input(2);
	//STD::Print(v); cout << '\n';

	std::unordered_map<std::string, std::string> some_map =
	{
		{ "black", "white" },
		{ "cat", "dog" },
		{ "day", "night" }
	};

	//pair<int, char> p = { 6, 'c'};
	//cout << 'c' in p << '\n';

	char l[6];
	cout << q(l);

	
	

	return 0;
}