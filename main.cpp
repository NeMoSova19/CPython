#include "CPython.h"
#include <chrono>
using namespace std;

class A{};


int main() {
	
	vector<int> v1 = { 1, 2, 3 };
	array<int, 3> v2 = { 1, 2, 3 };

	print(v1, "Hello", v2);

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