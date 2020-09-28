### 给模板取别名 Alias Template

```c++
template <typename T>
using Vec = std::vector<T,MyAlloc<T>>;

Vec<int> coll; //===>  std::vector<int,MyAlloc<int>> coll
```

**typedef 和 #define 是无法传参数的,只是原样替换**

```c++
//输入一个容器和一个对象,函数中生成装有该对象的容器
//列如: fun(list,string)  ==>  list<string>


template<typename Container>
void test_moveable(Container c)
{
    //获取容器中的类型
    typedef typrname iterator_traits<typename Container::iterator>::value_type Valtype;
    
}

```

---

### template template parameter

```c++

template<typename T,
		template<class>
		class Container
		>                       //软秀飞  , 不划水怎么专心听课
class XCls
{
private:
    Container<T> c;
public:
    XCls()
    {
        for(long i = 0;i<SIZE;++i)
        	c.insert(c.end,T());
        out_static_data(T());
     	Container<T> cl(c);
        Container<T> c2(std::move(c));
        c1.swap(c2);
    }
} 

template<typename T>
using Vec = vector<T,allocator<T>>;

template<typename T>
using Lst = listr<T,allocator<T>>;

template<typename T>
using Deq = deque<T,allocator<T>>;

//2020年9月28日20:48:25 根本看不懂 呵呵, c++ cnm 
```



---

### Type Alias (类似于typedef)

使用using 给类型取别名

```c++
//typedef void(*func)(int,int);
using func = void(*)(int,int);

void example(int,int){}
func fn = example;
```

```c++
template<typename T>
struct Container
{
  using value_type = T;  
};
```

```c++
templaye<class T>
using nystring = std::basic_string<T,std::char_traits<T>>;

mystring<char> str;
```



### noexcept(异常)

```c++
void foo() noexpect;  //告诉编译器着个函数保证不丢异常



```

#### &&



**移动构造,通过noexpect告诉编译器,这个构造函数是比拷贝构造效率更高的构造函数**

```c++
class MyString
{
 private:
    char * _data;
    size_t _len;
 public:   
    MyString(Mystring && str) noexcept : _data(str._data),_len(str._len) {...}
    MyString & operator=(MyString && str) noexcept 
    {......  return *this;}
    
};
```





---



### override

告诉编译器你要复写某个函数





### final

告诉编译器你是最后一个继承的

```c++
struct Base final{};  //这个类不可以被继承

struct Base2
{
    virtual void f() final; //  着个虚函数不能被子类复写
}

```















