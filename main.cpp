#include "CPython.h"
#include <chrono>
using namespace std;

class A{};


int main() {
	
	A a;

	ifstream f;

	//cout << input().rdbuf()->getloc().name().size(); //прикольно)

	vector<int> v = input("Text: ", 5);
	
	print(v, '\n');

	v = input("Only text: ");

	print(v, '\n');

	v = input(3); //No text

	print(v, '\n');


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

/*
* print(1)
* 
$LN4@main:
  lea rcx, QWORD PTR $T4[rsp]
  call _Print print<int>(int) ; print<int>
  lea rcx, QWORD PTR $T4[rsp]
  call _Print::~_Print(void) ; _Print::~_Print

* cout << 1 << ' '
* 
$LN4@main:
  lea rcx, OFFSET FLAT:std::basic_ostream<char,std::char_traits<char> > std::cout ; std::cout
  call std::basic_ostream<char,std::char_traits<char> > & std::basic_ostream<char,std::char_traits<char> >::operator<<(int) ; std::basic_ostream<char,std::char_traits<char> >::operator<<
  mov QWORD PTR tv73[rsp], rax
  mov dl, 32 ; 00000020H
  mov rcx, QWORD PTR tv73[rsp]
  call std::basic_ostream<char,std::char_traits<char> > & std::operator<<<std::char_traits<char> >(std::basic_ostream<char,std::char_traits<char> > &,char) ; std::operator<<<std::char_traits<char> >
*/