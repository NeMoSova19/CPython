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
	Input(std::string s = "", size_t Size = npos);
	Input(size_t Size);
	template<typename T> operator T();
	template<typename T1, typename T2> operator std::pair<T1, T2>();
	template<typename T1, typename T2> operator std::map<T1, T2>();
	template<typename T1, typename T2> operator std::unordered_map<T1, T2>();
	template<typename T, size_t N> operator std::array<T, N>();
	template<typename T> operator std::vector<T>();
	template<typename T> operator std::list<T>();
	template<typename T> operator std::forward_list<T>();
	template<typename T> operator std::set<T>();
	template<typename T> operator std::multiset<T>();
	template<typename T> operator std::unordered_set<T>();
	template<typename T> operator std::unordered_multiset<T>();
	template<typename T> operator std::queue<T>();
	template<typename T> operator std::priority_queue<T>();
	template<typename T> operator std::deque<T>();
	template<typename T> operator std::stack<T>();



	template<typename T> auto operator +(T t);
	template<typename T> auto operator -(T t);
	template<typename T> auto operator ~();
	template<typename T> auto operator !();
	template<typename T> auto operator ++();
	template<typename T> auto operator ++(T);
	template<typename T> auto operator --();
	template<typename T> auto operator --(T);
	template<typename T> auto operator *(T t);
	template<typename T> auto operator /(T t);
	template<typename T> auto operator %(T t);
	template<typename T> auto operator >>(int t);
	template<typename T> auto operator <<(int t);
	template<typename T> auto operator <(T t);
	template<typename T> auto operator >(T t);
	template<typename T> auto operator <=(T t);
	template<typename T> auto operator >=(T t);
	template<typename T> auto operator ==(T t);
	template<typename T> auto operator !=(T t);
	template<typename T> auto operator &(T t);
	template<typename T> auto operator ^(T t);
	template<typename T> auto operator |(T t);
	template<typename T> auto operator &&(T t);
	template<typename T> auto operator ||(T t);
};



template<class... T>
struct Print {
	Print() = delete;
	Print(Print&&) = delete;
	
	Print(T... t) {
		_print(t...);
	}
	/*void operator ()(T ...t) {
		_print(t...);
	}
	
	enum Preset {
		standart,
		fast,
		beautiful
	};

	static inline Print Settings(Preset pres) {
		Print prt;
		prt.preset = pres;
		return prt;
	}*/

private:
	//Preset preset{ standart };

private:
	template<typename R> void _print(R t) {
		std::cout << t;
	}
	template<typename R, typename P> void _print(std::pair<R,P> t) {
		_print(t.first); _print(t.second);
	}
	template<typename R, typename P> void _print(std::map<R, P> v) {
		for (auto i : v) _print(i);
	}
	template<typename R> void _print(std::vector<R> v) {
		for (auto i : v) _print(i);
	}
	template<typename R> void _print(std::list<R> v) {
		for (auto i : v) _print(i);
	}
	template<typename R> void _print(std::set<R> v) {
		for (auto i : v) _print(i);
	}
	template<typename R> void _print(std::queue<R> v) {
		for (auto i : v) _print(i);
	}
	template<typename R> void _print(std::deque<R> v) {
		for (auto i : v) _print(i);
	}
	template<typename R> void _print(std::stack<R> v) {
		for (auto i : v) _print(i);
	}
	template<typename R, size_t N> void _print(std::array<R, N> v) {
		for (auto i : v) _print(i);
	}
	template<typename R, typename... P> void _print(R v, P... w) {
		_print(v); _print(w...);
	}
};
//
//template<typename T> void Print(T t);
//template<typename T, typename... Args> void Print(T t, Args... args);
//template<class T1, class T2> void Print(std::pair<T1, T2> p);
//template<class T> void Print(std::vector<T> v);
//
//
//
//template <typename T> void Print(T t) { std::cout << t; }
//
//template<typename T, typename... Args> void Print(T t, Args... args)
//{
//	Print(t); std::cout << ' '; Print(args...);
//}
//
//template <class T1, class T2> void Print(std::pair<T1, T2> p) {
//	std::cout << "[";  Print(p.first); std::cout << ", "; Print(p.second); std::cout << "]";
//}
//
//template<class T> void Print(std::vector<T> v) {
//	std::cout << "[";
//	auto i = v.begin();
//	for (size_t _i = 0; _i < v.size() - 1; _i++) {
//		Print(*i);  std::cout << ", ";
//		i++;
//	}
//	Print(*i);
//	std::cout << "]";
//}
//
////WIP
////template<typename... Args> void Print(std::tuple<Args...> v) {
////	std::cout << "[";
////	auto i = v.begin();
////	for (size_t _i = 0; _i < v.size() - 1; _i++) {
////		Print(*i);  std::cout << ", ";
////		i++;
////	}
////	Print(*i);
////	std::cout << "]";
////}
////WIP
//
//template<class T, size_t N> void Print(std::array<T, N> v) {
//	std::cout << "[";
//	auto i = v.begin();
//	for (size_t _i = 0; _i < N - 1; _i++) {
//		Print(*i);  std::cout << ", ";
//		i++;
//	}
//	Print(*i);
//	std::cout << "]";
//}
//
//template<class T1, class T2> void Print(std::map<T1, T2> v) {
//	std::cout << "{\n";
//	for (auto u : v) {
//		std::cout << "    ";
//		Print(u.first);  
//		std::cout << ": ";
//		Print(u.second);  
//		std::cout << "\n";
//	}
//	std::cout << "}";
//}

/*
map - { } - key : val
arrays - [ ]
pair - < >
*/







