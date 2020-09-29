### decltype

**decltype(obj)  // 返回括号内表达式的结果的类型**

* **返回一个函数的类型 use declare return type**
* **元编程,我不会**
* **used to pass the type of a lambda**



```c++
#include<map>
#include<iostream>
#include<string>
#include<set>
using namespace std;

/*第一种用法*/
template<typename T1,typename T2>
decltype(x + y) add(T1 x, T2 y);

template<typename T1, typename T2>
auto add(T1 x, T2 y) -> decltype(x + y);

auto a(int x, int y) -> int { return x*y; }

/*第二种用法*/
template<typename T>
coid test_decltype(T obj)
{
	map<string, float>:value_type elem1;//定义一个元素

	map<string, float> coll;
	decltype(coll)::value_type elem2;//coll必须是一个容器

	typedef typename decltype(T)::iterator iType;//获得T的迭代器的类型,
}


/*第三种用法*/
class Person {};
auto cmp = [](const Person & p1, const Person & p2) {
				return (p1.lastname() == p2.lastname() &&
				p1.firstname() < p2.firstname());
			};
set<Person, decltype(cmp)> coll(cmp); //set的接口需要把cmp传入构造函数,否则就是默认的


int main()
{
	map<string, int> col;
	decltype(col)::value_type elem; // ==> map<string, int>::value_type elem;
	cout << a(3, 3) << "\n";
	system("pause");
	return 0;
}
```

