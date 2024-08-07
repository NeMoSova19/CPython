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

#ifndef _MSVC_LANG
#define _MSVC_LANG 199711L
#endif // !_MSVC_LANG

#define _Version_CPP_17			 (_MSVC_LANG > 201703L || __cplusplus > 201703L)
#define _If_No_Class_T           (!std::is_class<T>::value || typeid(T) == typeid(std::string))  
#define _Temp_			         template<>														 
#define _Temp_T			         template<typename T>											 
#define _Temp_Args				 template<typename ...Args>										 
#define _Temp_T_N		         template<typename T, _ui64 N>									 
#define _Temp_T1_T2		         template<typename T1, typename T2>								 
#define _Temp_T_Args	         template<typename T, typename ...Args>		

// �������� �� ����������� �������� � stringstream
template<typename T>
concept Streamable = requires(T t, std::stringstream ss) {
	ss << t;
};

// �������� �� ������
template<typename T>
concept Iterable = requires(T t) {
	std::begin(t);
	std::end(t);
};

// �������� �� �������
template<typename T>
concept MapLike = requires(T t) {
	typename T::key_type;
	typename T::mapped_type;
	std::begin(t);
	std::end(t);
};

// �������� �� set, queue, ...
template<typename T>
concept HasContainer = requires(T t) {
	typename T::container_type;
};

// �������� �� pair
template<typename T>
concept IsPair = requires(T t) {
	t.first;
	t.second;
};

#if (_Version_CPP_17)
typedef bool              _bool;     //bool													 

typedef __int8            _i8;     //char													 
typedef __int16           _i16;     //short													 
typedef __int32           _i32;     //int												 
typedef __int64           _i64;     //long long												 
typedef unsigned __int8   _ui8;     //unsigned char											 
typedef unsigned __int16  _ui16;     //unsigned short											 
typedef unsigned __int32  _ui32;     //unsigned int										 
typedef unsigned __int64  _ui64;     //unsigned long long										 

typedef float             _f32;     //float										 
typedef double            _f64;     //double													 
typedef long double       _lf64;     //long double		

typedef signed char       _sc8;     //signed char
typedef char8_t           _uc8;     //char8_t												 
typedef char16_t          _uc16;     //char16_t												 
typedef char32_t          _uc32;     //char32_t												 
typedef __wchar_t         _wc;     //__wchar_t												 
#else
typedef bool              _bool;     //bool													 

typedef __int8            _i8;     //char													 
typedef __int16           _i16;     //short													 
typedef __int32           _i32;     //int												 
typedef __int64           _i64;     //long long												 
typedef unsigned __int8   _ui8;     //unsigned char											 
typedef unsigned __int16  _ui16;     //unsigned short											 
typedef unsigned __int32  _ui32;     //unsigned int										 
typedef unsigned __int64  _ui64;     //unsigned long long										 

typedef float             _f32;     //float										 
typedef double            _f64;     //double													 
typedef long double       _lf64;     //long double		

typedef signed char       _sc8;     //signed char											 
typedef char16_t          _uc16;     //char16_t												 
typedef char32_t          _uc32;     //char32_t												 
typedef __wchar_t         _wc;     //__wchar_t												 
#endif


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

	static std::ifstream*       ifs; 
	static std::fstream*        fs;
	static std::streambuf*      sb;
	static enum OpenBy {
		Stream,
		FileName,
		IfStream,
		FStream,
		StreamBuf
	} open_by;
	
	_Temp_T static void _open    (T* t) {
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
	        static void __open   (std::ifstream* t) {
		open_by = FileName;
		ifs = t;
		_Input_In.rdbuf(ifs->rdbuf());
	}
	        static bool _is_open () {
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
	        static void _del     () {
		if (open_by == FileName) {
			delete ifs;
			ifs = nullptr;
		}
		open_by = Stream;
	}

protected:

	static std::istream _Input_In;

public:

	static std::streambuf* rdbuf   () {
		return _Input_In.rdbuf();
	}
	static std::streambuf* rdbuf   (std::streambuf* StreamBuf) {
		_del();
		_open(StreamBuf);
		return _Input_In.rdbuf();
	}
	static void            open    (std::string FileName, std::ios_base::openmode Mode = std::ios_base::in, _i32 Prot = 64) {
		_del();
		__open(new std::ifstream(FileName, Mode, Prot));
	}
	static void            open    (std::wstring FileName, std::ios_base::openmode Mode = std::ios_base::in, _i32 Prot = 64) {
		_del();
		__open(new std::ifstream(FileName, Mode, Prot));
	}
	static void            open    (std::fstream& FileStream) {
		_del();
		_open(&FileStream);
	}
	static void            open    (std::ifstream& FileStream) {
		_del();
		_open(&FileStream);
	}
	static void            open    (std::streambuf* StreamBuf) {
		_del();
		_open(StreamBuf);
	}
	static void            close   () {
		_del();
		_Input_In.rdbuf(sb);
	}
	static bool            eof     () {
		return _Input_In.eof(); 
	}
	static bool            is_open () {
		return _is_open();
	}

};
__IBuffer::OpenBy __IBuffer::open_by   { __IBuffer::Stream };
std::ifstream*    __IBuffer::ifs       { nullptr };
std::fstream*     __IBuffer::fs        { nullptr };
std::streambuf*   __IBuffer::sb        { std::cin.rdbuf() };
std::istream      __IBuffer::_Input_In { std::cin.rdbuf() };





class __wIBuffer {
	static std::wifstream*      ifs;
	static std::wfstream*       fs;
	static std::wstreambuf*     sb;
	static enum OpenBy {
		Stream,
		FileName,
		IfStream,
		FStream,
		StreamBuf
	} open_by;

	_Temp_T static void _open    (T* t) {
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
	        static void __open   (std::wifstream* t) {
		open_by = FileName;
		ifs = t;
		_wInput_In.rdbuf(ifs->rdbuf());
	}
	        static bool _is_open () {
		switch (open_by)
		{
		case __wIBuffer::Stream:
			return false;
		case __wIBuffer::FileName:
			return true;
		case __wIBuffer::IfStream:
			return ifs->is_open();
			break;
		case __wIBuffer::FStream:
			return fs->is_open();
			break;
		case __wIBuffer::StreamBuf:
			return true;
		}
	}
	        static void _del     () {
		if (open_by == FileName) {
			delete ifs;
			ifs = nullptr;
		}
		open_by = Stream;
	}

protected:

	static std::wistream _wInput_In;

public:

	static std::wstreambuf* rdbuf   () {
		return _wInput_In.rdbuf();
	}
	static std::wstreambuf* rdbuf   (std::wstreambuf* StreamBuf) {
		_del();
		_open(StreamBuf);
		return _wInput_In.rdbuf();
	}
	static void             open    (std::string FileName, std::ios_base::openmode Mode = std::ios_base::in, _i32 Prot = 64) {
		_del();
		__open(new std::wifstream(FileName, Mode, Prot));
	}
	static void             open    (std::wstring FileName, std::ios_base::openmode Mode = std::ios_base::in, _i32 Prot = 64) {
		_del();
		__open(new std::wifstream(FileName, Mode, Prot));
	}
	static void             open    (std::wfstream& FileStream) {
		_del();
		_open(&FileStream);
	}
	static void             open    (std::wifstream& FileStream) {
		_del();
		_open(&FileStream);
	}
	static void             open    (std::wstreambuf* StreamBuf) {
		_del();
		_open(StreamBuf);
	}
	static void             close   () {
		_del();
		_wInput_In.rdbuf(sb);
	}
	static bool             eof     () {
		return _wInput_In.eof();
	}
	static bool             is_open () {
		return _is_open();
	}

};
__wIBuffer::OpenBy __wIBuffer::open_by    { __wIBuffer::Stream };
std::wifstream*    __wIBuffer::ifs        { nullptr };
std::wfstream*     __wIBuffer::fs         { nullptr };
std::wstreambuf*   __wIBuffer::sb         { std::wcin.rdbuf() };
std::wistream      __wIBuffer::_wInput_In { std::wcin.rdbuf() };





class __PBuffer {
	static std::ofstream*       ifs;
	static std::fstream*        fs;
	static std::streambuf*      sb;
	static enum OpenBy {
		Stream,
		FileName,
		OfStream,
		FStream,
		StreamBuf
	} open_by;


	_Temp_T static void _open    (T* t) {
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
	        static void __open   (std::ofstream* t) {
		open_by = FileName;
		ifs = t;
		_Print_Out.rdbuf(ifs->rdbuf());
	}
	        static bool _is_open () {
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
	        static void _del     () {
		if (open_by == FileName) {
			delete ifs;
			ifs = nullptr;
		}
		open_by = Stream;
	}

protected:

	static std::ostream _Print_Out;

public:

	static std::streambuf* rdbuf   () {
		return _Print_Out.rdbuf();
	}
	static std::streambuf* rdbuf   (std::streambuf* StreamBuf) {
		_del();
		_open(StreamBuf);
		return _Print_Out.rdbuf();
	}
	static void            open    (std::string FileName, std::ios_base::openmode Mode = std::ios_base::out, _i32 Prot = 64) {
		_del();
		__open(new std::ofstream(FileName, Mode, Prot));
	}
	static void            open    (std::wstring FileName, std::ios_base::openmode Mode = std::ios_base::out, _i32 Prot = 64) {
		_del();
		__open(new std::ofstream(FileName, Mode, Prot));
	}
	static void            open    (std::fstream& FileStream) {
		_del();
		_open(&FileStream);
	}
	static void            open    (std::ofstream& FileStream) {
		_del();
		_open(&FileStream);
	}
	static void            open    (std::streambuf* StreamBuf) {
		_del();
		_open(StreamBuf);
	}
	static void            close   () {
		_del();
		_Print_Out.rdbuf(sb);
	}
	static bool            eof     () {
		return _Print_Out.eof();
	}
	static bool            is_open () {
		return _is_open();
	}

};
__PBuffer::OpenBy __PBuffer::open_by    { __PBuffer::Stream };
std::ofstream*    __PBuffer::ifs        {nullptr};
std::fstream*     __PBuffer::fs         {nullptr};
std::streambuf*   __PBuffer::sb         { std::cout.rdbuf() };
std::ostream      __PBuffer::_Print_Out { std::cout.rdbuf() };





class _Input : public __IBuffer {

	static _ui64 npos;
	_ui64 _Size{npos};

public:
	
	friend _Input&     input   (std::string Text, _ui64 Size);
	friend _Input&     input   (_ui64 Size);

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
	#if (_Version_CPP_17)
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
					 operator _uc8						 () { _ui8  v; _Input_In  >> v; return (_uc8)v;  }
				     operator _uc16						 () { _ui16 v; _Input_In  >> v; return (_uc16)v; }
				     operator _uc32						 () { _ui32 v; _Input_In  >> v; return (_uc32)v; }
	#else
	                 operator _bool						 () { _bool v; _Input_In >> v; return v; }
	                 operator _i8						 () { _i8   v; _Input_In >> v; return v; }
	                 operator _i16						 () { _i16  v; _Input_In >> v; return v; }
	                 operator _i32						 () { _i32  v; _Input_In >> v; return v; }
	                 operator _i64						 () { _i64  v; _Input_In >> v; return v; }
	                 operator _ui8						 () { _ui8  v; _Input_In >> v; return v; }
	                 operator _ui16						 () { _ui16 v; _Input_In >> v; return v; }
	                 operator _ui32						 () { _ui32 v; _Input_In >> v; return v; }
	                 operator _ui64						 () { _ui64 v; _Input_In >> v; return v; }
	                 operator _f32				         () { _f32  v; _Input_In >> v; return v; }
	                 operator _f64					     () { _f64  v; _Input_In >> v; return v; }
	                 operator _lf64					     () { _lf64 v; _Input_In >> v; return v; }
	                 operator _sc8                       () { _sc8  v; _Input_In >> v; return v; }
	                 operator _uc16						 () { _ui16 v; _Input_In >> v; return (_uc16)v; }
	                 operator _uc32						 () { _ui32 v; _Input_In >> v; return (_uc32)v; }
	#endif
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
	_Temp_T_N        operator std::array<T, N>           (){
		std::array<T, N> v;
		if (_Size >= N) for (_ui64 i = 0; i < N; i++) v[i] = *this;
		else for (_ui64 i = 0; i < _Size; i++) v[i] = *this;
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
_ui64 _Input::npos{ (_ui64)-1 };
/// <param name="Text">: ���������, ������� ���������</param>
/// <param name="Size">: ���� Size ���������� � ���������</param>
_Input& input(std::string Text = "", _ui64 Size = _Input::npos) {
	std::cout << Text;
	static _Input st;
	st._Size = Size;
	return st;
}
/// <param name="Size">: ���� Size ���������� � ���������</param>
_Input& input(_ui64 Size){
	static _Input st;
	st._Size = Size;
	return st;
}





class _wInput : public __wIBuffer {

	static _ui64 npos;
	_ui64 _Size{ npos };

public:

	friend _wInput&     winput  (std::string Text, _ui64 Size);
	friend _wInput&     winput  (_ui64 Size);
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
	_Temp_T_N        operator std::array<T, N>() {
		std::array<T, N> v;
		if (_Size >= N) for (_ui64 i = 0; i < N; i++) v[i] = *this;
		else for (_ui64 i = 0; i < _Size; i++) v[i] = *this;
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
_ui64 _wInput::npos{ (_ui64)-1 };
/// <param name="Text">: ���������, ������� ���������</param>
/// <param name="Size">: ���� Size ���������� � ���������</param>
/// <returns></returns>
_wInput& winput(std::string Text = "", _ui64 Size = _wInput::npos) {
	std::cout << Text;
	static _wInput st;
	st._Size = Size;
	return st;
}
/// <param name="Size">: ���� Size ���������� � ���������</param>
/// <returns></returns>
_wInput& winput(_ui64 Size) {
	static _wInput st;
	st._Size = Size;
	return st;
}




struct _cmd {
	_cmd(std::string what, std::string on_what) :what(what), on_what(on_what) {}
	_cmd(std::string what, char on_what) :what(what) { this->on_what += on_what; }
	std::string what{}, on_what{};
};




class _Print : public __PBuffer {
	_Temp_Args friend void print(Args...);

	static void Restart() {
		end = '\n';
		separator = " ";
	}
	
	_Temp_Args static void Start(Args... args) {
		Restart();
		__Test(args...);
		__Print(args...);
		_Print_Out << end;
	} 
	
	_Temp_Args static void __Print(Args... t) {
		now_pos = 0;
		_print(t...);
	}

	_Temp_Args static void __Test(Args... t) {
		need_separator.assign(sizeof...(Args), '0');
		now_pos = 0;
		_test(t...);
		need_separator.back() = '0';
	}

	static std::string end;
	static std::string separator;
	static std::string separator_in_containers;
	static std::string separator_in_map;

	static std::string brackets_in_array;
	static std::string brackets_in_tuple;
	static std::string brackets_in_map;

	_Temp_T		 static void _print(T t) {
		if constexpr (Streamable<T>) { // �������� �� ����� ���� ���������� � stringstream ��������
			_Print_Out << t;
			return;
		}
		else if constexpr (Iterable<T> && !MapLike<T>) { // �������� �� ������
			_Print_Out << brackets_in_array[0];
			_ui64 cnt{ 0 };
			for (auto i : t) {
				_print(i);
				if (cnt + 1 < t.size()) {
					_Print_Out << separator_in_containers;
				}
				cnt++;
			}
			_Print_Out << brackets_in_array[1];
			return;
		}
		else if constexpr (MapLike<T>) { // �������� �� �������
			_Print_Out << brackets_in_map[0];
			_ui64 cnt{ 0 };
			for (auto i : t) {
				_print(i.first);
				_Print_Out << separator_in_map;
				_print(i.second);
				if (cnt + 1 < t.size()) {
					_Print_Out << separator_in_containers;
				}
				cnt++;
			}
			_Print_Out << brackets_in_map[1];
			return;
		}
		else if constexpr (HasContainer<T>) {
			_Print_Out << brackets_in_array[0];
			_ui64 cnt{ 0 };
			for (auto i : t._Get_container()) {
				_print(i);
				if (cnt + 1 < t.size()) {
					_Print_Out << separator_in_containers;
				}
				cnt++;
			}
			_Print_Out << brackets_in_array[1];
			return;
		}
		else if constexpr (IsPair<T>) {
			_Print_Out << brackets_in_array[0];
			_print(t.first);
			_Print_Out << separator_in_containers;
			_print(t.second);
			_Print_Out << brackets_in_array[1];
			return;
		}
		_Print_Out << typeid(T).name();
	}

	_Temp_		 static void _print(_Input t) {
		_Print_Out << (std::string)t;
	}

	_Temp_		 static void _print(_wInput t) {
		std::wcout << (std::wstring)t;
	}

	_Temp_		 static void _print(_cmd t) {}

	_Temp_		 static void _print(bool t) {
		_Print_Out << std::boolalpha << t;
	}
	
	_Temp_T_Args static void _print(T v, Args... w) {
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

	_Temp_T		 static void _test(T t) {
		need_separator[now_pos] = '1';
		now_pos++;
		useful_amount++;
	}

	_Temp_		 static void _test(_cmd t) {
		__cmd[t.what](t.on_what);
		now_pos++;
	}

	_Temp_T_Args static void _test(T t, Args... args) {
		_test(t); _test(args...);
	}

	static std::map<std::string, std::function<void(std::string)>> __cmd;
	static std::string need_separator;
	static _ui64 now_pos;
	static _i32 useful_amount;
};
std::map<std::string, std::function<void(std::string)>> _Print::__cmd{
		{"end", [&](std::string s) {end = s; }},
		{"sep", [&](std::string s) {separator = s; }}
};
std::string _Print::end                     { '\n' };
std::string _Print::separator_in_containers { ", " };
std::string _Print::separator_in_map        { ": " };
std::string _Print::separator               { " "  };
std::string _Print::need_separator;
std::string _Print::brackets_in_array       { "[]" };
std::string _Print::brackets_in_tuple       { "()" };
std::string _Print::brackets_in_map         { "{}" };
_ui64       _Print::now_pos                 {  0   };
_i32		_Print::useful_amount           {  0   };
_Temp_Args void print(Args... args) {
	_Print::Start(args...);
}





//
//struct _SearchIn {
//	
//	//_Temp_T_N     _ui64     _is_conteiner_T                  (T t, N){
//	//	constexpr type_info a = typeid(T);
//	//	if constexpr (a == typeid(std::string))             return _is_conteiner_T(t, N);
//	//	if constexpr (a == typeid(std::pair))               return _is_conteiner_T(t, N);
//	//	if constexpr (a == typeid(std::map))                return _is_conteiner_T(t, N);
//	//	if constexpr (a == typeid(std::unordered_map))      return _is_conteiner_T(t, N);
//	//	if constexpr (a == typeid(std::array))              return _is_conteiner_T(t, N);
//	//	if constexpr (a == typeid(std::vector))             return _is_conteiner_T(t, N);
//	//	if constexpr (a == typeid(std::list))               return _is_conteiner_T(t, N);
//	//	if constexpr (a == typeid(std::forward_list))       return _is_conteiner_T(t, N);
//	//	if constexpr (a == typeid(std::set))                return _is_conteiner_T(t, N);
//	//	if constexpr (a == typeid(std::unordered_set))      return _is_conteiner_T(t, N);
//	//	if constexpr (a == typeid(std::multiset))           return _is_conteiner_T(t, N);
//	//	if constexpr (a == typeid(std::unordered_multiset)) return _is_conteiner_T(t, N);
//	//	if constexpr (a == typeid(std::queue))              return _is_conteiner_T(t, N);
//	//	if constexpr (a == typeid(std::deque))              return _is_conteiner_T(t, N);
//	//	if constexpr (a == typeid(std::stack))              return _is_conteiner_T(t, N);
//	//	if constexpr (!std::is_class<T>::value)             return _is_conteiner_T(t, N);
//	//	return -1;
//	//
//	//}
//
//	//_Temp_T_N     _bool       _is_conteiner_T                  (T t, N){
//	//	
//	//
//	//}
//
//	_Temp_T_N static _bool _cycle_T           (std::string _STR, std::array<T, N> V, _ui64 I) {
//		if (!!I) {
//			_bool _Flag{ false };
//			if constexpr (std::is_class<T>::value) for (auto u : V) _Flag |= _cycle_T(_STR, u, I - 1);
//			else for (auto u : V) _Flag |= (_STR == _to_string_T(u));
//			return _Flag;
//		}
//		return _STR == _to_string_T(V);
//	}
//	_Temp_T   static _bool _cycle_T             (std::string _STR, std::vector<T> V, _ui64 I) {
//		if (!!I) {
//			_bool _Flag{ false };
//			if constexpr (std::is_class<T>::value) for (auto u : V) _Flag |= _cycle_T(_STR, u, I - 1);
//			else for (auto u : V) _Flag |= (_STR == _to_string_T(u));
//			return _Flag;
//		}
//		return _STR == _to_string_T(V);
//	}
//	_Temp_T   static _bool _cycle_T               (std::string _STR, std::list<T> V, _ui64 I) {
//		if (!!I) {
//			_bool _Flag{ false };
//			if constexpr (std::is_class<T>::value) for (auto u : V) _Flag |= _cycle_T(_STR, u, I - 1);
//			else for (auto u : V) _Flag |= (_STR == _to_string_T(u));
//			return _Flag;
//		}
//		return _STR == _to_string_T(V);
//	}
//	_Temp_T   static _bool _cycle_T       (std::string _STR, std::forward_list<T> V, _ui64 I) {
//		if (!!I) {
//			_bool _Flag{ false };
//			if constexpr (std::is_class<T>::value) for (auto u : V) _Flag |= _cycle_T(_STR, u, I - 1);
//			else for (auto u : V) _Flag |= (_STR == _to_string_T(u));
//			return _Flag;
//		}
//		return _STR == _to_string_T(V);
//	}
//	_Temp_T   static _bool _cycle_T                (std::string _STR, std::set<T> V, _ui64 I) {
//		if (!!I) {
//			_bool _Flag{ false };
//			if constexpr (std::is_class<T>::value) for (auto u : V) _Flag |= _cycle_T(_STR, u, I - 1);
//			else for (auto u : V) _Flag |= (_STR == _to_string_T(u));
//			return _Flag;
//		}
//		return _STR == _to_string_T(V);
//	}
//	_Temp_T   static _bool _cycle_T           (std::string _STR, std::multiset<T> V, _ui64 I) {
//		if (!!I) {
//			_bool _Flag{ false };
//			if constexpr (std::is_class<T>::value) for (auto u : V) _Flag |= _cycle_T(_STR, u, I - 1);
//			else for (auto u : V) _Flag |= (_STR == _to_string_T(u));
//			return _Flag;
//		}
//		return _STR == _to_string_T(V);
//	}
//	_Temp_T   static _bool _cycle_T      (std::string _STR, std::unordered_set<T> V, _ui64 I) {
//		if (!!I) {
//			_bool _Flag{ false };
//			if constexpr (std::is_class<T>::value) for (auto u : V) _Flag |= _cycle_T(_STR, u, I - 1);
//			else for (auto u : V) _Flag |= (_STR == _to_string_T(u));
//			return _Flag;
//		}
//		return _STR == _to_string_T(V);
//	}
	//_Temp_T   static _bool _cycle_T (std::string _STR, std::unordered_multiset<T> V, _ui64 I) {
	//	if (!!I) {
	//		_bool _Flag{ false };
	//		if constexpr (std::is_class<T>::value) for (auto u : V) _Flag |= _cycle_T(_STR, u, I - 1);
	//		else for (auto u : V) _Flag |= (_STR == _to_string_T(u));
	//		return _Flag;
	//	}
//		return _STR == _to_string_T(V);
//	}
//	          static _bool _cycle_T                (std::string _STR, std::string V, _ui64 I) {
//		
//		return _STR == _to_string_T(V);
//	}
//
//	///
//	_Temp_T1_T2 static        _ui64 _is_class_T           (std::pair<T1, T2> V, _ui64 I) {}
//	_Temp_T1_T2 static        _ui64 _is_class_T            (std::map<T1, T2> V, _ui64 I) {}
//	_Temp_T1_T2 static        _ui64 _is_class_T  (std::unordered_map<T1, T2> V, _ui64 I) {}
//	///			
//
//	_Temp_T_N   static        _ui64 _is_class_T            (std::array<T, N> V, _ui64 I) { T v{}; return _is_class_T(v, I) + 1; }
//	_Temp_T     static        _ui64 _is_class_T              (std::vector<T> V, _ui64 I) { T v{}; return _is_class_T(v, I) + 1; }
//	_Temp_T     static        _ui64 _is_class_T                (std::list<T> V, _ui64 I) { T v{}; return _is_class_T(v, I) + 1; }
//	_Temp_T     static        _ui64 _is_class_T        (std::forward_list<T> V, _ui64 I) { T v{}; return _is_class_T(v, I) + 1; }
//	_Temp_T     static        _ui64 _is_class_T                 (std::set<T> V, _ui64 I) { T v{}; return _is_class_T(v, I) + 1; }
//	_Temp_T     static        _ui64 _is_class_T            (std::multiset<T> V, _ui64 I) { T v{}; return _is_class_T(v, I) + 1; }
//	_Temp_T     static        _ui64 _is_class_T       (std::unordered_set<T> V, _ui64 I) { T v{}; return _is_class_T(v, I) + 1; }
//	_Temp_T     static        _ui64 _is_class_T  (std::unordered_multiset<T> V, _ui64 I) { T v{}; return _is_class_T(v, I) + 1; }
//	_Temp_T     static        _ui64 _is_class_T                 (std::string V, _ui64 I) { return I + 1; }
//					    
//	///
//	_Temp_T1_T2 static  std::string _to_string_T             (std::pair<T1, T2> V) {
//		return _to_string_T(T1) + _to_string_T(T1);
//	}
//	_Temp_T1_T2 static  std::string _to_string_T              (std::map<T1, T2> V) {
//		
//		
//	}
//	_Temp_T1_T2 static  std::string _to_string_T    (std::unordered_map<T1, T2> V) {
//		
//
//	}
//	///											          
//												          
//	_Temp_T_N   static  std::string _to_string_T           (std::array<T, N> V) {
//		std::string _str;
//		for (auto u : V) _str += _to_string_T(u);
//		return _str;
//	}
//	_Temp_T     static  std::string _to_string_T             (std::vector<T> V) {
//		std::string _str;
//		for (auto u : V) _str += _to_string_T(u);
//		return _str;
//	}	    
//	_Temp_T     static  std::string _to_string_T               (std::list<T> V) {
//		std::string _str;
//		for (auto u : V) _str += _to_string_T(u);
//		return _str;
//	}	    
//	_Temp_T     static  std::string _to_string_T       (std::forward_list<T> V) {
//		std::string _str;
//		for (auto u : V) _str += _to_string_T(u);
//		return _str;
//	}
//	_Temp_T     static  std::string _to_string_T                (std::set<T> V) {
//		std::string _str;
//		for (auto u : V) _str += _to_string_T(u);
//		return _str;
//	}
//	_Temp_T     static  std::string _to_string_T           (std::multiset<T> V) {
//		std::string _str;
//		for (auto u : V) _str += _to_string_T(u);
//		return _str;
//	}
//	_Temp_T     static  std::string _to_string_T      (std::unordered_set<T> V) {
//		std::string _str;
//		for (auto u : V) _str += _to_string_T(u);
//		return _str;
//	}
//	_Temp_T     static  std::string _to_string_T (std::unordered_multiset<T> V) {
//		std::string _str;
//		for (auto u : V) _str += _to_string_T(u);
//		return _str;
//	}
//	            static  std::string _to_string_T                (std::string V) { return V; }
//
//#if (_Version_CPP_17)
//
//	            static  std::string _to_string_T	                    (_bool V) { return std::to_string(V); }
//	            static  std::string _to_string_T	                    (_i8   V) { return std::to_string(V); }
//	            static  std::string _to_string_T	                    (_i16  V) { return std::to_string(V); }
//	            static  std::string _to_string_T	                    (_i32  V) { return std::to_string(V); }
//	            static  std::string _to_string_T	                    (_i64  V) { return std::to_string(V); }
//	            static  std::string _to_string_T	                    (_ui8  V) { return std::to_string(V); }
//	            static  std::string _to_string_T	                    (_ui16 V) { return std::to_string(V); }
//	            static  std::string _to_string_T	                    (_ui32 V) { return std::to_string(V); }
//	            static  std::string _to_string_T	                    (_ui64 V) { return std::to_string(V); }
//	            static  std::string _to_string_T	                    (_f32  V) { return std::to_string(V); }
//	            static  std::string _to_string_T	                    (_f64  V) { return std::to_string(V); }
//	            static  std::string _to_string_T	                    (_lf64 V) { return std::to_string(V); }
//	            static  std::string _to_string_T	                    (_sc8  V) { return std::to_string(V); }
//	            static  std::string _to_string_T	                    (_uc8  V) { return std::to_string(V); }
//	            static  std::string _to_string_T	                    (_uc16 V) { return std::to_string(V); }
//	            static  std::string _to_string_T	                    (_uc32 V) { return std::to_string(V); }
//
//	            static        _ui64 _is_class_T	               (_bool V, _ui64 I) { return I; }
//	            static        _ui64 _is_class_T	               (_i8   V, _ui64 I) { return I; }
//	            static        _ui64 _is_class_T	               (_i16  V, _ui64 I) { return I; }
//	            static        _ui64 _is_class_T	               (_i32  V, _ui64 I) { return I; }
//	            static        _ui64 _is_class_T	               (_i64  V, _ui64 I) { return I; }
//	            static        _ui64 _is_class_T	               (_ui8  V, _ui64 I) { return I; }
//	            static        _ui64 _is_class_T	               (_ui16 V, _ui64 I) { return I; }
//	            static        _ui64 _is_class_T	               (_ui32 V, _ui64 I) { return I; }
//	            static        _ui64 _is_class_T	               (_ui64 V, _ui64 I) { return I; }
//	            static        _ui64 _is_class_T	               (_f32  V, _ui64 I) { return I; }
//	            static        _ui64 _is_class_T	               (_f64  V, _ui64 I) { return I; }
//	            static        _ui64 _is_class_T	               (_lf64 V, _ui64 I) { return I; }
//	            static        _ui64 _is_class_T	               (_sc8  V, _ui64 I) { return I; }
//	            static        _ui64 _is_class_T	               (_uc8  V, _ui64 I) { return I; }
//	            static        _ui64 _is_class_T	               (_uc16 V, _ui64 I) { return I; }
//	            static        _ui64 _is_class_T	               (_uc32 V, _ui64 I) { return I; }									 
//
//#else
//
//	            static  std::string _to_string_T                       (_bool V) { return std::to_string(V); }
//	            static  std::string _to_string_T                       (_i8   V) { return std::to_string(V); }
//	            static  std::string _to_string_T                       (_i16  V) { return std::to_string(V); }
//	            static  std::string _to_string_T                       (_i32  V) { return std::to_string(V); }
//	            static  std::string _to_string_T                       (_i64  V) { return std::to_string(V); }
//	            static  std::string _to_string_T                       (_ui8  V) { return std::to_string(V); }
//	            static  std::string _to_string_T                       (_ui16 V) { return std::to_string(V); }
//	            static  std::string _to_string_T                       (_ui32 V) { return std::to_string(V); }
//	            static  std::string _to_string_T                       (_ui64 V) { return std::to_string(V); }
//	            static  std::string _to_string_T                       (_f32  V) { return std::to_string(V); }
//	            static  std::string _to_string_T                       (_f64  V) { return std::to_string(V); }
//	            static  std::string _to_string_T                       (_lf64 V) { return std::to_string(V); }
//	            static  std::string _to_string_T                       (_sc8  V) { return std::to_string(V); }
//	            static  std::string _to_string_T                       (_uc16 V) { return std::to_string(V); }
//	            static  std::string _to_string_T                       (_uc32 V) { return std::to_string(V); }
//
//	            static        _ui64 _is_class_T               (_bool V, _ui64 I) { return I; }
//	            static        _ui64 _is_class_T               (_i8   V, _ui64 I) { return I; }
//	            static        _ui64 _is_class_T               (_i16  V, _ui64 I) { return I; }
//	            static        _ui64 _is_class_T               (_i32  V, _ui64 I) { return I; }
//	            static        _ui64 _is_class_T               (_i64  V, _ui64 I) { return I; }
//	            static        _ui64 _is_class_T               (_ui8  V, _ui64 I) { return I; }
//	            static        _ui64 _is_class_T               (_ui16 V, _ui64 I) { return I; }
//	            static        _ui64 _is_class_T               (_ui32 V, _ui64 I) { return I; }
//	            static        _ui64 _is_class_T               (_ui64 V, _ui64 I) { return I; }
//	            static        _ui64 _is_class_T               (_f32  V, _ui64 I) { return I; }
//	            static        _ui64 _is_class_T               (_f64  V, _ui64 I) { return I; }
//	            static        _ui64 _is_class_T               (_lf64 V, _ui64 I) { return I; }
//	            static        _ui64 _is_class_T               (_sc8  V, _ui64 I) { return I; }
//	            static        _ui64 _is_class_T               (_uc16 V, _ui64 I) { return I; }
//	            static        _ui64 _is_class_T               (_uc32 V, _ui64 I) { return I; }
//	            								 		 
//#endif
//
//	_Temp_T1_T2 static _bool       _in                          (T1 t1, T2 t2) {
//		_ui64 _dim1 = _is_class_T(t1, 0),
//			  _dim2 = _is_class_T(t2, 0);
//		if (_dim1 == _dim2) return (_to_string_T(t1) == _to_string_T(t2));
//		if (_dim1 > _dim2) return false;
//		return _cycle_T(_to_string_T(t1), t2, _dim2 - _dim1);
//	}
//
//public:
//	
//	_Temp_T1_T2 friend _bool search_in(T1 What, T2 Where);
//	_Temp_T friend _ui64 dimensial_size(T t);
//
//};
//	
//_Temp_T1_T2 _bool search_in(T1 What, T2 Where) {
//	return _SearchIn::_in(What, Where);
//};
//
//_Temp_T _ui64 dimensial_size(T t) {
//	return _SearchIn::_is_class_T(t, 0);
//};



_i64 random(_i64 const less, _i64 const more) {
	return rand() % (more - less) + less;
}

double_t random(double_t const less, double_t const more) {
	return less + (more - less) * ((double_t)(rand() % 0xff) / (double_t)0xff);
}