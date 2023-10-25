#pragma once																					 
#include <iostream>	
#include <fstream>
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
#include <functional>		
#include <tuple>
																								 
#define _If_No_Class_T           (!std::is_class<T>::value || typeid(T) == typeid(std::string))  
#define _Temp_			         template<>														 
#define _Temp_T			         template<typename T>											 
#define _Temp_Args				 template<typename ...Args>										 
#define _Temp_T_N		         template<typename T, _ui64 N>									 
#define _Temp_T1_T2		         template<typename T1, typename T2>								 
#define _Temp_T_Args	         template<typename T, typename ...Args>							 
// Has0 ������ ����� ������� ����� ��������� ���� �� � ������ �������: void(T)(void)
// value: bool - ��������� ����������� ��� ���������� ���������� �������
// ������: Has0(test)      -> has_test<T>.value - ����� ������� void T::test();
#define Has0(name)				 template<typename T> class has0_##name## {															   \
								 static void detect(...);                                    										   \
								 template<typename U> static decltype(std::declval<U>().##name##()) detect(const U&);                  \
								 public:																							   \
								 static constexpr bool value = std::is_same<T, decltype(detect(std::declval<T>()))>::value;};
// Has1 ������ ����� ������� ����� ��������� ���� �� � ������ T ������� ������������ out: out(T)(void)
// value: bool - ��������� ����������� ��� ���������� ���������� �������
// ������: Has1(string, test)      -> has_test<T>.value - ����� ������� string T::test();
#define Has1(out, name)			 template<typename T> class has1_##name## {															   \
								 static void detect(...);                                                                              \
								 template<typename U> static decltype(std::declval<U>().##name##()) detect(const U&);                  \
								 public:																							   \
								 static constexpr bool value = std::is_same<out, decltype(detect(std::declval<T>()))>::value;};
// Has2 ������ ����� ������� ����� ��������� ���� �� � ������ T ������� ����������� inp � ������������ out: out(T)(inp)
// value: bool - ��������� ����������� ��� ���������� ���������� �������
// ������: Has2(_i32, func, string) -> has_func<T>.value - ����� ������� _i32 T::func(string);
#define Has2(out, name, inp)	 template<typename T> class has2_##name## {															   \
								 static inp detect(...);																			   \
								 template<typename U> static decltype(std::declval<U>().##name##(inp())) detect(const U&);             \
								 public:																							   \
								 static constexpr bool value = std::is_same<out, decltype(detect(std::declval<T>()))>::value;};											 

typedef bool              _bool  ;     //bool													 
								 																 									   															 
typedef __int8            _i8    ;     //char													 
typedef __int16           _i16   ;     //short													 
typedef __int32           _i32   ;     //int												 
typedef __int64           _i64   ;     //long long												 
typedef unsigned __int8   _ui8   ;     //unsigned char											 
typedef unsigned __int16  _ui16  ;     //unsigned short											 
typedef unsigned __int32  _ui32  ;     //unsigned int										 
typedef unsigned __int64  _ui64  ;     //unsigned long long										 
								 	   															 
typedef float             _f32   ;     //float										 
typedef double            _f64   ;     //double													 
typedef long double       _lf64  ;     //long double		

typedef signed char       _sc8   ;     //signed char
#if ((defined(_MSVC_LANG) && _MSVC_LANG > 201703L) || __cplusplus > 201703L)
typedef char8_t           _uc8   ;     //char8_t												 
#endif
typedef char16_t          _uc16  ;     //char16_t												 
typedef char32_t          _uc32  ;     //char32_t												 
typedef __wchar_t         _wc    ;     //__wchar_t												 

template <typename T>
struct has_output_operator {
	template <typename U>
	static auto test1(U* u) -> decltype(std::cout << std::declval<U>(), std::true_type{});

	template <typename U>
	static auto test2(U u) -> decltype(std::cout << u, std::true_type{});

	template <typename>
	static std::false_type test1(...);
	template <typename>
	static std::false_type test2(...);

	static constexpr bool value = decltype(test1<T>(nullptr))::value || decltype(test2<T>(T()))::value;
};





class __IBuffer {
	static std::ifstream* ifs; 
	static std::fstream* fs;
	static std::streambuf* sb;

	static enum OpenBy {
		Stream,
		FileName,
		IfStream,
		FStream,
		StreamBuf
	} open_by;
	
	static void _del() {
		if (open_by == FileName) {
			delete ifs;
			ifs = nullptr;
		}
		open_by = Stream;
	}

	_Temp_T static void _open(T* t) {
		if constexpr (std::is_same_v<T, std::ifstream>) { 
			open_by = IfStream;
			ifs = t;
			_Input_In.rdbuf(ifs->rdbuf());
		}
		if constexpr (std::is_same_v<T, std::fstream>) { 
			open_by = FStream;
			fs = t;
			_Input_In.rdbuf(fs->rdbuf());
		}
		if constexpr (std::is_same_v<T, std::streambuf>) {
			open_by = StreamBuf;
			_Input_In.rdbuf(t);
		}
	}
	static void __open(std::ifstream* t) {
		open_by = FileName;
		ifs = t;
		_Input_In.rdbuf(ifs->rdbuf());
	}

	static bool _is_open() {
		switch (open_by)
		{
		case __IBuffer::Stream: 
			return false;
		case __IBuffer::FileName: 
			return true;
		case __IBuffer::IfStream:

			return ifs->is_open();
			break;
		case __IBuffer::FStream: 
			return fs->is_open();
			break;
		case __IBuffer::StreamBuf: 
			return true;
		}
	}

protected:

	static std::istream _Input_In;

public:
	static void open(std::string FileName, std::ios_base::openmode Mode = std::ios_base::in, _i32 Prot = 64) {
		_del();
		__open(new std::ifstream(FileName, Mode, Prot));
	}
	static void open(std::wstring FileName, std::ios_base::openmode Mode = std::ios_base::in, _i32 Prot = 64) {
		_del();
		__open(new std::ifstream(FileName, Mode, Prot));
	}
	static void open(std::fstream& FileStream) {
		_del();
		_open(&FileStream);
	}
	static void open(std::ifstream& FileStream) {
		_del();
		_open(&FileStream);
	}
	static void open(std::streambuf* StreamBuf) {
		_del();
		_open(StreamBuf);
	}
	static void close() {
		_del();
		_Input_In.rdbuf(sb);
	}
	static bool eof() {
		return _Input_In.eof(); 
	}
	static bool is_open() {
		return _is_open();
	}
};
std::ifstream* __IBuffer::ifs{ nullptr };
std::fstream* __IBuffer::fs{ nullptr };
std::streambuf* __IBuffer::sb{ std::cin.rdbuf() };
__IBuffer::OpenBy __IBuffer::open_by{ __IBuffer::Stream };
std::istream __IBuffer::_Input_In{ std::cin.rdbuf() };





class __WIBuffer {
	static std::wifstream* ifs;
	static std::wfstream* fs;
	static std::wstreambuf* sb;

	static enum OpenBy {
		Stream,
		FileName,
		IfStream,
		FStream,
		StreamBuf
	} open_by;

	static void _del() {
		if (open_by == FileName) {
			delete ifs;
			ifs = nullptr;
		}
		open_by = Stream;
	}

	_Temp_T static void _open(T* t) {
		if constexpr (std::is_same_v<T, std::wifstream>) {
			open_by = IfStream;
			ifs = t;
			_wInput_In.rdbuf(ifs->rdbuf());
		}
		if constexpr (std::is_same_v<T, std::wfstream>) {
			open_by = FStream;
			fs = t;
			_wInput_In.rdbuf(fs->rdbuf());
		}
		if constexpr (std::is_same_v<T, std::wstreambuf>) {
			open_by = StreamBuf;
			_wInput_In.rdbuf(t);
		}
	}
	static void __open(std::wifstream* t) {
		open_by = FileName;
		ifs = t;
		_wInput_In.rdbuf(ifs->rdbuf());
	}
	static bool _is_open() {
		switch (open_by)
		{
		case __WIBuffer::Stream:
			return false;
		case __WIBuffer::FileName:
			return true;
		case __WIBuffer::IfStream:
			return ifs->is_open();
			break;
		case __WIBuffer::FStream:
			return fs->is_open();
			break;
		case __WIBuffer::StreamBuf:
			return true;
		}
	}


protected:

	static std::wistream _wInput_In;

public:
	static void open(std::string FileName, std::ios_base::openmode Mode = std::ios_base::in, _i32 Prot = 64) {
		_del();
		__open(new std::wifstream(FileName, Mode, Prot));
	}
	static void open(std::wstring FileName, std::ios_base::openmode Mode = std::ios_base::in, _i32 Prot = 64) {
		_del();
		__open(new std::wifstream(FileName, Mode, Prot));
	}
	static void open(std::wfstream& FileStream) {
		_del();
		_open(&FileStream);
	}
	static void open(std::wifstream& FileStream) {
		_del();
		_open(&FileStream);
	}
	static void open(std::wstreambuf* StreamBuf) {
		_del();
		_open(StreamBuf);
	}
	static void close() {
		_del();
		_wInput_In.rdbuf(sb);
	}
	static bool eof() {
		return _wInput_In.eof();
	}
	static bool is_open() {
		return _is_open();
	}
};
std::wifstream* __WIBuffer::ifs{ nullptr };
std::wfstream* __WIBuffer::fs{ nullptr };
std::wstreambuf* __WIBuffer::sb{ std::wcin.rdbuf() };
__WIBuffer::OpenBy __WIBuffer::open_by{ __WIBuffer::Stream };
std::wistream __WIBuffer::_wInput_In{ std::wcin.rdbuf() };





class __PBuffer {
	static std::ofstream* ifs;
	static std::fstream* fs;
	static std::streambuf* sb;

	static enum OpenBy {
		Stream,
		FileName,
		OfStream,
		FStream,
		StreamBuf
	} open_by;

	static void _del() {
		if (open_by == FileName) {
			delete ifs;
			ifs = nullptr;
		}
		open_by = Stream;
	}

	_Temp_T static void _open(T* t) {
		if constexpr (std::is_same_v<T, std::ofstream>) {
			open_by = OfStream;
			ifs = t;
			_Print_Out.rdbuf(ifs->rdbuf());
		}
		if constexpr (std::is_same_v<T, std::fstream>) {
			open_by = FStream;
			fs = t;
			_Print_Out.rdbuf(fs->rdbuf());
		}
		if constexpr (std::is_same_v<T, std::streambuf>) {
			open_by = StreamBuf;
			_Print_Out.rdbuf(t);
		}
	}
	static void __open(std::ofstream* t) {
		open_by = FileName;
		ifs = t;
		_Print_Out.rdbuf(ifs->rdbuf());
	}

	static bool _is_open() {
		switch (open_by)
		{
		case __PBuffer::Stream:
			return false;
		case __PBuffer::FileName:
			return true;
		case __PBuffer::OfStream:
			return ifs->is_open();
			break;
		case __PBuffer::FStream:
			return fs->is_open();
			break;
		case __PBuffer::StreamBuf:
			return true;
		}
	}

protected:

	static std::ostream _Print_Out;

public:
	static void open(std::string FileName, std::ios_base::openmode Mode = std::ios_base::out, _i32 Prot = 64) {
		_del();
		__open(new std::ofstream(FileName, Mode, Prot));
	}
	static void open(std::wstring FileName, std::ios_base::openmode Mode = std::ios_base::out, _i32 Prot = 64) {
		_del();
		__open(new std::ofstream(FileName, Mode, Prot));
	}
	static void open(std::fstream& FileStream) {
		_del();
		_open(&FileStream);
	}
	static void open(std::ofstream& FileStream) {
		_del();
		_open(&FileStream);
	}
	static void open(std::streambuf* StreamBuf) {
		_del();
		_open(StreamBuf);
	}
	static void close() {
		_del();
		_Print_Out.rdbuf(sb);
	}
	static bool eof() {
		return _Print_Out.eof();
	}
	static bool is_open() {
		return _is_open();
	}
};
std::ofstream* __PBuffer::ifs{nullptr};
std::fstream* __PBuffer::fs{nullptr};
std::streambuf* __PBuffer::sb{ std::cout.rdbuf() };
__PBuffer::OpenBy __PBuffer::open_by{ __PBuffer::Stream };
std::ostream __PBuffer::_Print_Out{ std::cout.rdbuf() };





class input : public __IBuffer {
	static _ui64 npos;
	_ui64 _Size{npos};

public:
	/// <param name="Text">: ���������, ������� ���������</param>
	/// <param name="Size">: ���� Size ���������� � ���������</param>
	input(std::string Text = "", _ui64 Size = npos) : _Size(Size) { std::cout << Text;}
	/// <param name="Size">: ���� Size ���������� � ���������</param>
	input(_ui64 Size) : _Size(Size) {  }
	
	static std::string getline () {
		std::string s;
		_i8 c = _Input_In.get();
		std::getline(_Input_In, s);
		if (c != '\n' && c != EOF) s = c + s;
		return s;
	}

	_Temp_T auto     operator +						  (T t) { T     v; _Input_In  >> v; return v + t;    }
	_Temp_T auto     operator -						  (T t) { T     v; _Input_In  >> v; return v - t;    }
	_Temp_T auto     operator ~						     () { T     v; _Input_In  >> v; return ~v;       }
	_Temp_T auto     operator !						     () { T     v; _Input_In  >> v; return !v;       }
	_Temp_T auto     operator ++					     () { T     v; _Input_In  >> v; return v++;      }
	_Temp_T auto     operator ++					    (T) { T     v; _Input_In  >> v; return ++v;      }
	_Temp_T auto     operator --					     () { T     v; _Input_In  >> v; return v--;      }
	_Temp_T auto     operator --					    (T) { T     v; _Input_In  >> v; return --v;      }
	_Temp_T auto     operator *						  (T t) { T     v; _Input_In  >> v; return v * t;    }
	_Temp_T auto     operator /						  (T t) { T     v; _Input_In  >> v; return v / t;    }
	_Temp_T auto     operator %						  (T t) { T     v; _Input_In  >> v; return v % t;    }
	_Temp_T auto     operator >>				   (_i64 t) { T     v; _Input_In  >> v; return v >> t;   }
	_Temp_T auto     operator <<				   (_i64 t) { T     v; _Input_In  >> v; return v << t;   }
	_Temp_T auto     operator <						  (T t) { T     v; _Input_In  >> v; return v < t;    }
	_Temp_T auto     operator >						  (T t) { T     v; _Input_In  >> v; return v > t;    }
	_Temp_T auto     operator <=					  (T t) { T     v; _Input_In  >> v; return v <= t;   }
	_Temp_T auto     operator >=					  (T t) { T     v; _Input_In  >> v; return v >= t;   }
	_Temp_T auto     operator ==					  (T t) { T     v; _Input_In  >> v; return v == t;   }
	_Temp_T auto     operator !=					  (T t) { T     v; _Input_In  >> v; return v != t;   }
	_Temp_T auto     operator &						  (T t) { T     v; _Input_In  >> v; return v & t;    }
	_Temp_T auto     operator ^						  (T t) { T     v; _Input_In  >> v; return v ^ t;    }
	_Temp_T auto     operator |						  (T t) { T     v; _Input_In  >> v; return v | t;    }
	_Temp_T auto     operator &&					  (T t) { T     v; _Input_In  >> v; return v && t;   }
	_Temp_T auto     operator ||					  (T t) { T     v; _Input_In  >> v; return v || t;   }	
	_Temp_T explicit operator T                          () { T     v; _Input_In  >> v; return v;        }
				     operator _bool						 () { _bool v; _Input_In  >> v; return v;        }
				     operator _i8						 () { _i8   v; _Input_In  >> v; return v;        }
				     operator _i16						 () { _i16  v; _Input_In  >> v; return v;        }
				     operator _i32						 () { _i32  v; _Input_In  >> v; return v;        }
				     operator _i64						 () { _i64  v; _Input_In  >> v; return v;        }
				     operator _ui8						 () { _ui8  v; _Input_In  >> v; return v;        }
				     operator _ui16						 () { _ui16 v; _Input_In  >> v; return v;        }
				     operator _ui32						 () { _ui32 v; _Input_In  >> v; return v;        }
				     operator _ui64						 () { _ui64 v; _Input_In  >> v; return v;        }
				     operator _f32				         () { _f32  v; _Input_In  >> v; return v;        }
				     operator _f64					     () { _f64  v; _Input_In  >> v; return v;        }
				     operator _lf64					     () { _lf64 v; _Input_In  >> v; return v;        }
				     operator _sc8                       () { _sc8  v; _Input_In  >> v; return v;        }
					 #if ((defined(_MSVC_LANG) && _MSVC_LANG > 201703L) || __cplusplus > 201703L)
					 operator _uc8						 () { _ui8  v; _Input_In  >> v; return (_uc8)v;  }
					 #endif
				     operator _uc16						 () { _ui16 v; _Input_In  >> v; return (_uc16)v; }
				     operator _uc32						 () { _ui32 v; _Input_In  >> v; return (_uc32)v; }
				     operator std::string                () {
		std::string v; _Input_In >> v;
		return v;
	}
	_Temp_T1_T2	     operator std::pair<T1, T2>          (){
		std::pair<T1, T2> v;
		v.first = *this; v.second = *this;
		return v;
	}
	_Temp_T1_T2	     operator std::map<T1, T2>           (){
		std::map<T1, T2> v;
		if (_Size == npos) {
			T1 t1 = *this; T2 t2 = *this;
			v.insert({ t1, t2 });
			return v;
		}
		for (_ui64 i = 0; i < _Size; i++) {
			T1 t1 = *this; T2 t2 = *this;
			v.insert({ t1, t2 });
		}
		return v;
	}
	_Temp_T1_T2	     operator std::unordered_map<T1, T2> (){
		std::unordered_map<T1, T2> v;
		if (_Size == npos) {
			T1 t1 = input(); T2 t2 = input();
			v.insert({ t1, t2 });
			return v;
		}
		for (_ui64 i = 0; i < _Size; i++) {
			T1 t1 = input(); T2 t2 = input();
			v.insert({ t1, t2 });
		}
		return v;
	}
	_Temp_T_N        operator std::array<T, N>           (){
		std::array<T, N> v;
		if (_Size >= N) for (_ui64 i = 0; i < N; i++) v[i] = input();
		else for (_ui64 i = 0; i < _Size; i++) v[i] = input();
		return v;
	}
	_Temp_T		     operator std::vector<T>             () {
		std::vector<T> v;
		if (_Size != npos) {
			for (_ui64 i = 0; i < _Size; i++) v.push_back(*this);
			return v;
		}
		if constexpr (_If_No_Class_T) {
			std::stringstream ss(getline());
			T t;
			while (ss >> t) v.push_back(t);
			return v;
		}
		v.push_back(*this);
		return v;
	}
	_Temp_T		     operator std::list<T>               (){
		std::list<T> v;
		if (_Size != npos) {
			for (_ui64 i = 0; i < _Size; i++) v.push_back(*this);
			return v;
		}
		if constexpr (_If_No_Class_T) {
			std::stringstream ss(getline());
			T t;
			while (ss >> t) v.push_back(t);
			return v;
		}
		v.push_back(*this);
		return v;
	}
	_Temp_T		     operator std::forward_list<T>       (){
		std::forward_list<T> v;
		if (_Size != npos) {
			for (_ui64 i = 0; i < _Size; i++) v.push_front(*this);
			return v;
		}
		if constexpr (_If_No_Class_T) {
			std::stringstream ss(getline());
			T t;
			while (ss >> t) v.push_front(t);
			return v;
		}
		v.push_front(*this);
		return v;
	}
	_Temp_T		     operator std::set<T>                (){
		std::set<T> v;
		if (_Size != npos) {
			for (_ui64 i = 0; i < _Size; i++) {
				T t = *this;
				v.insert(t);
			}
			return v;
		}
		if constexpr (_If_No_Class_T) {
			std::stringstream ss(getline());
			T t;
			while (ss >> t) v.insert(t);
			return v;
		}
		T t = *this;
		v.insert(t);
		return v;
	}
	_Temp_T		     operator std::multiset<T>           (){
		std::multiset<T> v;
		if (_Size != npos) {
			for (_ui64 i = 0; i < _Size; i++) {
				T t = *this;
				v.insert(t);
			}
			return v;
		}
		if constexpr (_If_No_Class_T) {
			std::stringstream ss(getline());
			T t;
			while (ss >> t) v.insert(t);
			return v;
		}
		T t = *this;
		v.insert(t);
		return v;
	}
	_Temp_T		     operator std::unordered_set<T>      (){
		std::unordered_set<T> v;
		if (_Size != npos) {
			for (_ui64 i = 0; i < _Size; i++) {
				T t = *this;
				v.insert(t);
			}
			return v;
		}
		if constexpr (_If_No_Class_T) {
			std::stringstream ss(getline());
			T t;
			while (ss >> t) v.insert(t);
			return v;
		}
		T t = *this;
		v.insert(t);
		return v;
	}
	_Temp_T		     operator std::unordered_multiset<T> (){
		std::unordered_multiset<T> v;
		if (_Size != npos) {
			for (_ui64 i = 0; i < _Size; i++) {
				T t = *this;
				v.insert(t);
			}
			return v;
		}
		if constexpr (_If_No_Class_T) {
			std::stringstream ss(getline());
			T t;
			while (ss >> t) v.insert(t);
			return v;
		}
		T t = *this;
		v.insert(t);
		return v;
    }
	_Temp_T		     operator std::queue<T>              (){
		std::queue<T> v;
		if (_Size != npos) {
			for (_ui64 i = 0; i < _Size; i++) v.push(*this);
			return v;
		}
		if constexpr (_If_No_Class_T) {
			std::stringstream ss(getline());
			T t;
			while (ss >> t) v.push(t);
			return v;
		}
		v.push(*this);
		return v;
	}
	_Temp_T		     operator std::priority_queue<T>     (){
		std::priority_queue<T> v;
		if (_Size != npos) {
			for (_ui64 i = 0; i < _Size; i++) v.push(*this);
			return v;
		}
		if constexpr (_If_No_Class_T) {
			std::stringstream ss(getline());
			T t;
			while (ss >> t) v.push(t);
			return v;
		}
		v.push(*this);
		return v;
	}
	_Temp_T		     operator std::deque<T>              () {
		std::deque<T> v;
		if (_Size != npos) {
			for (_ui64 i = 0; i < _Size; i++) v.push_back(*this);
			return v;
		}
		if constexpr (_If_No_Class_T) {
			std::stringstream ss(getline());
			T t;
			while (ss >> t) v.push_back(t);
			return v;
		}
		v.push_back(*this);
		return v;
	}
	_Temp_T		     operator std::stack<T>              (){
		std::stack<T> v;
		if (_Size != npos) {
			for (_ui64 i = 0; i < _Size; i++) v.push(*this);
			return v;
		}
		if constexpr (_If_No_Class_T) {
			std::stringstream ss(getline());
			T t;
			while (ss >> t) v.push(t);
			return v;
		}
		v.push(*this);
		return v;
	}
};
_ui64 input::npos{ (_ui64)-1 };





class winput : public __WIBuffer {
	static _ui64 npos;
	_ui64 _Size{ npos };

public:
	/// <param name="Text">: ���������, ������� ���������</param>
	/// <param name="Size">: ���� Size ���������� � ���������</param>
	winput(std::string Text = "", _ui64 Size = npos) : _Size(Size) { std::cout << Text; }
	/// <param name="Size">: ���� Size ���������� � ���������</param>
	winput(_ui64 Size) : _Size(Size) {  }

	static std::wstring getline () {
		std::wstring s;
		_wc c = _wInput_In.get();
		std::getline(_wInput_In, s);
		if (c != '\n' && c != EOF) s = c + s;
		return s;
	}

	_Temp_T auto     operator +						  (T t) { T     v; _wInput_In >> v; return v + t; }
	_Temp_T auto     operator -						  (T t) { T     v; _wInput_In >> v; return v - t; }
	_Temp_T auto     operator ~						     () { T     v; _wInput_In >> v; return ~v; }
	_Temp_T auto     operator !						     () { T     v; _wInput_In >> v; return !v; }
	_Temp_T auto     operator ++					     () { T     v; _wInput_In >> v; return v++; }
	_Temp_T auto     operator ++					    (T) { T     v; _wInput_In >> v; return ++v; }
	_Temp_T auto     operator --					     () { T     v; _wInput_In >> v; return v--; }
	_Temp_T auto     operator --					    (T) { T     v; _wInput_In >> v; return --v; }
	_Temp_T auto     operator *						  (T t) { T     v; _wInput_In >> v; return v * t; }
	_Temp_T auto     operator /						  (T t) { T     v; _wInput_In >> v; return v / t; }
	_Temp_T auto     operator %						  (T t) { T     v; _wInput_In >> v; return v % t; }
	_Temp_T auto     operator >>				   (_i64 t) { T     v; _wInput_In >> v; return v >> t; }
	_Temp_T auto     operator <<				   (_i64 t) { T     v; _wInput_In >> v; return v << t; }
	_Temp_T auto     operator <						  (T t) { T     v; _wInput_In >> v; return v < t; }
	_Temp_T auto     operator >						  (T t) { T     v; _wInput_In >> v; return v > t; }
	_Temp_T auto     operator <=					  (T t) { T     v; _wInput_In >> v; return v <= t; }
	_Temp_T auto     operator >=					  (T t) { T     v; _wInput_In >> v; return v >= t; }
	_Temp_T auto     operator ==					  (T t) { T     v; _wInput_In >> v; return v == t; }
	_Temp_T auto     operator !=					  (T t) { T     v; _wInput_In >> v; return v != t; }
	_Temp_T auto     operator &						  (T t) { T     v; _wInput_In >> v; return v & t; }
	_Temp_T auto     operator ^						  (T t) { T     v; _wInput_In >> v; return v ^ t; }
	_Temp_T auto     operator |						  (T t) { T     v; _wInput_In >> v; return v | t; }
	_Temp_T auto     operator &&					  (T t) { T     v; _wInput_In >> v; return v && t; }
	_Temp_T auto     operator ||					  (T t) { T     v; _wInput_In >> v; return v || t; }
	_Temp_T explicit operator T                          () { T     v; _wInput_In >> v; return v; }
	                 operator _bool						 () { _bool v; _wInput_In >> v; return v; }
	                 operator _i16						 () { _i16  v; _wInput_In >> v; return v; }
	                 operator _i32						 () { _i32  v; _wInput_In >> v; return v; }
	                 operator _i64						 () { _i64  v; _wInput_In >> v; return v; }
	                 operator _ui16						 () { _ui16 v; _wInput_In >> v; return v; }
	                 operator _ui32						 () { _ui32 v; _wInput_In >> v; return v; }
	                 operator _ui64						 () { _ui64 v; _wInput_In >> v; return v; }
	                 operator _f32				         () { _f32  v; _wInput_In >> v; return v; }
	                 operator _f64					     () { _f64  v; _wInput_In >> v; return v; }
	                 operator _lf64					     () { _lf64 v; _wInput_In >> v; return v; }
	                 operator _uc16						 () { _ui16 v; _wInput_In >> v; return (_uc16)v; }
	                 operator _uc32						 () { _ui32 v; _wInput_In >> v; return (_uc32)v; }
	                 operator _wc						 () { _wc   v; _wInput_In >> v; return v; }
	                 operator std::wstring               () {
		std::wstring v; _wInput_In >> v;
		return v;
	}
	_Temp_T1_T2	     operator std::pair<T1, T2>() {
		std::pair<T1, T2> v;
		v.first = *this; v.second = *this;
		return v;
	}
	_Temp_T1_T2	     operator std::map<T1, T2>() {
		std::map<T1, T2> v;
		if (_Size == npos) {
			T1 t1 = *this; T2 t2 = *this;
			v.insert({ t1, t2 });
			return v;
		}
		for (_ui64 i = 0; i < _Size; i++) {
			T1 t1 = *this; T2 t2 = *this;
			v.insert({ t1, t2 });
		}
		return v;
	}
	_Temp_T1_T2	     operator std::unordered_map<T1, T2>() {
		std::unordered_map<T1, T2> v;
		if (_Size == npos) {
			T1 t1 = input(); T2 t2 = input();
			v.insert({ t1, t2 });
			return v;
		}
		for (_ui64 i = 0; i < _Size; i++) {
			T1 t1 = input(); T2 t2 = input();
			v.insert({ t1, t2 });
		}
		return v;
	}
	_Temp_T_N        operator std::array<T, N>() {
		std::array<T, N> v;
		if (_Size >= N) for (_ui64 i = 0; i < N; i++) v[i] = input();
		else for (_ui64 i = 0; i < _Size; i++) v[i] = input();
		return v;
	}
	_Temp_T		     operator std::vector<T>() {
		std::vector<T> v;
		if (_Size != npos) {
			for (_ui64 i = 0; i < _Size; i++) v.push_back(*this);
			return v;
		}
		if constexpr (_If_No_Class_T) {
			std::stringstream ss(getline());
			T t;
			while (ss >> t) v.push_back(t);
			return v;
		}
		v.push_back(*this);
		return v;
	}
	_Temp_T		     operator std::list<T>() {
		std::list<T> v;
		if (_Size != npos) {
			for (_ui64 i = 0; i < _Size; i++) v.push_back(*this);
			return v;
		}
		if constexpr (_If_No_Class_T) {
			std::stringstream ss(getline());
			T t;
			while (ss >> t) v.push_back(t);
			return v;
		}
		v.push_back(*this);
		return v;
	}
	_Temp_T		     operator std::forward_list<T>() {
		std::forward_list<T> v;
		if (_Size != npos) {
			for (_ui64 i = 0; i < _Size; i++) v.push_front(*this);
			return v;
		}
		if constexpr (_If_No_Class_T) {
			std::stringstream ss(getline());
			T t;
			while (ss >> t) v.push_front(t);
			return v;
		}
		v.push_front(*this);
		return v;
	}
	_Temp_T		     operator std::set<T>() {
		std::set<T> v;
		if (_Size != npos) {
			for (_ui64 i = 0; i < _Size; i++) {
				T t = *this;
				v.insert(t);
			}
			return v;
		}
		if constexpr (_If_No_Class_T) {
			std::stringstream ss(getline());
			T t;
			while (ss >> t) v.insert(t);
			return v;
		}
		T t = *this;
		v.insert(t);
		return v;
	}
	_Temp_T		     operator std::multiset<T>() {
		std::multiset<T> v;
		if (_Size != npos) {
			for (_ui64 i = 0; i < _Size; i++) {
				T t = *this;
				v.insert(t);
			}
			return v;
		}
		if constexpr (_If_No_Class_T) {
			std::stringstream ss(getline());
			T t;
			while (ss >> t) v.insert(t);
			return v;
		}
		T t = *this;
		v.insert(t);
		return v;
	}
	_Temp_T		     operator std::unordered_set<T>() {
		std::unordered_set<T> v;
		if (_Size != npos) {
			for (_ui64 i = 0; i < _Size; i++) {
				T t = *this;
				v.insert(t);
			}
			return v;
		}
		if constexpr (_If_No_Class_T) {
			std::stringstream ss(getline());
			T t;
			while (ss >> t) v.insert(t);
			return v;
		}
		T t = *this;
		v.insert(t);
		return v;
	}
	_Temp_T		     operator std::unordered_multiset<T>() {
		std::unordered_multiset<T> v;
		if (_Size != npos) {
			for (_ui64 i = 0; i < _Size; i++) {
				T t = *this;
				v.insert(t);
			}
			return v;
		}
		if constexpr (_If_No_Class_T) {
			std::stringstream ss(getline());
			T t;
			while (ss >> t) v.insert(t);
			return v;
		}
		T t = *this;
		v.insert(t);
		return v;
	}
	_Temp_T		     operator std::queue<T>() {
		std::queue<T> v;
		if (_Size != npos) {
			for (_ui64 i = 0; i < _Size; i++) v.push(*this);
			return v;
		}
		if constexpr (_If_No_Class_T) {
			std::stringstream ss(getline());
			T t;
			while (ss >> t) v.push(t);
			return v;
		}
		v.push(*this);
		return v;
	}
	_Temp_T		     operator std::priority_queue<T>() {
		std::priority_queue<T> v;
		if (_Size != npos) {
			for (_ui64 i = 0; i < _Size; i++) v.push(*this);
			return v;
		}
		if constexpr (_If_No_Class_T) {
			std::stringstream ss(getline());
			T t;
			while (ss >> t) v.push(t);
			return v;
		}
		v.push(*this);
		return v;
	}
	_Temp_T		     operator std::deque<T>() {
		std::deque<T> v;
		if (_Size != npos) {
			for (_ui64 i = 0; i < _Size; i++) v.push_back(*this);
			return v;
		}
		if constexpr (_If_No_Class_T) {
			std::stringstream ss(getline());
			T t;
			while (ss >> t) v.push_back(t);
			return v;
		}
		v.push_back(*this);
		return v;
	}
	_Temp_T		     operator std::stack<T>() {
		std::stack<T> v;
		if (_Size != npos) {
			for (_ui64 i = 0; i < _Size; i++) v.push(*this);
			return v;
		}
		if constexpr (_If_No_Class_T) {
			std::stringstream ss(getline());
			T t;
			while (ss >> t) v.push(t);
			return v;
		}
		v.push(*this);
		return v;
	}
};
_ui64 winput::npos{ (_ui64)-1 };




struct _cmd {
	_cmd(std::string what, std::string on_what) :what(what), on_what(on_what) {}
	_cmd(std::string what, char on_what) :what(what) { this->on_what += on_what; }
	std::string what{}, on_what{};
};





class _Print : public __PBuffer {
public:
	~_Print() { if(imsomewrite) _Print_Out << end; }
	_Temp_Args friend _Print& print(Args...);
	
private:
	bool imsomewrite{ false };
	_Print() = default;
	_Temp_Args _Print(Args... args) {
		imsomewrite = true;
		__Test(args...);
		__Print(args...);
	} 
	Has1(std::string, ToString);
	
	_Temp_Args void __Print(Args... t) {
		now_pos = 0;
		_print(t...);
	}
	_Temp_Args void __Test(Args... t) {
		need_separator.assign(sizeof...(Args), '0');
		now_pos = 0;
		_test(t...);
		need_separator.back() = '0';
	}

	std::string end{ '\n' };
	std::string separator{" "};
	std::string separator_in_containers{", "};
	std::string separator_in_map{": "};

	std::string brakets_in_array{"[]"};
	std::string brakets_in_tuple{"()"};
	std::string brakets_in_map{"{}"};

	_Temp_T		 void _print(T t) {
		if constexpr (has_output_operator<T>::value)
			_Print_Out << t;
		else if constexpr (has1_ToString<T>::value) 
			_Print_Out << t.ToString();
		else 
			_Print_Out << typeid(T).name();
	}
	_Temp_		 void _print(input t) {
		_Print_Out << (std::string)t;
	}
	_Temp_		 void _print(_cmd t) {}
	_Temp_		 void _print(bool t) {
		_Print_Out << std::boolalpha << t;
	}
	_Temp_T1_T2	 void _print(std::pair<T1, T2> t) {
		_Print_Out << brakets_in_array[0];
		_print(t.first);
		_Print_Out << separator_in_containers;
		_print(t.second);
		_Print_Out << brakets_in_array[1];
	}
	_Temp_T1_T2	 void _print(std::map<T1, T2> v) {
		_Print_Out << brakets_in_map[0];
		_ui64 cnt{ 0 };
		for (auto i : v) {
			_print(i.first);
			_Print_Out << separator_in_map;
			_print(i.second);
			if (cnt + 1 < v.size()) {
				_Print_Out << separator_in_containers;
			}
			cnt++;
		}
		_Print_Out << brakets_in_map[1];
	}
	_Temp_T1_T2	 void _print(std::unordered_map<T1, T2> v) {
		_Print_Out << brakets_in_map[0];
		_ui64 cnt{ 0 };
		for (auto i : v) {
			_print(i.first);
			_Print_Out << separator_in_map;
			_print(i.second);
			if (cnt + 1 < v.size()) {
				_Print_Out << separator_in_containers;
			}
			cnt++;
		}
		_Print_Out << brakets_in_map[1];
	}
	_Temp_T_N	 void _print(std::array<T, N> v) {
		_Print_Out << brakets_in_array[0];
		_ui64 cnt{ 0 };
		for (auto i : v) {
			_print(i);
			if (cnt + 1 < v.size()) {
				_Print_Out << separator_in_containers;
			}
			cnt++;
		}
		_Print_Out << brakets_in_array[1];
	}
	_Temp_T		 void _print(std::vector<T> v) {
		_Print_Out << brakets_in_array[0];
		_ui64 cnt{ 0 };
		for (auto i : v) {
			_print(i);
			if (cnt + 1 < v.size()) {
				_Print_Out << separator_in_containers;
			}
			cnt++;
		}
		_Print_Out << brakets_in_array[1];
	}
	_Temp_T		 void _print(std::list<T> v) {
		_Print_Out << brakets_in_array[0];
		_ui64 cnt{ 0 };
		for (auto i : v) {
			_print(i);
			if (cnt + 1 < v.size()) {
				_Print_Out << separator_in_containers;
			}
			cnt++;
		}
		_Print_Out << brakets_in_array[1];
	}
	_Temp_T		 void _print(std::forward_list<T> v) {
		_Print_Out << brakets_in_array[0];
		_ui64 cnt{ 0 };
		for (auto i : v) {
			_print(i);
			if (cnt + 1 < v.size()) {
				_Print_Out << separator_in_containers;
			}
			cnt++;
		}
		_Print_Out << brakets_in_array[1];
	}
	_Temp_T		 void _print(std::set<T> v) {
		_Print_Out << brakets_in_array[0];
		_ui64 cnt{ 0 };
		for (auto i : v) {
			_print(i);
			if (cnt + 1 < v.size()) {
				_Print_Out << separator_in_containers;
			}
			cnt++;
		}
		_Print_Out << brakets_in_array[1];
	}
	_Temp_T		 void _print(std::multiset<T> v) {
		_Print_Out << brakets_in_array[0];
		_ui64 cnt{ 0 };
		for (auto i : v) {
			_print(i);
			if (cnt + 1 < v.size()) {
				_Print_Out << separator_in_containers;
			}
			cnt++;
		}
		_Print_Out << brakets_in_array[1];
	}
	_Temp_T		 void _print(std::unordered_set<T> v) {
		_Print_Out << brakets_in_array[0];
		_ui64 cnt{ 0 };
		for (auto i : v) {
			_print(i);
			if (cnt + 1 < v.size()) {
				_Print_Out << separator_in_containers;
			}
			cnt++;
		}
		_Print_Out << brakets_in_array[1];
	}
	_Temp_T		 void _print(std::unordered_multiset<T> v) {
		_Print_Out << brakets_in_array[0];
		_ui64 cnt{ 0 };
		for (auto i : v) {
			_print(i);
			if (cnt + 1 < v.size()) {
				_Print_Out << separator_in_containers;
			}
			cnt++;
		}
		_Print_Out << brakets_in_array[1];
	}
	_Temp_T		 void _print(std::queue<T> v) {
		_Print_Out << brakets_in_array[0];
		auto vnew = v;
		while (true) {
			_print(vnew.front());
			vnew.pop();
			if (vnew.empty()) break;
			_Print_Out << separator_in_containers;
		}
		_Print_Out << brakets_in_array[1];
	}
	_Temp_T		 void _print(std::priority_queue<T> v) {
		_Print_Out << brakets_in_array[0];
		auto vnew = v;
		while (true) {
			_print(vnew.front());
			vnew.pop();
			if (vnew.empty()) break;
			_Print_Out << separator_in_containers;
		}
		_Print_Out << brakets_in_array[1];
	}
	_Temp_T		 void _print(std::deque<T> v) {
		_Print_Out << brakets_in_array[0];
		_ui64 cnt{ 0 };
		for (auto i : v) {
			_print(i);
			if (cnt + 1 < v.size()) {
				_Print_Out << separator_in_containers;
			}
			cnt++;
		}
		_Print_Out << brakets_in_array[1];
	}
	_Temp_T		 void _print(std::stack<T> v) {
		_Print_Out << brakets_in_array[0];
		auto vnew = v;
		while (true) {
			_print(vnew.front());
			vnew.pop();
			if (vnew.empty()) break;
			_Print_Out << separator_in_containers;
		}
		_Print_Out << brakets_in_array[1];
	}
	_Temp_T_Args void _print(T v, Args... w) {
		if (need_separator[now_pos] == '0') {
			now_pos++;
			_print(w...);
			return;
		}
		now_pos++;
		_print(v);
		if(--useful_amount) _Print_Out << separator;
		_print(w...);
	}

	_Temp_T		 void _test(T t) {
		need_separator[now_pos] = '1';
		now_pos++;
		useful_amount++;
	}
	_Temp_		 void _test(_cmd t) {
		__cmd[t.what](t.on_what);
		now_pos++;
	}
	_Temp_T_Args void _test(T t, Args... args) {
		_test(t); _test(args...);
	}

	std::map<std::string, std::function<void(std::string)>> __cmd{ 
		{"end", [&](std::string s) {end = s; }},
		{"sep", [&](std::string s) {separator = s; }}
	};
	std::string need_separator;
	_ui64 now_pos{ 0 };
	_i32 useful_amount{ 0 };
};
_Temp_Args _Print& print(Args... args) {
	_Print st(args...);
	return st;
}





/// <summary>
/// Not working
/// </summary>
//namespace _In {
//	class OperatorIn {};
//	template<typename Tin>
//	struct InSearch {
//		const Tin& m_in;
//		InSearch(const Tin& val) : m_in(val) {};
//		template<typename T> bool operator *(T& what) { return _in(m_in, what); }
//	private:
//		template<typename T1, typename T2> bool _in(std::pair<T1, T2> p1, std::pair<T1, T2> p2) {
//			return (p1.first == p2.first) && (p1.second == p2.second);
//		}
//		
//		template<typename Search, typename T1, typename T2> bool _in(Search t, std::pair<T1, T2> V) {
//			if constexpr (typeid(Search) == typeid(T1)) return _in(t, V.first);
//			if constexpr (typeid(Search) == typeid(T2)) return _in(t, V.second);
//			return false;
//		}
//		
//		template<typename Search, typename T1, typename T2> bool _in(Search t, std::map<T1, T2> V) {
//			return false;
//		}
//		
//		template<typename Search, typename T1, typename T2> bool _in(Search t, std::unordered_map<T1, T2> V) {
//			return false;
//		}
//		
//		template<typename T, size_t N1, size_t N2> bool _in(std::array<T, N1> V1, std::array<T, N2> V2) {
//			if (N1 != N2) return false;
//			bool opt = true;
//			for (size_t i = 0; i < N1; i++) {
//				opt &= _in(V1[i], V2[i]);
//				if (!opt) return false;
//			}
//			return opt;
//		}
//		template<typename Search, typename T, size_t N> bool _in(Search t, std::array<T, N> V) {
//			bool opt = false;
//			for (size_t i = 0; i < N; i++) {
//				opt |= _in(t, V[i]);
//				if (opt) return true;
//			}
//			return opt;
//		}
//	
//		template<typename T> bool _in(std::vector<T> V1, std::vector<T> V2) {
//			if (V1.size() != V2.size()) return false;
//			bool opt = true;
//			for (size_t i = 0; i < V1.size(); i++) {
//				opt &= _in(V1[i], V2[i]);
//				if (!opt) return false;
//			}
//			return opt;
//		}
//		template<typename Search, typename T> bool _in(Search t, std::vector<T> V) {
//			bool opt = false;
//			for (size_t i = 0; i < V.size(); i++) {
//				opt |= _in(t, V[i]);
//				if (opt) return true;
//			}
//			return opt;
//		}
//
//		template<typename Search, typename T> bool _in(Search t, std::list<T> V) {
//			return false;
//		}
//		
//		template<typename Search, typename T> bool _in(Search t, std::forward_list<T> V) {
//			return false;
//		}
//		
//		template<typename Search, typename T> bool _in(Search t, std::set<T> V) {
//			return false;
//		}
//		
//		template<typename Search, typename T> bool _in(Search t, std::multiset<T> V) {
//			return false;
//		}
//		
//		template<typename Search, typename T> bool _in(Search t, std::unordered_set<T> V) {
//			return false;
//		}
//		
//		template<typename Search, typename T> bool _in(Search t, std::unordered_multiset<T> V) {
//			return false;
//		}
//		
//		template<typename Search, typename T> bool _in(Search t, T V) { return t == V; }
//
//	};
//	template<typename T> InSearch<T> operator *(const T& data, const OperatorIn&) { return InSearch<T>(data); }
//}
//#define in *_In::OperatorIn{}*

int64_t random(int64_t const less, int64_t const more) {
	return rand() % (more - less) + less;
}

double_t random(double_t const less, double_t const more) {
	return less + (more - less) * ((double_t)(rand() % 0xff) / (double_t)0xff);
}