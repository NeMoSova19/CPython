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





int main() {
	std::setlocale(0, "ru");

	Input::Open("Test.txt");
	
	while(!Input::Eof()) {
		Print(Input::GetLine()); // появляется буква "я" если в конце стоит \n(перенос строки) !
	}

	return 0;
}

/*

	std::ifstream in("in.txt");
	std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

	std::string word;
	std::cin >> word;           //input from the file in.txt

	std::cin.rdbuf(cinbuf);   //reset to standard input again

	std::cin >> word;   //input from the standard input

*/

	//std::apply([](auto&&... args) {((std::cin >> args), ...); }, t);


	//std::apply([](auto&&... args) {((std::cout << args << '\n'), ...); }, t);

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
