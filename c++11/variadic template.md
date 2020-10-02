### variadic template 可变参数模板





```c++
//example-5
int maximum(a)
{
    return a;
}
template<typename... Args>
int maximum(int n,Args... args)
{
    return std::max(n,maximum(args...));
}
```



```c++
//example-6-直观的打印一个tuple
cout << make_tuple(7.5,string("hello"),bitset<16>(377),42) < <endl;


```



```c++
//简易tuple-递归继承
template<typename... Values> class tuple;
template<> class tuple<>{};

templae<typename Head,typename... Tail>
class tuple<Head,Tail...>:private tuple<Tail...>
{
	typedef tuple<Tail...> inherited;
protected:
	Head m_head;
public:
	tuple(){}
	tuple(Head v,Tail... vtail)
		:m_head(v),inherited(vtail){} // 调用父类的构造函数
		
	//typename Head::type head(){return m_head;}
	//auto head() -> decltype(m_head) {return m_head;}
	Head head() {return m_head;}
	
	inherited & tail(){return *this;}
};
```







