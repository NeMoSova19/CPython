#include "CPython.h"
#include <fstream>
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

_Temp_T
struct MyVector : public vector<T> {
	
	
};




int main() {
	std::setlocale(0, "ru");

	Input::Open("test.txt"); // перенаправление ввода из файла
	int n = Input(">> ¬вод из файла\n");
	Print(n, "чисел:");

	for (int i = 0; i < n; i++)
	{
		Print(Input(),_set("end"," "));
	}


	Input::Close(); // перенаправление ввода из стандартного потока
	n = Input("\n\n>> ¬вод из потока\n¬ведите количество чисел: ");
	vector<int> vec(n);
	for (int i = 0; i < n; i++)
	{
		string s = to_string(i + 1);
		s += ") ";
		vec[i] = Input(s);
	}
	for (int i = 0; i < n; i++) {
		Print(vec[i], _set("end", " "));
	}


	Print("\n>> чтение из другого потока");
	stringstream ss("hello world and hello world again and stop 1243 441 33");
	Input::Open(ss.rdbuf()); // перенаправление ввода в какой-нибудь поток, который имеет функцию rdbuf()
	while (!Input::Eof()) { // чтение пока поток не пуст
		Print(Input());
	}


	Input::Close(); // не забываем вернуть стандартный поток
	//а ниже прикольный фокус
	int k = Input("напишите двузначное число здесь __ - ваше число!\rнапишите двузначное число здесь ");

	

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
