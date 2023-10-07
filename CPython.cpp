#include "CPython.h"

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


Input::Input(std::string s, size_t Size) : _Size(Size) { std::cout << s; }
Input::Input(size_t Size) : _Size(Size) {  }
template<typename T> Input::operator T() { T v; std::cin >> v; return v; }
template<typename T1, typename T2> Input::operator std::pair<T1, T2>() {
		std::pair<T1, T2> v;
		v.first = Input(); v.second = Input();
		return v;
	}
	template<typename T1, typename T2> Input::operator std::map<T1, T2>() {
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
	template<typename T1, typename T2> Input::operator std::unordered_map<T1, T2>() {
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
	template<typename T, size_t N> Input::operator std::array<T, N>() {
		std::array<T, N> v;
		if (_Size >= N) for (size_t i = 0; i < N; i++) v[i] = Input();
		else for (size_t i = 0; i < _Size; i++) v[i] = Input();
		return v;
	}
	template<typename T> Input::operator std::vector<T>() {
		//vector<vector<vector<...>>> not working. WIP
		std::vector<T> v;
		static_assert(!is_class<T>::value, "Error: Multidimensional vectors dont work, WIP");
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
	template<typename T> Input::operator std::list<T>() {
		//list<list<list<...>>> not working. WIP
		std::list<T> v;
		static_assert(!is_class<T>::value, "Error: Multidimensional lists dont work, WIP");
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
	template<typename T> Input::operator std::forward_list<T>() {
		//forward_list<forward_list<forward_list<...>>> not working. WIP
		std::forward_list<T> v;
		static_assert(!is_class<T>::value, "Error: Multidimensional forward_lists dont work, WIP");
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
	template<typename T> Input::operator std::set<T>() {
		//set<set<set<...>>> not working. WIP
		std::set<T> v;
		static_assert(!is_class<T>::value, "Error: Multidimensional sets dont work, WIP");
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
	template<typename T> Input::operator std::multiset<T>() {
		//multiset<multiset<multiset<...>>> not working. WIP
		std::multiset<T> v;
		static_assert(!is_class<T>::value, "Error: Multidimensional multisets dont work, WIP");
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
	template<typename T> Input::operator std::unordered_set<T>() {
		//unordered_set<unordered_set<unordered_set<...>>> not working. WIP
		std::unordered_set<T> v;
		static_assert(!is_class<T>::value, "Error: Multidimensional unordered_sets dont work, WIP");
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
	template<typename T> Input::operator std::unordered_multiset<T>() {
		//unordered_multiset<unordered_multiset<unordered_multiset<...>>> not working. WIP
		std::unordered_multiset<T> v;
		static_assert(!is_class<T>::value, "Error: Multidimensional unordered_multisets dont work, WIP");
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
	template<typename T> Input::operator std::queue<T>() {
		//queue<queue<queue<...>>> not working. WIP
		std::queue<T> v;
		static_assert(!is_class<T>::value, "Error: Multidimensional queues dont work, WIP");
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
	template<typename T> Input::operator std::priority_queue<T>() {
		//priority_queue<priority_queue<priority_queue<...>>> not working. WIP
		std::priority_queue<T> v;
		static_assert(!is_class<T>::value, "Error: Multidimensional priority_queues dont work, WIP");
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
	template<typename T> Input::operator std::deque<T>() {
		//deque<deque<deque<...>>> not working. WIP
		std::deque<T> v;
		static_assert(!is_class<T>::value, "Error: Multidimensional deques dont work, WIP");
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
	template<typename T> Input::operator std::stack<T>() {
		//stack<stack<stack<...>>> not working. WIP
		std::stack<T> v;
		static_assert(!is_class<T>::value, "Error: Multidimensional stacks dont work, WIP");
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

	//template<typename T, typename... Args> auto Input::operator [](size_t Size) {
	//	T v[Size] ;
	//	for (size_t i = 0; i < Size; i++) v[i] = Input();
	//	return v;
	//}

	template<typename T> auto Input::operator +(T t) { T v; std::cin >> v; return v + t; }
	template<typename T> auto Input::operator -(T t) { T v; std::cin >> v; return v - t; }
	template<typename T> auto Input::operator ~() { T v; std::cin >> v; return ~v; }
	template<typename T> auto Input::operator !() { T v; std::cin >> v; return !v; }
	template<typename T> auto Input::operator ++() { T v; std::cin >> v; return v++; }
	template<typename T> auto Input::operator ++(T) { T v; std::cin >> v; return ++v; }
	template<typename T> auto Input::operator --() { T v; std::cin >> v; return v--; }
	template<typename T> auto Input::operator --(T) { T v; std::cin >> v; return --v; }
	template<typename T> auto Input::operator *(T t) { T v; std::cin >> v; return v * t; }
	template<typename T> auto Input::operator /(T t) { T v; std::cin >> v; return v / t; }
	template<typename T> auto Input::operator %(T t) { T v; std::cin >> v; return v % t; }
	template<typename T> auto Input::operator >>(int t) { T v; std::cin >> v; return v >> t; }
	template<typename T> auto Input::operator <<(int t) { T v; std::cin >> v; return v << t; }
	template<typename T> auto Input::operator <(T t) { T v; std::cin >> v; return v < t; }
	template<typename T> auto Input::operator >(T t) { T v; std::cin >> v; return v > t; }
	template<typename T> auto Input::operator <=(T t) { T v; std::cin >> v; return v <= t; }
	template<typename T> auto Input::operator >=(T t) { T v; std::cin >> v; return v >= t; }
	template<typename T> auto Input::operator ==(T t) { T v; std::cin >> v; return v == t; }
	template<typename T> auto Input::operator !=(T t) { T v; std::cin >> v; return v != t; }
	template<typename T> auto Input::operator &(T t) { T v; std::cin >> v; return v & t; }
	template<typename T> auto Input::operator ^(T t) { T v; std::cin >> v; return v ^ t; }
	template<typename T> auto Input::operator |(T t) { T v; std::cin >> v; return v | t; }
	template<typename T> auto Input::operator &&(T t) { T v; std::cin >> v; return v && t; }
	template<typename T> auto Input::operator ||(T t) { T v; std::cin >> v; return v || t; }

