#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <tuple>
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

struct Input {
private:
	size_t _Size{1};
public:
	Input(std::string s = "", size_t Size = 1) : _Size(Size) { std::cout << s; }
	Input(size_t Size) : _Size(Size) {  }
	template<typename T> operator T() { T v; std::cin >> v; return v; }
	template<typename T1, typename T2> operator std::pair<T1, T2>() {
		std::pair<T1, T2> v;
		v.first = Input(); v.second = Input();
		return v;
	}
	
	//WIP
	//template<typename... Args> operator std::tuple<Args...>() {
	//	std::tuple<Args...> v;
	//	for (size_t i = 0; i < _Size; i++) {
	//		v[0];
	//	}
	//	return v;
	//} 
	//WIP

	template<typename T1, typename T2> operator std::map<T1, T2>() {
		std::map<T1, T2> v;
		for (size_t i = 0; i < _Size; i++) {
			T1 t1 = Input(); T2 t2 = Input();
			v.insert({ t1, t2 });
		}
		return v;
	}
	template<typename T1, typename T2> operator std::unordered_map<T1, T2>() {
		std::unordered_map<T1, T2> v;
		for (size_t i = 0; i < _Size; i++) {
			T1 t1 = Input(); T2 t2 = Input();
			v.insert({ t1, t2 });
		}
		return v;
	}
	template<typename T, size_t N> operator std::array<T, N>() {
		std::array<T, N> v;
		for (size_t i = 0; i < N; i++) v[i] = Input();
		return v;
	}
	template<typename T> operator std::vector<T>() {
		std::vector<T> v;
		//T x = Input();
		//v.push_back(x);
		std::string s;
		char c = std::cin.get();
		std::getline(std::cin, s);
		if (c != '\n') s = c + s;
		std::stringstream ss(s);
		//if (_Size == 1);
		T t;
		while (ss >> t) v.push_back(t);
		return v;
	}
	template<typename T> operator std::list<T>() {
		std::list<T> v;
		std::string s;
		char c = std::cin.get();
		std::getline(std::cin, s);
		if (c != '\n') s = c + s;
		std::stringstream ss(s);
		T t;
		while (ss >> t) v.push_back(t);
		return v;
	}
	template<typename T> operator std::forward_list<T>() {
		std::forward_list<T> v;
		std::string s;
		char c = std::cin.get();
		std::getline(std::cin, s);
		if (c != '\n') s = c + s;
		std::stringstream ss(s);
		T t;
		while (ss >> t) v.push_front(t);
		return v;
	}
	template<typename T> operator std::set<T>() {
		std::set<T> v;
		std::string s;
		char c = std::cin.get();
		std::getline(std::cin, s);
		if (c != '\n') s = c + s;
		std::stringstream ss(s);
		T t;
		while (ss >> t) v.insert(t);
		return v;
	}
	template<typename T> operator std::multiset<T>() {
		std::multiset<T> v;
		std::string s;
		char c = std::cin.get();
		std::getline(std::cin, s);
		if (c != '\n') s = c + s;
		std::stringstream ss(s);
		T t;
		while (ss >> t) v.insert(t);
		return v;
	}
	template<typename T> operator std::unordered_set<T>() {
		std::unordered_set<T> v;
		std::string s;
		char c = std::cin.get();
		std::getline(std::cin, s);
		if (c != '\n') s = c + s;
		std::stringstream ss(s);
		T t;
		while (ss >> t) v.insert(t);
		return v;
	}
	template<typename T> operator std::unordered_multiset<T>() {
		std::unordered_multiset<T> v;
		std::string s;
		char c = std::cin.get();
		std::getline(std::cin, s);
		if (c != '\n') s = c + s;
		std::stringstream ss(s);
		T t;
		while (ss >> t) v.insert(t);
		return v;
	}
	template<typename T> operator std::queue<T>() {
		std::queue<T> v;
		std::string s;
		char c = std::cin.get();
		std::getline(std::cin, s);
		if (c != '\n') s = c + s;
		std::stringstream ss(s);
		T t;
		while (ss >> t) v.push(t);
		return v;
	}
	template<typename T> operator std::priority_queue<T>() {
		std::priority_queue<T> v;
		std::string s;
		char c = std::cin.get();
		std::getline(std::cin, s);
		if (c != '\n') s = c + s;
		std::stringstream ss(s);
		T t;
		while (ss >> t) v.push(t);
		return v;
	}
	template<typename T> operator std::deque<T>() {
		std::deque<T> v;
		std::string s;
		char c = std::cin.get();
		std::getline(std::cin, s);
		if (c != '\n') s = c + s;
		std::stringstream ss(s);
		T t;
		while (ss >> t) v.push_back(t);
		return v;
	}
	template<typename T> operator std::stack<T>() {
		std::stack<T> v;
		std::string s;
		char c = std::cin.get();
		std::getline(std::cin, s);
		if (c != '\n') s = c + s;
		std::stringstream ss(s);
		T t;
		while (ss >> t) v.push(t);
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

//WIP
//template<typename... Args> void Print(std::tuple<Args...> v) {
//	std::cout << "[";
//	auto i = v.begin();
//	for (size_t _i = 0; _i < v.size() - 1; _i++) {
//		Print(*i);  std::cout << ", ";
//		i++;
//	}
//	Print(*i);
//	std::cout << "]";
//}
//WIP

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


