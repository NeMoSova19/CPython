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


//static_assert(!(std::is_class<T>::value && typeid(std::string) != typeid(T)), "Error: Multidimensional vectors dont work, WIP");

/// Input() - ���� 1 �������� ��� ���������� �� \n ��� �������� Size
/// Text : ���������, ������� ���������;
/// Size : ���� Size ���������� � ���������
class Input {
	Input(Input&&) = delete;
	static inline size_t npos{ (size_t)-1 };
	size_t _Size{npos};
	std::string StoSS() {
		std::string s;
		char c = std::cin.get();
		std::getline(std::cin, s);
		if (c != '\n') s = c + s;
		return s;
	}
public:
	Input(std::string Text = "", size_t Size = npos) : _Size(Size) { std::cout << Text; }
	Input(size_t Size) : _Size(Size) {  }
	template<typename T> operator T() { T v; std::cin >> v; return v; }
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
	template<typename T1, typename T2> operator std::pair<T1, T2>() {
		std::pair<T1, T2> v;
		v.first = Input(); v.second = Input();
		return v;
	}
	template<typename T1, typename T2> operator std::map<T1, T2>() {
		std::map<T1, T2> v;
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
		std::vector<T> v;
		if (_Size != npos) {
			for (size_t i = 0; i < _Size; i++) v.push_back(Input(_Size));
			return v;
		}
		if constexpr (!std::is_class<T>::value || typeid(T) == typeid(std::string)) {
			std::stringstream ss(StoSS());
			T t;
			while (ss >> t) v.push_back(t);
			return v;
		}
		v.push_back(Input());
		return v;
	}
	template<typename T> operator std::list<T>() {
		std::list<T> v;
		if (_Size != npos) {
			for (size_t i = 0; i < _Size; i++) v.push_back(Input(_Size));
			return v;
		}
		if constexpr (!std::is_class<T>::value || typeid(T) == typeid(std::string)) {
			std::stringstream ss(StoSS());
			T t;
			while (ss >> t) v.push_back(t);
			return v;
		}
		v.push_back(Input());
		return v;
	}
	template<typename T> operator std::forward_list<T>() {
		std::forward_list<T> v;
		if (_Size != npos) {
			for (size_t i = 0; i < _Size; i++) v.push_front(Input(_Size));
			return v;
		}
		if constexpr (!std::is_class<T>::value || typeid(T) == typeid(std::string)) {
			std::stringstream ss(StoSS());
			T t;
			while (ss >> t) v.push_front(t);
			return v;
		}
		v.push_front(Input());
		return v;
	}
	template<typename T> operator std::set<T>() {
		std::set<T> v;
		if (_Size != npos) {
			for (size_t i = 0; i < _Size; i++) {
				T t = Input(_Size);
				v.insert(t);
			}
			return v;
		}
		if constexpr (!std::is_class<T>::value || typeid(T) == typeid(std::string)) {
			std::stringstream ss(StoSS());
			T t;
			while (ss >> t) v.insert(t);
			return v;
		}
		T t = Input();
		v.insert(t);
		return v;
	}
	template<typename T> operator std::multiset<T>() {
		std::multiset<T> v;
		if (_Size != npos) {
			for (size_t i = 0; i < _Size; i++) {
				T t = Input(_Size);
				v.insert(t);
			}
			return v;
		}
		if constexpr (!std::is_class<T>::value || typeid(T) == typeid(std::string)) {
			std::stringstream ss(StoSS());
			T t;
			while (ss >> t) v.insert(t);
			return v;
		}
		T t = Input();
		v.insert(t);
		return v;
		return v;
	}
	template<typename T> operator std::unordered_set<T>() {
		std::unordered_set<T> v;
		if (_Size != npos) {
			for (size_t i = 0; i < _Size; i++) {
				T t = Input(_Size);
				v.insert(t);
			}
			return v;
		}
		if constexpr (!std::is_class<T>::value || typeid(T) == typeid(std::string)) {
			std::stringstream ss(StoSS());
			T t;
			while (ss >> t) v.insert(t);
			return v;
		}
		T t = Input();
		v.insert(t);
		return v;
		return v;
	}
	template<typename T> operator std::unordered_multiset<T>() {
		std::unordered_multiset<T> v;
		if (_Size != npos) {
			for (size_t i = 0; i < _Size; i++) {
				T t = Input(_Size);
				v.insert(t);
			}
			return v;
		}
		if constexpr (!std::is_class<T>::value || typeid(T) == typeid(std::string)) {
			std::stringstream ss(StoSS());
			T t;
			while (ss >> t) v.insert(t);
			return v;
		}
		T t = Input();
		v.insert(t);
		return v;
		return v;
    }
	template<typename T> operator std::queue<T>() {
		std::queue<T> v;
		if (_Size != npos) {
			for (size_t i = 0; i < _Size; i++) v.push(Input(_Size));
			return v;
		}
		if constexpr (!std::is_class<T>::value || typeid(T) == typeid(std::string)) {
			std::stringstream ss(StoSS());
			T t;
			while (ss >> t) v.push(t);
			return v;
		}
		v.push(Input());
		return v;
	}
	template<typename T> operator std::priority_queue<T>() {
		std::priority_queue<T> v;
		if (_Size != npos) {
			for (size_t i = 0; i < _Size; i++) v.push(Input(_Size));
			return v;
		}
		if constexpr (!std::is_class<T>::value || typeid(T) == typeid(std::string)) {
			std::stringstream ss(StoSS());
			T t;
			while (ss >> t) v.push(t);
			return v;
		}
		v.push(Input());
		return v;
	}
	template<typename T> operator std::deque<T>() {
		std::deque<T> v;
		if (_Size != npos) {
			for (size_t i = 0; i < _Size; i++) v.push_back(Input(_Size));
			return v;
		}
		if constexpr (!std::is_class<T>::value || typeid(T) == typeid(std::string)) {
			std::stringstream ss(StoSS());
			T t;
			while (ss >> t) v.push_back(t);
			return v;
		}
		v.push_back(Input());
		return v;		
	}
	template<typename T> operator std::stack<T>() {
		std::stack<T> v;
		if (_Size != npos) {
			for (size_t i = 0; i < _Size; i++) v.push(Input(_Size));
			return v;
		}
		if constexpr (!std::is_class<T>::value || typeid(T) == typeid(std::string)) {
			std::stringstream ss(StoSS());
			T t;
			while (ss >> t) v.push(t);
			return v;
		}
		v.push(Input());
		return v;
	}
};


// WIP WIP WIP WIP WIP WIP WIP WIP
struct STD {
	
template<typename... T>
	static inline void Print(T... t) {
		_print(standart, t...);
	}

	enum Preset {
		standart,
		fast,
		beautiful
	};

template<typename... T>
	static inline void Print(Preset pres, T... t) {
		_print(pres, t...);
	}
	
private:

	template<typename R> static inline void _print(Preset pres, R t) {
		std::cout << t;
	}
	template<typename R, typename P> static inline void _print(Preset pres, std::pair<R,P> t) {
		switch (pres)
		{
		case STD::fast:
			break;
		case STD::standart:
		case STD::beautiful:
			std::cout << '<';
			break;
		}
		_print(pres, t.first); 
		switch (pres)
		{
		case STD::fast:
			std::cout << ' ';
			break;
		case STD::standart:
		case STD::beautiful:
			std::cout << ", ";
			break;
		}
		_print(pres, t.second);
		switch (pres)
		{
		case STD::fast:
			break;
		case STD::standart:
		case STD::beautiful:
			std::cout << '>';
			break;
		}
	}
	template<typename R, typename P> static inline void _print(Preset pres, std::map<R, P> v) {
		for (auto i : v) _print(pres, i);
	}
	template<typename R> static inline void _print(Preset pres, std::vector<R> v) {
		switch (pres)
		{
		case STD::fast:
			break;
		case STD::standart:
		case STD::beautiful:
			std::cout << '[';
				break;
		}
		
		int cnt{ 0 };
		for (auto i : v) {
			_print(pres, i);
			
			if (cnt+1 < v.size()) {
				switch (pres)
				{
				case STD::fast:
					std::cout << ' ';
					break;
				case STD::standart:
				case STD::beautiful:
					std::cout << ", ";
					break;
				}
			}

			cnt++;
		}

		switch (pres)
		{
		case STD::fast: 
			break;
		case STD::standart: 
		case STD::beautiful:
			std::cout << ']';
				break;
		}
	}
	template<typename R> static inline void _print(Preset pres, std::list<R> v) {
		for (auto i : v) _print(pres, i);
	}
	template<typename R> static inline void _print(Preset pres, std::set<R> v) {
		for (auto i : v) _print(pres, i);
	}
	template<typename R> static inline void _print(Preset pres, std::queue<R> v) {
		for (auto i : v) _print(pres, i);
	}
	template<typename R> static inline void _print(Preset pres, std::deque<R> v) {
		for (auto i : v) _print(pres, i);
	}
	template<typename R> void _print(Preset pres, std::stack<R> v) {
		for (auto i : v) _print(pres, i);
	}
	template<typename R, size_t N> static inline void _print(Preset pres, std::array<R, N> v) {
		for (auto i : v) _print(pres, i);
	}
	template<typename R, typename... P> static inline void _print(Preset pres, R v, P... w) {
		_print(pres, v);
		switch (pres)
		{
		case STD::fast:
			std::cout << ' ';
			break;
		case STD::standart:
		case STD::beautiful:
			std::cout << ", ";
			break;
		}
		_print(pres, w...);
	}
};
#define Print(a) STD::Print(a)




class InSearch {
	template<typename T1, typename T2> bool _in(std::pair<T1, T2> V) {
		std::pair<T1, T2> v;
		
		return v;
	}
	template<typename T1, typename T2> bool _in(std::map<T1, T2> V) {
		std::map<T1, T2> v;
		
		return v;
	}
	template<typename T1, typename T2> bool _in(std::unordered_map<T1, T2> V) {
		std::unordered_map<T1, T2> v;
		
		return v;
	}
	template<typename T, size_t N> bool _in(std::array<T, N> V) {
		std::array<T, N> v;
		
		return v;
	}
	template<typename T> bool _in(std::vector<T> V) {
		std::vector<T> v;
		
		return v;
	}
	template<typename T> bool _in(std::list<T> V) {
		std::list<T> v;
		
		return v;
	}
	template<typename T> bool _in(std::forward_list<T> V) {
		std::forward_list<T> v;
		
		return v;
	}
	template<typename T> bool _in(std::set<T> V) {
		std::set<T> v;
		
		return v;
	}
	template<typename T> bool _in(std::multiset<T> V) {
		std::multiset<T> v;
		
		return v;
	}
	template<typename T> bool _in(std::unordered_set<T> V) {
		std::unordered_set<T> v;
		
		return v;
	}
	template<typename T> bool _in(std::unordered_multiset<T> V) {
		std::unordered_multiset<T> v;
		
		return v;
	}
public:
	template<typename T, typename C> bool _in_(T t, C container) {
		if (!std::is_class<C>::value) {
			



			return 0;
		}

		if (typeid(std::string) != typeid(T)) {


		}
		//text.find()




		return 0;
	}


};





//#define in InSearch::in(t, container)
//#define t not in container !InSearch::in(t, container)


//static_assert(!(std::is_class<C>::value && typeid(std::string) != typeid(T)), "Error: Multidimensional containers dont work, WIP");

/*

<string>
<array>
<vector>
<list>
<forward_list>
<set>
<unordered_set>
<map>
<unordered_map>
<queue>
<deque>
<stack>

*/
