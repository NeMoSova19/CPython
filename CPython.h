#pragma once
#include <iostream>
#include <sstream>
#include <type_traits>
#include <ostream>
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
 
/// Input() - ���� 1 �������� ��� ���������� �� n ��� �������� Size
/// Text : ���������, ������� ���������;
/// Size : ���� Size ���������� � ���������;
/// = : Container_Type T = Input();
/// == : { Container_Type T; }
///         { T == Input();         };
class Input {
	static inline size_t npos{ (size_t)-1 };
	size_t _Size{npos};
	static std::string StoSS() {
		std::string s;
		char c = std::cin.get();
		std::getline(std::cin, s);
		if (c != '\n') s = c + s;
		return s;
	}
	friend struct STD;
public:
	Input(std::string Text = "", size_t Size = npos) : _Size(Size) { std::cout << Text; }
	Input(size_t Size) : _Size(Size) {  }
	template <typename T> operator T() {T v; std::cin >> v; return v;}
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
template<typename T1, typename T2> void operator ==(std::pair<T1, T2>& V, Input I) {
	std::pair<T1, T2> v = I;
	V = v;
}
template<typename T1, typename T2> void operator ==(std::map<T1, T2>& V, Input I) {
	std::map<T1, T2> v = I;
	V = v;
}
template<typename T1, typename T2> void operator ==(std::unordered_map<T1, T2>& V, Input I) {
	std::unordered_map<T1, T2> v = I;
	V = v;
}
template<typename T, size_t N> void operator ==(std::array<T, N>& V, Input I) {
	std::array<T, N> v = I;
	V = v;
}
template<typename T> void operator ==(std::vector<T>& V, Input I) {
	std::vector<T> v = I;
	V = v;
}
template<typename T> void operator ==(std::list<T>& V, Input I) {
	std::list<T> v = I;
	V = v;
}
template<typename T> void operator ==(std::forward_list<T>& V, Input I) {
	std::forward_list<T> v = I;
	V = v;
}
template<typename T> void operator ==(std::set<T>& V, Input I) {
	std::set<T> v = I;
	V = v;
}
template<typename T> void operator ==(std::multiset<T>& V, Input I) {
	std::multiset<T> v = I;
	V = v;
}
template<typename T> void operator ==(std::unordered_set<T>& V, Input I) {
	std::unordered_set<T> v = I;
	V = v;
}
template<typename T> void operator ==(std::unordered_multiset<T>& V, Input I) {
	std::unordered_multiset<T> v = I;
	V = v;
}
template<typename T> void operator ==(std::queue<T>& V, Input I) {
	std::queue<T> v = I;
	V = v;
}
template<typename T> void operator ==(std::priority_queue<T>& V, Input I) {
	std::priority_queue<T> v = I;
	V = v;
}
template<typename T> void operator ==(std::deque<T>& V, Input I) {
	std::deque<T> v = I;
	V = v;
}
template<typename T> void operator ==(std::stack<T>& V, Input I) {
	std::stack<T> v = I;
	V = v;
}
template<typename T> bool operator ==(T& t, Input I) {
	if constexpr (std::is_class<T>::value && typeid(T) != typeid(std::string)) {
		T v = I;
		t = v;
		return true;
	}
	T tnew = I;
	return t == tnew;
}

template<typename T>
struct Command {
	Command(std::string com, T op) :command(com), _operator(op) {}

	std::string command;
	T _operator;
};
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
	std::string separator{ " "};
private:
	std::string separator_in_containers{", "};
	std::string separator_in_map{": "};

	std::string brakets_in_array{"[]"};
	std::string brakets_in_tuple{"()"};
	std::string brakets_in_map{"{}"};

	template<typename R> void _print(R t) {
		std::cout << t;
	}
	template<typename T> void _print(Command<T> t) {
		std::cout << t.command << ' ' << t._operator << '\n';
	}
	template<> void _print(bool t) {
		std::cout << std::boolalpha << t;
	}
	template<typename R, typename P> void _print(std::pair<R,P> t) {
		std::cout << brakets_in_array[0];
		_print(t.first);
		std::cout << separator_in_containers;
		_print(t.second);
		std::cout << brakets_in_array[1];
	}
	template<typename R, typename P> void _print(std::map<R, P> v) {
		std::cout << brakets_in_map[0];
		int cnt{ 0 };
		for (auto i : v) {
			_print(i.first);
			std::cout << separator_in_map;
			_print(i.second);
			if (cnt + 1 < v.size()) {
				std::cout << separator_in_containers;
			}
			cnt++;
		}
		std::cout << brakets_in_map[1];
	}
	template<typename R, typename P> void _print(std::unordered_map<R, P> v) {
		std::cout << brakets_in_map[0];
		int cnt{ 0 };
		for (auto i : v) {
			_print(i.first);
			std::cout << separator_in_map;
			_print(i.second);
			if (cnt + 1 < v.size()) {
				std::cout << separator_in_containers;
			}
			cnt++;
		}
		std::cout << brakets_in_map[1];
	}
	template<typename R, size_t N> void _print(std::array<R, N> v) {
		std::cout << brakets_in_array[0];
		int cnt{ 0 };
		for (auto i : v) {
			_print(i);
			if (cnt + 1 < v.size()) {
				std::cout << separator_in_containers;
			}
			cnt++;
		}
		std::cout << brakets_in_array[1];
	}
	template<typename R> void _print(std::vector<R> v) {
		std::cout << brakets_in_array[0];
		int cnt{ 0 };
		for (auto i : v) {
			_print(i);
			if (cnt + 1 < v.size()) {
				std::cout << separator_in_containers;
			}
			cnt++;
		}
		std::cout << brakets_in_array[1];
	}
	template<typename R> void _print(std::list<R> v) {
		std::cout << brakets_in_array[0];
		int cnt{ 0 };
		for (auto i : v) {
			_print(i);
			if (cnt + 1 < v.size()) {
				std::cout << separator_in_containers;
			}
			cnt++;
		}
		std::cout << brakets_in_array[1];
	}
	template<typename R> void _print(std::forward_list<R> v) {
		std::cout << brakets_in_array[0];
		int cnt{ 0 };
		for (auto i : v) {
			_print(i);
			if (cnt + 1 < v.size()) {
				std::cout << separator_in_containers;
			}
			cnt++;
		}
		std::cout << brakets_in_array[1];
	}
	template<typename R> void _print(std::set<R> v) {
		std::cout << brakets_in_array[0];
		int cnt{ 0 };
		for (auto i : v) {
			_print(i);
			if (cnt + 1 < v.size()) {
				std::cout << separator_in_containers;
			}
			cnt++;
		}
		std::cout << brakets_in_array[1];
	}
	template<typename R> void _print(std::multiset<R> v) {
		std::cout << brakets_in_array[0];
		int cnt{ 0 };
		for (auto i : v) {
			_print(i);
			if (cnt + 1 < v.size()) {
				std::cout << separator_in_containers;
			}
			cnt++;
		}
		std::cout << brakets_in_array[1];
	}
	template<typename R> void _print(std::unordered_set<R> v) {
		std::cout << brakets_in_array[0];
		int cnt{ 0 };
		for (auto i : v) {
			_print(i);
			if (cnt + 1 < v.size()) {
				std::cout << separator_in_containers;
			}
			cnt++;
		}
		std::cout << brakets_in_array[1];
	}
	template<typename R> void _print(std::unordered_multiset<R> v) {
		std::cout << brakets_in_array[0];
		int cnt{ 0 };
		for (auto i : v) {
			_print(i);
			if (cnt + 1 < v.size()) {
				std::cout << separator_in_containers;
			}
			cnt++;
		}
		std::cout << brakets_in_array[1];
	}
	template<typename R> void _print(std::queue<R> v) {
		std::cout << brakets_in_array[0];
		auto vnew = v;
		while (true) {
			_print(vnew.front());
			vnew.pop();
			if (vnew.empty()) break;
			std::cout << separator_in_containers;
		}
		std::cout << brakets_in_array[1];
	}
	template<typename R> void _print(std::priority_queue<R> v) {
		std::cout << brakets_in_array[0];
		auto vnew = v;
		while (true) {
			_print(vnew.front());
			vnew.pop();
			if (vnew.empty()) break;
			std::cout << separator_in_containers;
		}
		std::cout << brakets_in_array[1];
	}
	template<typename R> void _print(std::deque<R> v) {
		std::cout << brakets_in_array[0];
		int cnt{ 0 };
		for (auto i : v) {
			_print(i);
			if (cnt + 1 < v.size()) {
				std::cout << separator_in_containers;
			}
			cnt++;
		}
		std::cout << brakets_in_array[1];
	}
	template<typename R> void _print(std::stack<R> v) {
		std::cout << brakets_in_array[0];
		auto vnew = v;
		while (true) {
			_print(vnew.front());
			vnew.pop();
			if (vnew.empty()) break;
			std::cout << separator_in_containers;
		}
		std::cout << brakets_in_array[1];
	}
	template<typename R, typename... P> void _print(R v, P... w) {
		_print(v);
		std::cout << separator;
		_print(w...);
	}
};
template<typename ...T>
void Print(T... Args) {
	auto tuple = std::forward_as_tuple(std::forward<T>(Args)...);
	auto size = sizeof...(Args);
	std::cout << "Info\nlength of parameter pack = "<< size << '\n';
	for (size_t i = 0; i < size; i++)
	{
		if constexpr (typeid(tuple.get<i>()) == typeid(Command)) {

		}
	}
	STD st(Args...);
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
	private:
		template<typename T1, typename T2> bool _in(std::pair<T1, T2> p1, std::pair<T1, T2> p2) {
			return (p1.first == p2.first) && (p1.second == p2.second);
		}
		
		template<typename Search, typename T1, typename T2> bool _in(Search t, std::pair<T1, T2> V) {
			if constexpr (typeid(Search) == typeid(T1)) return _in(t, V.first);
			if constexpr (typeid(Search) == typeid(T2)) return _in(t, V.second);
			return false;
		}
		
		template<typename Search, typename T1, typename T2> bool _in(Search t, std::map<T1, T2> V) {
			return false;
		}
		
		template<typename Search, typename T1, typename T2> bool _in(Search t, std::unordered_map<T1, T2> V) {
			return false;
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
			for (size_t i = 0; i < N; i++) {
				opt |= _in(t, V[i]);
				if (opt) return true;
			}
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
			for (size_t i = 0; i < V.size(); i++) {
				opt |= _in(t, V[i]);
				if (opt) return true;
			}
			return opt;
		}

		template<typename Search, typename T> bool _in(Search t, std::list<T> V) {
			return false;
		}
		
		template<typename Search, typename T> bool _in(Search t, std::forward_list<T> V) {
			return false;
		}
		
		template<typename Search, typename T> bool _in(Search t, std::set<T> V) {
			return false;
		}
		
		template<typename Search, typename T> bool _in(Search t, std::multiset<T> V) {
			return false;
		}
		
		template<typename Search, typename T> bool _in(Search t, std::unordered_set<T> V) {
			return false;
		}
		
		template<typename Search, typename T> bool _in(Search t, std::unordered_multiset<T> V) {
			return false;
		}
		
		template<typename Search, typename T> bool _in(Search t, T V) { return t == V; }

	};
	template<typename T> InSearch<T> operator *(const T& data, const OperatorIn&) { return InSearch<T>(data); }
}
#define in *_In::OperatorIn{}*

int64_t random(int64_t const less, int64_t const more) {
	return rand() % (more - less) + less;
}

double_t random(double_t const less, double_t const more) {
	return less + (more - less) * ((double_t)(rand() % 0xff) / (double_t)0xff);
}





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


