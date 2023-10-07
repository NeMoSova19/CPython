#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <array>
#include <vector>
#include <list>
#include <forward_list>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <stack>

#include <type_traits>

class Input {
private:
	static inline size_t npos{ (size_t)-1 };
	size_t _Size{npos};
public:
	Input(std::string s = "", size_t Size = npos) : _Size(Size) { std::cout << s; }
	Input(size_t Size) : _Size(Size) {  }
	template<typename T> operator T() { T v; std::cin >> v; return v; }
	template<typename T1, typename T2> operator std::pair<T1, T2>() {
		std::pair<T1, T2> v;
		v.first = Input(); v.second = Input();
		return v;
	}
	template<typename T1, typename T2> operator std::map<T1, T2>() {
		std::map<T1, T2> v;
		if (_Size == 0) return v;
		if (_Size == npos) {
			T1 t1 = Input(); T2 t2 = Input();
			v.insert({ t1, t2 });
			return v;
		}
		for (size_t i = 0; i < _Size; i++) {
			T1 t1 = Input(); T2 t2 = Input();
			v.insert({ t1, t2 });
		}
		return v;
	}
	template<typename T1, typename T2> operator std::unordered_map<T1, T2>() {
		std::unordered_map<T1, T2> v;
		if (_Size == npos) {
			T1 t1 = Input(); T2 t2 = Input();
			v.insert({ t1, t2 });
			return v;
		}
		for (size_t i = 0; i < _Size; i++) {
			T1 t1 = Input(); T2 t2 = Input();
			v.insert({ t1, t2 });
		}
		return v;
	}
	template<typename T, size_t N> operator std::array<T, N>() {
		std::array<T, N> v;
		if (_Size >= N) for (size_t i = 0; i < N; i++) v[i] = Input();
		else for (size_t i = 0; i < _Size; i++) v[i] = Input();
		return v;
	}
	template<typename T> operator std::vector<T>() {
		//vector<vector<vector<...>>> not working. WIP
		std::vector<T> v;
		if (_Size == npos) {
			std::string s;
			char c = std::cin.get();
			std::getline(std::cin, s);
			if (c != '\n') s = c + s;
			std::stringstream ss(s);
			T t;
			while (ss >> t) v.push_back(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push_back(Input());
		return v;
	}
	template<typename T> operator std::list<T>() {
		//list<list<list<...>>> not working. WIP
		std::list<T> v;
		if (_Size == npos) {
			std::string s;
			char c = std::cin.get();
			std::getline(std::cin, s);
			if (c != '\n') s = c + s;
			std::stringstream ss(s);
			T t;
			while (ss >> t) v.push_back(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push_back(Input());
		return v;
	}
	template<typename T> operator std::forward_list<T>() {
		//forward_list<forward_list<forward_list<...>>> not working. WIP
		std::forward_list<T> v;
		if (_Size == npos) {
			std::string s;
			char c = std::cin.get();
			std::getline(std::cin, s);
			if (c != '\n') s = c + s;
			std::stringstream ss(s);
			T t;
			while (ss >> t) v.push_front(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push_front(Input());
		return v;
	}
	template<typename T> operator std::set<T>() {
		//set<set<set<...>>> not working. WIP
		std::set<T> v;
		if (_Size == npos) {
			std::string s;
			char c = std::cin.get();
			std::getline(std::cin, s);
			if (c != '\n') s = c + s;
			std::stringstream ss(s);
			T t;
			while (ss >> t) v.insert(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.insert(Input());
		return v;
	}
	template<typename T> operator std::multiset<T>() {
		//multiset<multiset<multiset<...>>> not working. WIP
		std::multiset<T> v;
		if (_Size == npos) {
			std::string s;
			char c = std::cin.get();
			std::getline(std::cin, s);
			if (c != '\n') s = c + s;
			std::stringstream ss(s);
			T t;
			while (ss >> t) v.insert(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.insert(Input());
		return v;
	}
	template<typename T> operator std::unordered_set<T>() {
		//unordered_set<unordered_set<unordered_set<...>>> not working. WIP
		std::unordered_set<T> v;
		if (_Size == npos) {
			std::string s;
			char c = std::cin.get();
			std::getline(std::cin, s);
			if (c != '\n') s = c + s;
			std::stringstream ss(s);
			T t;
			while (ss >> t) v.insert(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.insert(Input());
		return v;
	}
	template<typename T> operator std::unordered_multiset<T>() {
		//unordered_multiset<unordered_multiset<unordered_multiset<...>>> not working. WIP
		std::unordered_multiset<T> v;
		if (_Size == npos) {
			std::string s;
			char c = std::cin.get();
			std::getline(std::cin, s);
			if (c != '\n') s = c + s;
			std::stringstream ss(s);
			T t;
			while (ss >> t) v.insert(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.insert(Input());
		return v;
	}
	template<typename T> operator std::queue<T>() {
		//queue<queue<queue<...>>> not working. WIP
		std::queue<T> v;
		if (_Size == npos) {
			std::string s;
			char c = std::cin.get();
			std::getline(std::cin, s);
			if (c != '\n') s = c + s;
			std::stringstream ss(s);
			T t;
			while (ss >> t) v.push(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push(Input());
		return v;
	}
	template<typename T> operator std::priority_queue<T>() {
		//priority_queue<priority_queue<priority_queue<...>>> not working. WIP
		std::priority_queue<T> v;
		if (_Size == npos) {
			std::string s;
			char c = std::cin.get();
			std::getline(std::cin, s);
			if (c != '\n') s = c + s;
			std::stringstream ss(s);
			T t;
			while (ss >> t) v.push(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push(Input());
		return v;
	}
	template<typename T> operator std::deque<T>() {
		//deque<deque<deque<...>>> not working. WIP
		std::deque<T> v;
		if (_Size == npos) {
			std::string s;
			char c = std::cin.get();
			std::getline(std::cin, s);
			if (c != '\n') s = c + s;
			std::stringstream ss(s);
			T t;
			while (ss >> t) v.push_back(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push_back(Input());
		return v;
	}
	template<typename T> operator std::stack<T>() {
		//stack<stack<stack<...>>> not working. WIP
		std::stack<T> v;
		if (_Size == npos) {
			std::string s;
			char c = std::cin.get();
			std::getline(std::cin, s);
			if (c != '\n') s = c + s;
			std::stringstream ss(s);
			T t;
			while (ss >> t) v.push(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push(Input());
		return v;
	}

	//template<typename T, typename... Args> auto operator [](size_t Size) {
	//	T v[Size] ;
	//	for (size_t i = 0; i < Size; i++) v[i] = Input();
	//	return v;
	//}

	template<typename T> auto operator +(T t) { T v; std::cin >> v; return v + t; }
	template<typename T> auto operator -(T t) { T v; std::cin >> v; return v - t; }
	template<typename T> auto operator ~() { T v; std::cin >> v; return ~v; }
	template<typename T> auto operator !() { T v; std::cin >> v; return !v; }
	template<typename T> auto operator ++() { T v; std::cin >> v; return v++; }
	template<typename T> auto operator ++(T) { T v; std::cin >> v; return ++v; }
	template<typename T> auto operator --() { T v; std::cin >> v; return v--; }
	template<typename T> auto operator --(T) { T v; std::cin >> v; return --v; }
	template<typename T> auto operator *(T t) { T v; std::cin >> v; return v * t; }
	template<typename T> auto operator /(T t) { T v; std::cin >> v; return v / t; }
	template<typename T> auto operator %(T t) { T v; std::cin >> v; return v % t; }
	template<typename T> auto operator >>(int t) { T v; std::cin >> v; return v >> t; }
	template<typename T> auto operator <<(int t) { T v; std::cin >> v; return v << t; }
	template<typename T> auto operator <(T t) { T v; std::cin >> v; return v < t; }
	template<typename T> auto operator >(T t) { T v; std::cin >> v; return v > t; }
	template<typename T> auto operator <=(T t) { T v; std::cin >> v; return v <= t; }
	template<typename T> auto operator >=(T t) { T v; std::cin >> v; return v >= t; }
	template<typename T> auto operator ==(T t) { T v; std::cin >> v; return v == t; }
	template<typename T> auto operator !=(T t) { T v; std::cin >> v; return v != t; }
	template<typename T> auto operator &(T t) { T v; std::cin >> v; return v & t; }
	template<typename T> auto operator ^(T t) { T v; std::cin >> v; return v ^ t; }
	template<typename T> auto operator |(T t) { T v; std::cin >> v; return v | t; }
	template<typename T> auto operator &&(T t) { T v; std::cin >> v; return v && t; }
	template<typename T> auto operator ||(T t) { T v; std::cin >> v; return v || t; }
};

template<typename T> void Print(T t);
template<typename T, typename... Args> void Print(T t, Args... args);
template<class T1, class T2> void Print(std::pair<T1, T2> p);
template<class T> void Print(std::vector<T> v);



template <typename T> void Print(T t) { std::cout << t; }

template<typename T, typename... Args> void Print(T t, Args... args)
{
	Print(t); std::cout << ' '; Print(args...);
}

template <class T1, class T2> void Print(std::pair<T1, T2> p) {
	std::cout << "[";  Print(p.first); std::cout << ", "; Print(p.second); std::cout << "]";
}

template<class T> void Print(std::vector<T> v) {
	std::cout << "[";
	auto i = v.begin();
	for (size_t _i = 0; _i < v.size() - 1; _i++) {
		Print(*i);  std::cout << ", ";
		i++;
	}
	Print(*i);
	std::cout << "]";
}

template<class T, size_t N> void Print(std::array<T, N> v) {
	std::cout << "[";
	auto i = v.begin();
	for (size_t _i = 0; _i < N - 1; _i++) {
		Print(*i);  std::cout << ", ";
		i++;
	}
	Print(*i);
	std::cout << "]";
}

template<class T1, class T2> void Print(std::map<T1, T2> v) {
	std::cout << "{\n";
	for (auto u : v) {
		std::cout << "    ";
		Print(u.first);  
		std::cout << ": ";
		Print(u.second);  
		std::cout << "\n";
	}
	std::cout << "}";
}

/*
map - { } - key : val
arrays - [ ]
pair - < >
*/


