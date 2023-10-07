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