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

/// Input() - ¬вод 1 значени€ или контейнера до \n или размером Size
/// Text : —ообщение, которое выводитс€;
/// Size : ¬вод Size переменных в контейнер
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

	operator std::vector<int8_t>() {
		std::vector<int8_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			int8_t t;
			while (ss >> t) v.push_back(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push_back(Input());
		return v;
	}
	operator std::vector<int16_t>() {
		std::vector<int16_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			int16_t t;
			while (ss >> t) v.push_back(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push_back(Input());
		return v;
	}
	operator std::vector<int32_t>() {
		std::vector<int32_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			int32_t t;
			while (ss >> t) v.push_back(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push_back(Input());
		return v;
	}
	operator std::vector<int64_t>() {
		std::vector<int64_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			int64_t t;
			while (ss >> t) v.push_back(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push_back(Input());
		return v;
	}
	operator std::vector<uint8_t>() {
		std::vector<uint8_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			uint8_t t;
			while (ss >> t) v.push_back(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push_back(Input());
		return v;
	}
	operator std::vector<uint16_t>() {
		std::vector<uint16_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			uint16_t t;
			while (ss >> t) v.push_back(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push_back(Input());
		return v;
	}
	operator std::vector<uint32_t>() {
		std::vector<uint32_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			uint32_t t;
			while (ss >> t) v.push_back(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push_back(Input());
		return v;
	}
	operator std::vector<uint64_t>() {
		std::vector<uint64_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			uint64_t t;
			while (ss >> t) v.push_back(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push_back(Input());
		return v;
	}
	operator std::vector<float_t>() {
		std::vector<float_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			float_t t;
			while (ss >> t) v.push_back(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push_back(Input());
		return v;
	}
	operator std::vector<double_t>() {
		std::vector<double_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			double_t t;
			while (ss >> t) v.push_back(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push_back(Input());
		return v;
	}
	operator std::vector<bool>() {
		std::vector<bool> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			bool t;
			while (ss >> t) v.push_back(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push_back(Input());
		return v;
	}
	operator std::vector<std::string>() {
		std::vector<std::string> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			std::string t;
			while (ss >> t) v.push_back(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push_back(Input());
		return v;
	}
	template<typename T> operator std::vector<T>() {
		std::vector<T> v;
		if (_Size == npos) {
			v.push_back(Input());
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push_back(Input(_Size));
		return v;
		
	}
	
	operator std::list<int8_t>() {
		std::list<int8_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			int8_t t;
			while (ss >> t) v.push_back(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push_back(Input());
		return v;
	}
	operator std::list<int16_t>() {
		std::list<int16_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			int16_t t;
			while (ss >> t) v.push_back(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push_back(Input());
		return v;
	}
	operator std::list<int32_t>() {
		std::list<int32_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			int32_t t;
			while (ss >> t) v.push_back(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push_back(Input());
		return v;
	}
	operator std::list<int64_t>() {
		std::list<int64_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			int64_t t;
			while (ss >> t) v.push_back(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push_back(Input());
		return v;
	}
	operator std::list<uint8_t>() {
		std::list<uint8_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			uint8_t t;
			while (ss >> t) v.push_back(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push_back(Input());
		return v;
	}
	operator std::list<uint16_t>() {
		std::list<uint16_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			uint16_t t;
			while (ss >> t) v.push_back(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push_back(Input());
		return v;
	}
	operator std::list<uint32_t>() {
		std::list<uint32_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			uint32_t t;
			while (ss >> t) v.push_back(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push_back(Input());
		return v;
	}
	operator std::list<uint64_t>() {
		std::list<uint64_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			uint64_t t;
			while (ss >> t) v.push_back(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push_back(Input());
		return v;
	}
	operator std::list<float_t>() {
		std::list<float_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			float_t t;
			while (ss >> t) v.push_back(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push_back(Input());
		return v;
	}
	operator std::list<double_t>() {
		std::list<double_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			double_t t;
			while (ss >> t) v.push_back(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push_back(Input());
		return v;
	}
	operator std::list<bool>() {
		std::list<bool> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			bool t;
			while (ss >> t) v.push_back(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push_back(Input());
		return v;
	}
	operator std::list<std::string>() {
		std::list<std::string> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			std::string t;
			while (ss >> t) v.push_back(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push_back(Input());
		return v;
	}
	template<typename T> operator std::list<T>() {
		std::list<T> v;
		if (_Size == npos) {
			v.push_back(Input());
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push_back(Input(_Size));
		return v;

	}

	operator std::forward_list<int8_t>() {
		std::forward_list<int8_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			int8_t t;
			while (ss >> t) v.push_front(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push_front(Input());
		return v;
	}
	operator std::forward_list<int16_t>() {
		std::forward_list<int16_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			int16_t t;
			while (ss >> t) v.push_front(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push_front(Input());
		return v;
	}
	operator std::forward_list<int32_t>() {
		std::forward_list<int32_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			int32_t t;
			while (ss >> t) v.push_front(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push_front(Input());
		return v;
	}
	operator std::forward_list<int64_t>() {
		std::forward_list<int64_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			int64_t t;
			while (ss >> t) v.push_front(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push_front(Input());
		return v;
	}
	operator std::forward_list<uint8_t>() {
		std::forward_list<uint8_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			uint8_t t;
			while (ss >> t) v.push_front(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push_front(Input());
		return v;
	}
	operator std::forward_list<uint16_t>() {
		std::forward_list<uint16_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			uint16_t t;
			while (ss >> t) v.push_front(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push_front(Input());
		return v;
	}
	operator std::forward_list<uint32_t>() {
		std::forward_list<uint32_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			uint32_t t;
			while (ss >> t) v.push_front(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push_front(Input());
		return v;
	}
	operator std::forward_list<uint64_t>() {
		std::forward_list<uint64_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			uint64_t t;
			while (ss >> t) v.push_front(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push_front(Input());
		return v;
	}
	operator std::forward_list<float_t>() {
		std::forward_list<float_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			float_t t;
			while (ss >> t) v.push_front(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push_front(Input());
		return v;
	}
	operator std::forward_list<double_t>() {
		std::forward_list<double_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			double_t t;
			while (ss >> t) v.push_front(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push_front(Input());
		return v;
	}
	operator std::forward_list<bool>() {
		std::forward_list<bool> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			bool t;
			while (ss >> t) v.push_front(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push_front(Input());
		return v;
	}
	operator std::forward_list<std::string>() {
		std::forward_list<std::string> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			std::string t;
			while (ss >> t) v.push_front(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push_front(Input());
		return v;
	}
	template<typename T> operator std::forward_list<T>() {
		std::forward_list<T> v;
		if (_Size == npos) {
			v.push_front(Input());
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push_front(Input(_Size));
		return v;

	}

	operator std::set<int8_t>() {
		std::set<int8_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			int8_t t;
			while (ss >> t) v.insert(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.insert((int8_t)Input());
		return v;
	}
	operator std::set<int16_t>() {
		std::set<int16_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			int16_t t;
			while (ss >> t) v.insert(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.insert((int16_t)Input());
		return v;
	}
	operator std::set<int32_t>() {
		std::set<int32_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			int32_t t;
			while (ss >> t) v.insert(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.insert((int32_t)Input());
		return v;
	}
	operator std::set<int64_t>() {
		std::set<int64_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			int64_t t;
			while (ss >> t) v.insert(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.insert((int64_t)Input());
		return v;
	}
	operator std::set<uint8_t>() {
		std::set<uint8_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			uint8_t t;
			while (ss >> t) v.insert(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.insert((uint8_t)Input());
		return v;
	}
	operator std::set<uint16_t>() {
		std::set<uint16_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			uint16_t t;
			while (ss >> t) v.insert(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.insert((uint16_t)Input());
		return v;
	}
	operator std::set<uint32_t>() {
		std::set<uint32_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			uint32_t t;
			while (ss >> t) v.insert(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.insert((uint32_t)Input());
		return v;
	}
	operator std::set<uint64_t>() {
		std::set<uint64_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			uint64_t t;
			while (ss >> t) v.insert(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.insert((uint64_t)Input());
		return v;
	}
	operator std::set<float_t>() {
		std::set<float_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			float_t t;
			while (ss >> t) v.insert(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.insert((float_t)Input());
		return v;
	}
	operator std::set<double_t>() {
		std::set<double_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			double_t t;
			while (ss >> t) v.insert(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.insert((double_t)Input());
		return v;
	}
	operator std::set<bool>() {
		std::set<bool> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			bool t;
			while (ss >> t) v.insert(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.insert((bool)Input());
		return v;
	}
	operator std::set<std::string>() {
		std::set<std::string> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			std::string t;
			while (ss >> t) v.insert(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.insert((std::string)Input());
		return v;
	}
	template<typename T> operator std::set<T>() {
		std::set<T> v;
		if (_Size == npos) {
			v.insert(Input());
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.insert(Input(_Size));
		return v;

	}

	operator std::multiset<int8_t>() {
		std::multiset<int8_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			int8_t t;
			while (ss >> t) v.insert(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.insert((int8_t)Input());
		return v;
	}
	operator std::multiset<int16_t>() {
		std::multiset<int16_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			int16_t t;
			while (ss >> t) v.insert(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.insert((int16_t)Input());
		return v;
	}
	operator std::multiset<int32_t>() {
		std::multiset<int32_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			int32_t t;
			while (ss >> t) v.insert(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.insert((int32_t)Input());
		return v;
	}
	operator std::multiset<int64_t>() {
		std::multiset<int64_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			int64_t t;
			while (ss >> t) v.insert(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.insert((int64_t)Input());
		return v;
	}
	operator std::multiset<uint8_t>() {
		std::multiset<uint8_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			uint8_t t;
			while (ss >> t) v.insert(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.insert((uint8_t)Input());
		return v;
	}
	operator std::multiset<uint16_t>() {
		std::multiset<uint16_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			uint16_t t;
			while (ss >> t) v.insert(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.insert((uint16_t)Input());
		return v;
	}
	operator std::multiset<uint32_t>() {
		std::multiset<uint32_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			uint32_t t;
			while (ss >> t) v.insert(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.insert((uint32_t)Input());
		return v;
	}
	operator std::multiset<uint64_t>() {
		std::multiset<uint64_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			uint64_t t;
			while (ss >> t) v.insert(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.insert((uint64_t)Input());
		return v;
	}
	operator std::multiset<float_t>() {
		std::multiset<float_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			float_t t;
			while (ss >> t) v.insert(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.insert((float_t)Input());
		return v;
	}
	operator std::multiset<double_t>() {
		std::multiset<double_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			double_t t;
			while (ss >> t) v.insert(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.insert((double_t)Input());
		return v;
	}
	operator std::multiset<bool>() {
		std::multiset<bool> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			bool t;
			while (ss >> t) v.insert(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.insert((bool)Input());
		return v;
	}
	operator std::multiset<std::string>() {
		std::multiset<std::string> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			std::string t;
			while (ss >> t) v.insert(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.insert((std::string)Input());
		return v;
	}
	template<typename T> operator std::multiset<T>() {
		std::multiset<T> v;
		if (_Size == npos) {
			v.insert(Input());
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.insert(Input(_Size));
		return v;

	}

	operator std::unordered_set<int8_t>() {
		std::unordered_set<int8_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			int8_t t;
			while (ss >> t) v.insert(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.insert((int8_t)Input());
		return v;
	}
	operator std::unordered_set<int16_t>() {
		std::unordered_set<int16_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			int16_t t;
			while (ss >> t) v.insert(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.insert((int16_t)Input());
		return v;
	}
	operator std::unordered_set<int32_t>() {
		std::unordered_set<int32_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			int32_t t;
			while (ss >> t) v.insert(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.insert((int32_t)Input());
		return v;
	}
	operator std::unordered_set<int64_t>() {
		std::unordered_set<int64_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			int64_t t;
			while (ss >> t) v.insert(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.insert((int64_t)Input());
		return v;
	}
	operator std::unordered_set<uint8_t>() {
		std::unordered_set<uint8_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			uint8_t t;
			while (ss >> t) v.insert(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.insert((uint8_t)Input());
		return v;
	}
	operator std::unordered_set<uint16_t>() {
		std::unordered_set<uint16_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			uint16_t t;
			while (ss >> t) v.insert(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.insert((uint16_t)Input());
		return v;
	}
	operator std::unordered_set<uint32_t>() {
		std::unordered_set<uint32_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			uint32_t t;
			while (ss >> t) v.insert(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.insert((uint32_t)Input());
		return v;
	}
	operator std::unordered_set<uint64_t>() {
		std::unordered_set<uint64_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			uint64_t t;
			while (ss >> t) v.insert(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.insert((uint64_t)Input());
		return v;
	}
	operator std::unordered_set<float_t>() {
		std::unordered_set<float_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			float_t t;
			while (ss >> t) v.insert(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.insert((float_t)Input());
		return v;
	}
	operator std::unordered_set<double_t>() {
		std::unordered_set<double_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			double_t t;
			while (ss >> t) v.insert(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.insert((double_t)Input());
		return v;
	}
	operator std::unordered_set<bool>() {
		std::unordered_set<bool> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			bool t;
			while (ss >> t) v.insert(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.insert((bool)Input());
		return v;
	}
	operator std::unordered_set<std::string>() {
		std::unordered_set<std::string> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			std::string t;
			while (ss >> t) v.insert(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.insert((std::string)Input());
		return v;
	}
	template<typename T> operator std::unordered_set<T>() {
		std::unordered_set<T> v;
		if (_Size == npos) {
			v.insert(Input());
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.insert(Input(_Size));
		return v;

	}

	operator std::unordered_multiset<int8_t>() {
		std::unordered_multiset<int8_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			int8_t t;
			while (ss >> t) v.insert(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.insert((int8_t)Input());
		return v;
	}
	operator std::unordered_multiset<int16_t>() {
		std::unordered_multiset<int16_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			int16_t t;
			while (ss >> t) v.insert(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.insert((int16_t)Input());
		return v;
	}
	operator std::unordered_multiset<int32_t>() {
		std::unordered_multiset<int32_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			int32_t t;
			while (ss >> t) v.insert(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.insert((int32_t)Input());
		return v;
	}
	operator std::unordered_multiset<int64_t>() {
		std::unordered_multiset<int64_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			int64_t t;
			while (ss >> t) v.insert(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.insert((int64_t)Input());
		return v;
	}
	operator std::unordered_multiset<uint8_t>() {
		std::unordered_multiset<uint8_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			uint8_t t;
			while (ss >> t) v.insert(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.insert((uint8_t)Input());
		return v;
	}
	operator std::unordered_multiset<uint16_t>() {
		std::unordered_multiset<uint16_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			uint16_t t;
			while (ss >> t) v.insert(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.insert((uint16_t)Input());
		return v;
	}
	operator std::unordered_multiset<uint32_t>() {
		std::unordered_multiset<uint32_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			uint32_t t;
			while (ss >> t) v.insert(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.insert((uint32_t)Input());
		return v;
	}
	operator std::unordered_multiset<uint64_t>() {
		std::unordered_multiset<uint64_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			uint64_t t;
			while (ss >> t) v.insert(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.insert((uint64_t)Input());
		return v;
	}
	operator std::unordered_multiset<float_t>() {
		std::unordered_multiset<float_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			float_t t;
			while (ss >> t) v.insert(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.insert((float_t)Input());
		return v;
	}
	operator std::unordered_multiset<double_t>() {
		std::unordered_multiset<double_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			double_t t;
			while (ss >> t) v.insert(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.insert((double_t)Input());
		return v;
	}
	operator std::unordered_multiset<bool>() {
		std::unordered_multiset<bool> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			bool t;
			while (ss >> t) v.insert(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.insert((bool)Input());
		return v;
	}
	operator std::unordered_multiset<std::string>() {
		std::unordered_multiset<std::string> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			std::string t;
			while (ss >> t) v.insert(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.insert((std::string)Input());
		return v;
	}
	template<typename T> operator std::unordered_multiset<T>() {
		std::unordered_multiset<T> v;
		if (_Size == npos) {
			v.insert(Input());
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.insert(Input(_Size));
		return v;

	}

	operator std::queue<int8_t>() {
		std::queue<int8_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			int8_t t;
			while (ss >> t) v.push(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push(Input());
		return v;
	}
	operator std::queue<int16_t>() {
		std::queue<int16_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			int16_t t;
			while (ss >> t) v.push(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push(Input());
		return v;
	}
	operator std::queue<int32_t>() {
		std::queue<int32_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			int32_t t;
			while (ss >> t) v.push(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push(Input());
		return v;
	}
	operator std::queue<int64_t>() {
		std::queue<int64_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			int64_t t;
			while (ss >> t) v.push(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push(Input());
		return v;
	}
	operator std::queue<uint8_t>() {
		std::queue<uint8_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			uint8_t t;
			while (ss >> t) v.push(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push(Input());
		return v;
	}
	operator std::queue<uint16_t>() {
		std::queue<uint16_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			uint16_t t;
			while (ss >> t) v.push(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push(Input());
		return v;
	}
	operator std::queue<uint32_t>() {
		std::queue<uint32_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			uint32_t t;
			while (ss >> t) v.push(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push(Input());
		return v;
	}
	operator std::queue<uint64_t>() {
		std::queue<uint64_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			uint64_t t;
			while (ss >> t) v.push(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push(Input());
		return v;
	}
	operator std::queue<float_t>() {
		std::queue<float_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			float_t t;
			while (ss >> t) v.push(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push(Input());
		return v;
	}
	operator std::queue<double_t>() {
		std::queue<double_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			double_t t;
			while (ss >> t) v.push(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push(Input());
		return v;
	}
	operator std::queue<bool>() {
		std::queue<bool> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			bool t;
			while (ss >> t) v.push(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push(Input());
		return v;
	}
	operator std::queue<std::string>() {
		std::queue<std::string> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			std::string t;
			while (ss >> t) v.push(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push(Input());
		return v;
	}
	template<typename T> operator std::queue<T>() {
		std::queue<T> v;
		if (_Size == npos) {
			v.push(Input());
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push(Input(_Size));
		return v;

	}

	operator std::priority_queue<int8_t>() {
		std::priority_queue<int8_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			int8_t t;
			while (ss >> t) v.push(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push(Input());
		return v;
	}
	operator std::priority_queue<int16_t>() {
		std::priority_queue<int16_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			int16_t t;
			while (ss >> t) v.push(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push(Input());
		return v;
	}
	operator std::priority_queue<int32_t>() {
		std::priority_queue<int32_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			int32_t t;
			while (ss >> t) v.push(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push(Input());
		return v;
	}
	operator std::priority_queue<int64_t>() {
		std::priority_queue<int64_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			int64_t t;
			while (ss >> t) v.push(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push(Input());
		return v;
	}
	operator std::priority_queue<uint8_t>() {
		std::priority_queue<uint8_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			uint8_t t;
			while (ss >> t) v.push(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push(Input());
		return v;
	}
	operator std::priority_queue<uint16_t>() {
		std::priority_queue<uint16_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			uint16_t t;
			while (ss >> t) v.push(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push(Input());
		return v;
	}
	operator std::priority_queue<uint32_t>() {
		std::priority_queue<uint32_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			uint32_t t;
			while (ss >> t) v.push(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push(Input());
		return v;
	}
	operator std::priority_queue<uint64_t>() {
		std::priority_queue<uint64_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			uint64_t t;
			while (ss >> t) v.push(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push(Input());
		return v;
	}
	operator std::priority_queue<float_t>() {
		std::priority_queue<float_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			float_t t;
			while (ss >> t) v.push(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push(Input());
		return v;
	}
	operator std::priority_queue<double_t>() {
		std::priority_queue<double_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			double_t t;
			while (ss >> t) v.push(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push(Input());
		return v;
	}
	operator std::priority_queue<bool>() {
		std::priority_queue<bool> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			bool t;
			while (ss >> t) v.push(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push(Input());
		return v;
	}
	operator std::priority_queue<std::string>() {
		std::priority_queue<std::string> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			std::string t;
			while (ss >> t) v.push(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push(Input());
		return v;
	}
	template<typename T> operator std::priority_queue<T>() {
		std::priority_queue<T> v;
		if (_Size == npos) {
			v.push(Input());
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push(Input(_Size));
		return v;

	}

	operator std::deque<int8_t>() {
		std::deque<int8_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			int8_t t;
			while (ss >> t) v.push_back(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push_back(Input());
		return v;
	}
	operator std::deque<int16_t>() {
		std::deque<int16_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			int16_t t;
			while (ss >> t) v.push_back(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push_back(Input());
		return v;
	}
	operator std::deque<int32_t>() {
		std::deque<int32_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			int32_t t;
			while (ss >> t) v.push_back(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push_back(Input());
		return v;
	}
	operator std::deque<int64_t>() {
		std::deque<int64_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			int64_t t;
			while (ss >> t) v.push_back(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push_back(Input());
		return v;
	}
	operator std::deque<uint8_t>() {
		std::deque<uint8_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			uint8_t t;
			while (ss >> t) v.push_back(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push_back(Input());
		return v;
	}
	operator std::deque<uint16_t>() {
		std::deque<uint16_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			uint16_t t;
			while (ss >> t) v.push_back(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push_back(Input());
		return v;
	}
	operator std::deque<uint32_t>() {
		std::deque<uint32_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			uint32_t t;
			while (ss >> t) v.push_back(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push_back(Input());
		return v;
	}
	operator std::deque<uint64_t>() {
		std::deque<uint64_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			uint64_t t;
			while (ss >> t) v.push_back(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push_back(Input());
		return v;
	}
	operator std::deque<float_t>() {
		std::deque<float_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			float_t t;
			while (ss >> t) v.push_back(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push_back(Input());
		return v;
	}
	operator std::deque<double_t>() {
		std::deque<double_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			double_t t;
			while (ss >> t) v.push_back(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push_back(Input());
		return v;
	}
	operator std::deque<bool>() {
		std::deque<bool> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			bool t;
			while (ss >> t) v.push_back(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push_back(Input());
		return v;
	}
	operator std::deque<std::string>() {
		std::deque<std::string> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			std::string t;
			while (ss >> t) v.push_back(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push_back(Input());
		return v;
	}
	template<typename T> operator std::deque<T>() {
		std::deque<T> v;
		if (_Size == npos) {
			v.push_back(Input());
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push_back(Input(_Size));
		return v;

	}

	operator std::stack<int8_t>() {
		std::stack<int8_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			int8_t t;
			while (ss >> t) v.push(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push(Input());
		return v;
	}
	operator std::stack<int16_t>() {
		std::stack<int16_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			int16_t t;
			while (ss >> t) v.push(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push(Input());
		return v;
	}
	operator std::stack<int32_t>() {
		std::stack<int32_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			int32_t t;
			while (ss >> t) v.push(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push(Input());
		return v;
	}
	operator std::stack<int64_t>() {
		std::stack<int64_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			int64_t t;
			while (ss >> t) v.push(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push(Input());
		return v;
	}
	operator std::stack<uint8_t>() {
		std::stack<uint8_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			uint8_t t;
			while (ss >> t) v.push(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push(Input());
		return v;
	}
	operator std::stack<uint16_t>() {
		std::stack<uint16_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			uint16_t t;
			while (ss >> t) v.push(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push(Input());
		return v;
	}
	operator std::stack<uint32_t>() {
		std::stack<uint32_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			uint32_t t;
			while (ss >> t) v.push(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push(Input());
		return v;
	}
	operator std::stack<uint64_t>() {
		std::stack<uint64_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			uint64_t t;
			while (ss >> t) v.push(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push(Input());
		return v;
	}
	operator std::stack<float_t>() {
		std::stack<float_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			float_t t;
			while (ss >> t) v.push(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push(Input());
		return v;
	}
	operator std::stack<double_t>() {
		std::stack<double_t> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			double_t t;
			while (ss >> t) v.push(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push(Input());
		return v;
	}
	operator std::stack<bool>() {
		std::stack<bool> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			bool t;
			while (ss >> t) v.push(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push(Input());
		return v;
	}
	operator std::stack<std::string>() {
		std::stack<std::string> v;
		if (_Size == npos) {
			std::stringstream ss(StoSS());
			std::string t;
			while (ss >> t) v.push(t);
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push(Input());
		return v;
	}
	template<typename T> operator std::stack<T>() {
		std::stack<T> v;
		if (_Size == npos) {
			v.push(Input());
			return v;
		}
		for (size_t i = 0; i < _Size; i++) v.push(Input(_Size));
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
