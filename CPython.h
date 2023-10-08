#pragma once
#include <iostream>
#include <sstream>
#include <type_traits>

#include <string>
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

class Input {
	Input(Input&&) = delete;
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
	//vector<vector<vector<...>>> not working. WIP
	template<typename T> operator std::vector<T>() {
		std::vector<T> v;
		static_assert(!std::is_class<T>::value, "Error: Multidimensional vectors dont work, WIP");
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
	//list<list<list<...>>> not working. WIP
	template<typename T> operator std::list<T>() {
		std::list<T> v;
		static_assert(!std::is_class<T>::value, "Error: Multidimensional lists dont work, WIP");
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
	//forward_list<forward_list<forward_list<...>>> not working. WIP
	template<typename T> operator std::forward_list<T>() {
		std::forward_list<T> v;
		static_assert(!std::is_class<T>::value, "Error: Multidimensional forward_lists dont work, WIP");
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
	//set<set<set<...>>> not working. WIP
	template<typename T> operator std::set<T>() {
		std::set<T> v;
		static_assert(!std::is_class<T>::value, "Error: Multidimensional sets dont work, WIP");
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
	//multiset<multiset<multiset<...>>> not working. WIP
	template<typename T> operator std::multiset<T>() {
		std::multiset<T> v;
		static_assert(!std::is_class<T>::value, "Error: Multidimensional multisets dont work, WIP");
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
	//unordered_set<unordered_set<unordered_set<...>>> not working. WIP
	template<typename T> operator std::unordered_set<T>() {
		std::unordered_set<T> v;
		static_assert(!std::is_class<T>::value, "Error: Multidimensional unordered_sets dont work, WIP");
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
	//unordered_multiset<unordered_multiset<unordered_multiset<...>>> not working. WIP
	template<typename T> operator std::unordered_multiset<T>() {
		std::unordered_multiset<T> v;
		static_assert(!std::is_class<T>::value, "Error: Multidimensional unordered_multisets dont work, WIP");
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
	//queue<queue<queue<...>>> not working. WIP
	template<typename T> operator std::queue<T>() {
		std::queue<T> v;
		static_assert(!std::is_class<T>::value, "Error: Multidimensional queues dont work, WIP");
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
	//priority_queue<priority_queue<priority_queue<...>>> not working. WIP
	template<typename T> operator std::priority_queue<T>() {
		std::priority_queue<T> v;
		static_assert(!std::is_class<T>::value, "Error: Multidimensional priority_queues dont work, WIP");
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
	//deque<deque<deque<...>>> not working. WIP
	template<typename T> operator std::deque<T>() {
		std::deque<T> v;
		static_assert(!std::is_class<T>::value, "Error: Multidimensional deques dont work, WIP");
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
	//stack<stack<stack<...>>> not working. WIP
	template<typename T> operator std::stack<T>() {
		std::stack<T> v;
		static_assert(!std::is_class<T>::value, "Error: Multidimensional stacks dont work, WIP");
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

// WIP WIP WIP WIP WIP WIP WIP WIP
template<typename... T>
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


template<typename T, typename C> bool in(T t, C container) {


}


#define in(t, container) t in container
#define in(t, container) t not in container


