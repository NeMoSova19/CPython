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
bool q2(T &t) {
	return is_array(T);
}



//__declspec(deprecated("** this is a deprecated function **")) void func2(int) {}


int main() {
	
	std::unordered_map<std::string, std::string> some_map =
	{
		{ "black", "white" },
		{ "cat", "dog" },
		{ "day", "night" }
	};
	//vector<char> p = { 'a', 'b', 'd', 'e', 'f'};
	//Print('c' in p);
	pair<int, string> p = { 6, "sddj" }, pnew = { 6, "sddj" };
	pair<int, char> p1 = { -56, '0'};
	pair<pair<int, char>, pair<int, char>> pp = { { 6, 'c'} , { 90, '3'} };
	array<int, 5> as = { 5, -4, 2, 4, 3 };
	array<array<int, 3>, 3> aa;
	aa[0] = { 4, 5, 10 };
	aa[1] = { 90, -34, 7 };
	aa[2] = { -56, -45, 4 };
	array<int, 3> a1 = { 4, 5, 1 };	
	vector<string> sss = { "str", "gg", "string" };
	
	vector<int> a;
	a = Input();
	

	Print(a);

	return 0;
}