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
};

template<typename T>
bool q(T t) {
	return 0;
}

template<typename T>
bool q2(T &t) {
	return is_array(T);
}

struct Data {
	Data() = delete;
	Data(string s) {
		data = s;
	}
	int ToInt() {
		return stoi(data);
	}

	operator std::string() {
		return data;
	}
	template<typename T>
	operator T() {
		return T();
	}
	friend ostream& operator <<(ostream& I, Data& t) {
		I << t.data;
		return I;
	}

private:
	string data;
	int a;
};

Data input() {
	string data;
	cin >> data;
	return Data(data);
}


int main() {
	
	srand(time(0));

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
	map<int, string> m;
	m[1] = "hello";
	m[2] = "goodbue";
	m[3] = "nooo";
	
	Print(Command("end", 12), m, '\n', sss, '\n', a1, '\n', aa, '\n', as, '\n', pp, '\n', p1);

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