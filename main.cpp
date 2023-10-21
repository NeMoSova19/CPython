#include "CPython.h"
using namespace std;

template<typename T>
constexpr int _typeindefication(T t) {
	constexpr type_info a = typeid(T);
	if constexpr (a == typeid(std::string)) return 1;
	if constexpr (a == typeid(std::pair)) return 2;
	if constexpr (a == typeid(std::map)) return 3;
	if constexpr (a == typeid(std::unordered_map)) return 4;
	if constexpr (a == typeid(std::array)) return 5;
	if constexpr (a == typeid(std::vector)) return 6;
	if constexpr (a == typeid(std::list)) return 7;
	if constexpr (a == typeid(std::forward_list)) return 8;
	if constexpr (a == typeid(std::set)) return 9;
	if constexpr (a == typeid(std::unordered_set)) return 10;
	if constexpr (a == typeid(std::multiset)) return 11;
	if constexpr (a == typeid(std::unordered_multiset)) return 12;
	if constexpr (a == typeid(std::queue)) return 13;
	if constexpr (a == typeid(std::deque)) return 14;
	if constexpr (a == typeid(std::stack)) return 15;
	if constexpr (!std::is_class<T>::value) return 0;
	return -1;
}
struct A {
	string ToString() { return "this is struct A"; }
};
struct B{
	B() = default;

	static B InputToThis() {
		B b;
		cin >> b.a >> b.b;
		return b;
	}

	int a{ 0};
	string b{};
};


int main() {
	
	srand((unsigned int)time(0));

	std::unordered_map<std::string, std::string> some_map =
	{
		{ "black", "white" },
		{ "cat", "dog" },
		{ "day", "night" }
	};
	pair<pair<int, char>, pair<int, char>> pp = { { 6, 'c'} , { 90, '3'} };
	array<array<int, 3>, 3> aa;
	aa[0] = { 4, 5, 10 };
	aa[1] = { 90, -34, 7 };
	aa[2] = { -56, -45, 4 };
	vector<string> sss = { "str", "gg", "string" };
	map<int, string> m;
	m[1] = "hello";
	m[2] = "goodbue";
	m[3] = "nooo";
	

	

	
	//constexpr bool has = has1_ToString<A>().value;
	Print(A(), B(), m, some_map, _set("sep", '\n'), _set("end", '\n'));
	
	return 0;
}


/* Python code

a = [1,2,3,4,'hello',"world",33.13]
b = {1:3,2:6,3: 9}
c = ('w','h','t','f',1,2,3)


# [1, 2, 3, 4, 'hello', 'world', 33.13]
# {1: 3, 2: 6, 3: 9}
# ('w', 'h', 't', 'f', 1, 2, 3)
*/


/* Types

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
