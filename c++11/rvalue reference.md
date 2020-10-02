### Rvalue reference

**获得右值的引用**

* 右值rvalue : **只能**出现在 operator= 右边,  例如:临时对象
* 左值lvalue : 出现在 operator= 左边,也可以出现在右边

```c++
int a=3,b=5;
a = b;
b = a;
a = a + b;
a + b = 5; // a+b就是一个右值
```

```c++
string s1("aaa");
string s2("bbb");
s1 + s2 = s2;   //编译可以通过
string() = "world"  //给一个temp obj assign
```

```
int foo() {return 5;}
//auto f = []{return 5;}

int *p = &foo(); //Error 在c++11之前不可以对右值reference,, 现在需要取得右值的地址
```



### std::move

```c++
#include<map>
#include<iostream>
#include<string>
#include<set>
using namespace std;

void test(int && a)//右值
{
	cout << "右值" << "\n";
}

void test(int & a)//左值
{
	cout << "左值" << "\n";
}

template<typename T>
void fun(T && a)
{
	cout << "a = " << a << endl;
	test(forward<T>(a));//使用forward模板函数调用右值版本
}

template<typename T>
void func(T && a)
{
	cout << "a = " << a << endl;
	test(a);  //调用左值版本test
}

int main()
{
	int a = 1;
	//test(1);
	//test(a);
	//test(move(a));

	fun<int>(1);
	//fun(a);  //Error fun需要的是一个右值
	fun<int>(move(a));

	

	system("pause");
	return 0;
}
```



### move aware class

```c++
#include<map>
#include<iostream>
#include<string>
#include<set>
using namespace std;

class MyString
{
public:
	static size_t DCtor;//default-constructor
	static size_t Ctor; //constructor
	static size_t CCtor;//copy-constructor
	static size_t CAsgn;//copy-assign
	static size_t MCtor;//move-constructor
	static size_t MAsgn;//cmove-assign
	static size_t Dtor; //desstructor
private:
	char * _data;
	size_t  _len;
	void _init_data(const char * p)
	{
		_data = new char[_len+1];
		memcpy(_data, p, _len);
		_data[_len] = '\0';
	}
public:
	//default-ctor
	MyString() :_data(nullptr), _len(0) { ++DCtor; }
	//ctor
	MyString(const char * p) :_len(strlen(p))
	{
		++Ctor;
		_init_data(p);
	}
	//copy-ctor
	MyString(const MyString & m) : _len(m._len)
	{
		++CCtor;
		_init_data(m._data);
	}
	//move-ctor
	MyString(MyString && str) noexcept :_data(str._data), _len(str._len)
	{
		++MCtor;
		str._data = nullptr;  //很关键 防止析构函数释放str._data
		str._len = 0;
	}
	//copy-assign
	MyString& operator= (const MyString & str)
	{
		++CAsgn;
		if (this != &str)
		{
			if (_data) delete _data;
			this->_data = str._data;
			_init_data(str._data);
		}
		return *this;
	}

	//move-assign
	MyString& operator= (MyString && str) noexcept
	{
		++MAsgn;
		if (this != &str)
		{
			if (_data) delete _data; //释放掉自己原来的
			this->_len = str._len;
			this->_data = str._data;
			str._len = 0;
			str._data = nullptr;
		}
		return *this;
	}


	virtual ~MyString()
	{	
		++Dtor;
		if (_data) delete _data;
	}

	bool operator< (const MyString & r) const
	{
		return string(this->_data) < string(r._data);
	}
	bool operator== (const MyString & r) const
	{
		return string(this->_data) == string(r._data);
	}
	char * get() { return this->_data; }
};
```

































