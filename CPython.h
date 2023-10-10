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

/// Input() - ¬вод 1 значени€ или контейнера до n или размером Size
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
	STD(STD&&) = delete;

template<typename... T>
	STD(T... t) {
		_print(t...);
	}

	~STD()
	{
		std::cout << end;
	}

	std::string end{ '\n' };
	std::string separator{ ", "};
	
private:
	template<typename R> void _print(R t) {
		std::cout << t;
	}
	template<> void _print(bool t) {
		std::cout << std::boolalpha << t;
	}
	template<typename R, typename P> void _print(std::pair<R,P> t) {
		std::cout << '<';
		_print(t.first);
		std::cout << separator;
		_print(t.second);
		std::cout << '>';
	}
	template<typename R, typename P> void _print(std::map<R, P> v) {
		std::cout << '{';
		int cnt{ 0 };
		for (auto i : v) {
			_print(i);
			if (cnt + 1 < v.size()) {
				std::cout << separator;
			}
			cnt++;
		}
		std::cout << '}';
	}
	template<typename R, typename P> void _print(std::unordered_map<R, P> v) {
		std::cout << '{';
		int cnt{ 0 };
		for (auto i : v) {
			_print(i);
			if (cnt + 1 < v.size()) {
				std::cout << separator;
			}
			cnt++;
		}
		std::cout << '}';
	}
	template<typename R, size_t N> void _print(std::array<R, N> v) {
		std::cout << '[';
		int cnt{ 0 };
		for (auto i : v) {
			_print(i);
			if (cnt + 1 < v.size()) {
				std::cout << separator;
			}
			cnt++;
		}
		std::cout << ']';
	}
	template<typename R> void _print(std::vector<R> v) {
		std::cout << '[';
		int cnt{ 0 };
		for (auto i : v) {
			_print(i);
			if (cnt+1 < v.size()) {
				std::cout << separator;
			}
			cnt++;
		}
		std::cout << ']';
	}
	template<typename R> void _print(std::list<R> v) {
		std::cout << '[';
		int cnt{ 0 };
		for (auto i : v) {
			_print(i);
			if (cnt + 1 < v.size()) {
				std::cout << separator;
			}
			cnt++;
		}
		std::cout << ']';
	}
	template<typename R> void _print(std::forward_list<R> v) {
		std::cout << '[';
		int cnt{ 0 };
		for (auto i : v) {
			_print(i);
			if (cnt + 1 < v.size()) {
				std::cout << separator;
			}
			cnt++;
		}
		std::cout << ']';
	}
	template<typename R> void _print(std::set<R> v) {
		std::cout << '[';
		int cnt{ 0 };
		for (auto i : v) {
			_print(i);
			if (cnt + 1 < v.size()) {
				std::cout << separator;
			}
			cnt++;
		}
		std::cout << ']';
	}
	template<typename R> void _print(std::multiset<R> v) {
		std::cout << '[';
		int cnt{ 0 };
		for (auto i : v) {
			_print(i);
			if (cnt + 1 < v.size()) {
				std::cout << separator;
			}
			cnt++;
		}
		std::cout << ']';
	}
	template<typename R> void _print(std::unordered_set<R> v) {
		std::cout << '[';
		int cnt{ 0 };
		for (auto i : v) {
			_print(i);
			if (cnt + 1 < v.size()) {
				std::cout << separator;
			}
			cnt++;
		}
		std::cout << ']';
	}
	template<typename R> void _print(std::unordered_multiset<R> v) {
		std::cout << '[';
		int cnt{ 0 };
		for (auto i : v) {
			_print(i);
			if (cnt + 1 < v.size()) {
				std::cout << separator;
			}
			cnt++;
		}
		std::cout << ']';
	}
	template<typename R> void _print(std::queue<R> v) {
		std::cout << '[';
		auto vnew = v;
		while (true) {
			_print(vnew.front());
			vnew.pop();
			if (vnew.empty()) break;
			std::cout << separator;
		}
		std::cout << ']';
	}
	template<typename R> void _print(std::priority_queue<R> v) {
		std::cout << '[';
		auto vnew = v;
		while(true) {
			_print(vnew.front());
			vnew.pop();
			if (vnew.empty()) break;
			std::cout << separator;
		}
		std::cout << ']';
	}
	template<typename R> void _print(std::deque<R> v) {
		std::cout << '[';
		int cnt{ 0 };
		for (auto i : v) {
			_print(i);
			if (cnt + 1 < v.size()) {
				std::cout << separator;
			}
			cnt++;
		}
		std::cout << ']';
	}
	template<typename R> void _print(std::stack<R> v) {
		std::cout << '[';
		auto vnew = v;
		while (true) {
			_print(vnew.top());
			vnew.pop();
			if (vnew.empty()) break;
			std::cout << separator;
		}
		std::cout << ']';
	}
	template<typename R, typename... P> void _print(R v, P... w) {
		_print(v);
		std::cout << separator;
		_print(w...);
	}
};

template<typename ...T>
void Print(T... tmp) {
	STD st(tmp...);
}





/// <summary>
/// Not working
/// </summary>
namespace _In {
	class OperatorIn {};

	template<typename Tin>
	struct InSearch {
		const Tin& m_in;
		InSearch(const Tin& val) : m_in(val) {};
		template<typename T> bool operator *(T& what) { return _in(m_in, what); }

		template<typename T1, typename T2> bool _in(std::pair<T1, T2> p1, std::pair<T1, T2> p2) {
			return (p1.first == p2.first) && (p1.second == p2.second);
		}
		
		template<typename Search, typename T1, typename T2> bool _in(Search t, std::pair<T1, T2> V) {
			if constexpr (typeid(Search) == typeid(T1)) return _in(t, V.first);
			if constexpr (typeid(Search) == typeid(T2)) return _in(t, V.second);
			return false;
		}
		
		template<typename Search, typename T1, typename T2> bool _in(Search t, std::map<T1, T2> V) {
			std::map<T1, T2> v;

			return v;
		}
		
		template<typename Search, typename T1, typename T2> bool _in(Search t, std::unordered_map<T1, T2> V) {
			std::unordered_map<T1, T2> v;

			return v;
		}
		
		template<typename T, size_t N1, size_t N2> bool _in(std::array<T, N1> V1, std::array<T, N2> V2) {
			if (N1 != N2) return false;
			bool opt = true;
			for (size_t i = 0; i < N1; i++) {
				opt &= _in(V1[i], V2[i]);
				if (!opt) return false;
			}
			return opt;
		}
		template<typename Search, typename T, size_t N> bool _in(Search t, std::array<T, N> V) {
			bool opt = false;
			if (typeid(Search) == typeid(T)) {
				for (size_t i = 0; i < N; i++) {
					opt |= _in(t, V[i]);
					if (opt) return true;
				}
			};
			return opt;
		}
	
		template<typename T> bool _in(std::vector<T> V1, std::vector<T> V2) {
			if (V1.size() != V2.size()) return false;
			bool opt = true;
			for (size_t i = 0; i < V1.size(); i++) {
				opt &= _in(V1[i], V2[i]);
				if (!opt) return false;
			}
			return opt;
		}
		template<typename Search, typename T> bool _in(Search t, std::vector<T> V) {
			bool opt = false;
			if (typeid(Search) == typeid(T)) {
				for (size_t i = 0; i < V.size(); i++) {
					opt |= _in(t, V[i]);
					if (opt) return true;
				}
			};
			return opt;
		}

		template<typename Search, typename T> bool _in(Search t, std::list<T> V) {
			std::list<T> v;

			return v;
		}
		
		template<typename Search, typename T> bool _in(Search t, std::forward_list<T> V) {
			std::forward_list<T> v;

			return v;
		}
		
		template<typename Search, typename T> bool _in(Search t, std::set<T> V) {
			std::set<T> v;

			return v;
		}
		
		template<typename Search, typename T> bool _in(Search t, std::multiset<T> V) {
			std::multiset<T> v;

			return v;
		}
		
		template<typename Search, typename T> bool _in(Search t, std::unordered_set<T> V) {
			std::unordered_set<T> v;

			return v;
		}
		
		template<typename Search, typename T> bool _in(Search t, std::unordered_multiset<T> V) {
			std::unordered_multiset<T> v;

			return v;
		}
		
		template<typename Search, typename T> bool _in(Search t, T V) { return t == V; }

	};
	template<typename T> InSearch<T> operator *(const T& data, const OperatorIn&) { return InSearch<T>(data); }
}
#define in *_In::OperatorIn{}*







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
