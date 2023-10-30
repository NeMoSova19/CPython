#include "CPython.h"
#include <chrono>
using namespace std;

class A{};


int main() {
	
	vector<int> v1 = { 1, 2, 3 };
	array<int, 3> v2 = { 1, 2, 3 };

	vector<vector<vector<int>>> vIN2 = { 
		{ {1, 3, 3}, {1, 2, 2} }, 
		{ {1, 4, 3}, {1, 5, 3}, {1, 2, 1} }, 
		{ {1, 1, 1} }, 
		{ {1, 2, 6}, {5, 5, 3} }, 
		{ {1, 9, 3}, {1, 10, 3}, {1, 2, 3} },
		{ {1, 2, 11}, {1, 2, 12}, {13, 2, 3} }
	};

	//print(v1 SearchIn v2);

	map<int, int> m;

	set<int> l = { 1, 2, 3 };

	

	print(search_in("20", vIN2), dimensial_size(vIN2));

	return 0;
}


//auto t1 = std::chrono::system_clock::now(); 
	//for (size_t i = 0; i < 10000; i++) { 
	//	//print(1); //  4.77261  //  4.37907  //  4.47151
	//	//cout << 1 << '\n'; //  4.61076  // 4.53652  //  4.51189			
	//}
	//auto t2 = std::chrono::system_clock::now(); 
	//
	//print('\n', chrono::duration<double>(t2 - t1).count()); 


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