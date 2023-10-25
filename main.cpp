#include "CPython.h"
#include <Windows.h>
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

class Base {
protected:
	int num{ 99 };
};
class A : private Base {
	friend ostream& operator << (ostream&, A const&);
};
class B : private Base {
	friend ostream& operator << (ostream&, B&);
};
class C : private Base{
public:
	std::string ToString() const {
		return "From C -> " + to_string(num);
	}
};


ostream& operator << (ostream& o, A const& a) {
	return o << "From A -> " << a.num;
}
ostream& operator << (ostream& o, B& b) {
	return o << "From B -> " << b.num;
}


int main() {
	//std::setlocale(0, "ru");

	A a; B b; C c;
	print(a, b, c);

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
