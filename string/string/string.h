# define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <assert.h>
using namespace std;

namespace Simulation
{
	class string
	{  
	public:
		typedef char* iterator;
		typedef const char* const_iterator;

		iterator begin()
		{
			return _str;
		}

		const_iterator begin()const
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		const_iterator end()const
		{
			return _str + _size;
		}

		string(const char* str = "")
			:_size(strlen(str)),
			_capacity(_size)
		{
			_str = new char[_size + 1];
			strcpy(_str, str);
		}

		// 传统写法
		//string(const string& s)
		//	:_size(s._size),
		//	_capacity(s._capacity)
		//{
		//	_str = new char[_capacity + 1];
		//	strcpy(_str, s._str);
		//}
		
		// 现代写法
		string(const string& s)
			:_str(nullptr)
			, _size(0)
			,_capacity(0)			
		{
			string tmp(s.c_str());
			swap(tmp);
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

		// 传统写法
		//string& operator=(const string s)
		//{
		//	if (&s != this)
		//	{
		//		// 如果拷贝失败，将delete放在后面不至于删掉原数据
		//		char* tmp = new char[s._size + 1];
		//		strcpy(tmp, s._str);				
		//		delete[] _str;
		//		_size = s._size;
		//		_capacity = s._capacity;
		//		_str = tmp;
		//	}

		//	return *this;
		//}

		// 现代写法
		string& operator=(string s)
		{
			swap(s);
			return *this;
		}

		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}

		char* c_str() const
		{
			return _str;
		}

		char& operator[](size_t pos)
		{
			return _str[pos];
		}

		const char& operator[](size_t pos) const
		{
			return _str[pos];
		}
		
		int size()const
		{
			return _size;
		}
		
		int capacity()const
		{
			return _capacity;
		}

		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				_capacity = n;
				delete[] _str;
				_str = tmp;
			}
		}

		void resize(size_t n, char ch = '\0')
		{
			if (n <= _size)
			{
				_str[n] = '\0';
				_size = n;
			}
			else
			{
				reserve(n);
				memset(_str + _size, ch, n - _size);
				_str[n] = '\0';
				_size = n;
			}

		}

		void push_back(char ch)
		{
			//if (_size == _capacity)
			//{
			//	reserve(_capacity == 0 ? 4 : _capacity * 2);
			//}

			//_str[_size++] = ch;
			//_str[_size] = 0;

			insert(_size, ch);
		}

		void append(const char* s)
		{
			/*size_t len = strlen(s);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}

			strcpy(_str + _size, s);
			_size += len;*/

			insert(_size, s);
		}

		string& operator+=(char c)
		{
			push_back(c);

			return *this;
		}

		string& operator+=(const char* str)
		{
			append(str);

			return *this;
		}

		void clear()
		{			
			_str[0] = '\0';
			_size = 0;
		}

		// 返回c在string中第一次出现的位置

		size_t find(char c, size_t pos = 0) const
		{
			for (size_t i = 0; i < _size; ++i)
			{
				if (_str[i] == c)
				{
					return i;
				}
			}

			return npos;
		}

		// 返回子串s在string中第一次出现的位置

		size_t find(const char* s, size_t pos = 0) const
		{
			char* ret = strstr(_str, s);

			if (ret == nullptr)
			{
				return npos;
			}

			return ret - _str;
		}

		// 在pos位置上插入字符c/字符串str

		string& insert(size_t pos, char c)
		{
			assert(pos <= _size);

			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}

			size_t end = _size + 1;
			for (size_t i = end; i > pos; --i)
			{
				_str[i] = _str[i - 1];
			}

			_str[pos] = c;
			_size++;

			return *this;
		}

		string& insert(size_t pos, const char* str)
		{
			assert(pos <= _size);
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}

			size_t end = _size + len;

			for (size_t i = end; i >= pos + len; --i)
			{
				_str[i] = _str[i - len];
			}

			strncpy(_str + pos, str, len);
			_size += len;

			return *this;
		}

		// 删除pos位置上的元素

		string& erase(size_t pos, size_t len)
		{
			assert(pos < _size);

			if (pos + len >= _size)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				strcpy(_str + pos, _str + pos + len);
				_size -= len;
			}

			return *this;
		}

		// 相关符号

		//bool operator<(const string& s)
		//{
		//	return strcmp(_str, s._str) < 0;
		//}

		//bool operator<=(const string& s)
		//{
		//	return !(*this > s);
		//}

		//bool operator>(const string& s)
		//{
		//	return strcmp(_str, s._str) > 0;
		//}

		//bool operator>=(const string& s)
		//{
		//	return !(*this < s);
		//}

		//bool operator==(const string& s)
		//{
		//	return strcmp(_str, s._str) == 0;
		//}

		//bool operator!=(const string& s)
		//{
		//	return !(*this == s);
		//}

		//friend istream& operator>>(istream& in, string& s);
		//friend ostream& operator<<(ostream& out, const string& s);



	private:
		char* _str;
		size_t _size;
		size_t _capacity;
		
	public:
		static const size_t npos = -1;
	};

	bool operator==(const string& s1, const string& s2)
	{
		return strcmp(s1.c_str(), s2.c_str()) == 0;
	}

	bool operator>(const string& s1, const string& s2)
	{
		return strcmp(s1.c_str(), s2.c_str()) > 0;
	}

	bool operator>=(const string& s1, const string& s2)
	{
		return s1 > s2 || s1 == s2;
	}

	bool operator<(const string& s1, const string& s2)
	{
		return !(s1 >= s2);
	}

	bool operator<=(const string& s1, const string& s2)
	{
		return !(s1 > s2);
	}

	bool operator!=(const string& s1, const string& s2)
	{
		return !(s1 == s2);
	}

	istream& operator>>(istream& in, string& s)
	{
		s.clear();

		char ch = in.get();
		while (ch != ' ' && ch != '\n')
		{
			s += ch;
			ch = in.get();
		}

		return in;
	}

	ostream& operator<<(ostream& out, const string& s)
	{
		for (auto e : s)
		{
			out << e;
		}

		return out;
	}


	void test1()
	{
		string s1("hello world!");
		string s2(s1);
		string s3;
		s3 = s2;
	}

	//void test2()
	//{
	//	string s1("baichen");
	//	const string s2 = "hello,world";
	//	string s3;

	//	/*s3 = s1 = s1;*/
	//	size_t len1 = s1.size();
	//	size_t len2 = s2.size();
	//	for (size_t i = 0; i < len2; i++)
	//	{
	//		cout << s2[i] << " ";
	//	}
	//	cout << endl;

	//	string::iterator begin = s1.begin();
	//	while (begin != s1.end())
	//	{
	//		*begin += 1;
	//		begin++;
	//	}

	//	for (auto ch : s1)
	//	{
	//		cout << ch << " ";
	//	}
	//	cout << endl;

	//	const_iterator cbegin = s2.begin();
	//	for (; cbegin != s2.end(); cbegin++)
	//	{
	//		cout << *cbegin << " ";
	//	}
	//	cout << endl;
	//}

	void test3()
	{
		//string s("baichendada");
		//s.reserve(60);
		//s.resize(3);
		//s.reserve(20);
		//s.resize(20, 'a');
		//s.resize(30);

		string s;
		s.push_back('b');
		s.append("aichen");
		s += 'd';
		s += "ada";

		size_t pos = s.find('b');
		pos = s.find('l');
		pos = s.find("baichen");
		pos = s.find("baichel");
	}

	/*void test4()
	{
		string s("li");

		s.insert(0, 'b');
		s.insert(0, "baichen");
		cout << s._str << endl;
		s.insert(s._size, "02");
		s.insert(s._size, '1');
		s.insert(5, '2');
		s.insert(6, '3');

		s.erase(0, 2);
		s.erase(4, 1);
		s.erase(s._size - 1, 1);
		s.erase(0, npos);
	}*/

	void test5()
	{
		string s1("bai");
		string s2("chen");
		string s3(s1);
		bool jud = s1 == s2;
		jud = s1 == s3;
		jud = s2 != s3;
		jud = s2 < s3;
		jud = s2 > s3;
		jud = s2 >= s3;
		jud = s2 <= s3;

	}

	void test6()
	{
		string s1, s2;
		cin >> s1 >> s2;
		cout << s1 << s2;
	}

}

