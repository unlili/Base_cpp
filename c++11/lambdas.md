### lambda



**[] () mutable throwSpec -> retType { }; **

* []  需要的外界的变量,可以值传递,也可以传引用
* 值传递想要改变值的话得加mutable
* 相当于创建了一个匿名函数对象

```c++
#include<map>
#include<iostream>
#include<string>
#include<set>
using namespace std;

int main()
{

	int id = 0;
	auto f = [id]()mutable{
		cout << "id:" << id << endl;
		++id;  //没有mutable  id就不可变
	};

	id = 42;
	f();//print id:0
	f();//print id:1
	f();//print id:2
	f();//print id:3
	cout << id << endl;// 42

	/* 上面等价于==>
	class Functor
	{
		private: int id=0;
		public:
		void operator() ()
		{
			cout << "id:" << id << endl;
			++id;
		}
	};
	Functor f;
	*/

	[] {
		cout << "nmsl" << endl;
	}();  //直接打印nmsl

	auto l = [] {cout << "nmsl" << endl; };
	l(); //打印nmsl

	system("pause");
	return 0;
}
```

````c++
int tobefound = 5;
auto lambda1 = [tobefond](int val) {return val == tobefound; };

//===>
class UnNameLocalFunctor
{
  int localVal;
public:
    UnNameLocalFunctor(int val):localVal(cal){};
    bool operator() (int tobefound)  {return localVal == tobefound;}
};

````















