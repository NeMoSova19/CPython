#include "CPython.h"
using namespace std;

struct MyStruct {
	int n;
	//string s;
	friend istream& operator >>(istream& I, MyStruct& t) {
		I >> t.n;
		return I;
	}
	friend ostream& operator <<(ostream& I, MyStruct& t) {
		I << t.n;
		return I;
	}
	auto operator =(int t) {
		n = t;
	}
	auto operator =(Input i) {
		n = i;
	}
};

template<typename T>
bool q(T t) {
	return 0;
}

template<typename T>
bool q2(T &t) {
	return is_array(T);
}

template<typename T>
int _typeindefication(T t) {
	type_info a = typeid(T);
	if (a == typeid(std::string)) return 1;
	if (a == typeid(std::pair)) return 2;
	if (a == typeid(std::map)) return 3;
	if (a == typeid(std::unordered_map)) return 4;
	if (a == typeid(std::array)) return 5;
	if (a == typeid(std::vector)) return 6;
	if (a == typeid(std::list)) return 7;
	if (a == typeid(std::forward_list)) return 8;
	if (a == typeid(std::set)) return 9;
	if (a == typeid(std::unordered_set)) return 10;
	if (a == typeid(std::multiset)) return 11;
	if (a == typeid(std::unordered_multiset)) return 12;
	if (a == typeid(std::queue)) return 13;
	if (a == typeid(std::deque)) return 14;
	if (a == typeid(std::stack)) return 15;
	if (!std::is_class<T>::value) return 0;
	return -1;
}






int main() {
	
	//vector<int> v = Input();
	
	char t = Input();
	
	

	Print(Input() + 1);


	return 0;
}







//std::unordered_map<std::string, std::string> some_map =
//{
//	{ "black", "white" },
//	{ "cat", "dog" },
//	{ "day", "night" }
//};
////vector<char> p = { 'a', 'b', 'd', 'e', 'f'};
////Print('c' in p);
//pair<int, string> p = { 6, "sddj" }, pnew = { 6, "sddj" };
//pair<int, char> p1 = { -56, '0'};
//pair<pair<int, char>, pair<int, char>> pp = { { 6, 'c'} , { 90, '3'} };
//array<int, 5> as = { 5, -4, 2, 4, 3 };
//array<array<int, 3>, 3> aa;
//aa[0] = { 4, 5, 10 };
//aa[1] = { 90, -34, 7 };
//aa[2] = { -56, -45, 4 };
//array<int, 3> a1 = { 4, 5, 1 };	
//vector<string> sss = { "str", "gg", "string" };



/*

<string>
<pair>
<map>
<unordered_map>
<array>
<vector>
<list>
<forward_list>
<set>
<unordered_set>
<multiset>
<unordered_multiset>
<queue>
<deque>
<stack>

*/
