###  set

```c++
//set底层实现 gunc
tempalte<
    class Key,
    class Compare = less<key>,  //底层默认调用小于比较,所以一般直接重载<就可以了
    class Alloc = alloc
    >
class set
{
public:
    typedef Key key_type;
    typedef Key value_type;  //key_type和value_type是同一个东西
    typedef Compare key_compare;
    typedef Compare value_compare; //比较的方法一样
private:
    //identity<value_type> 怎么样通过value取key
    typedef rb_tree<key_type,value_type,
    				identity<value_type>,key_compare,Alloc>  rep_type;
    reptype t;//实例化一个红黑树
public:
   typedef typename rep_type::const_iterator iterator;//set的底层迭代器被def为const类型,set不能通过iterator修改值,拿到的是红黑树的const_iterator
    ....   //set的所有操作底层都是调用rb_tree的函数,所有set也就是container adapter 相当于queue/stack
};
/*
set<int> iset;
===>set<int,less<int>,alloc>
=====>template<int,int,identity<int>,less<int>,alloc> class rb_tree;
*/
```

trips: queue stack底层都是deque实现

```c++
//嫖的测试代码
void test_multiset(long & value)
{
multiset<string> c;
clock_t timeStart = clock();

	for (long i = 0; i < value; ++i)
	{
		try
		{
			cout << i<<"\n";
			c.insert(to_string( (rand()%32767)+1 ));
		}
		catch (const std::exception&p)
		{
			cout << "i = " << i << p.what() << endl;
			abort();
		}
	}

	cout << "插入所用时间:" << ((clock() - timeStart)/60000) <<"mins"<< endl;
	cout << "multiset大小:" << c.size() << endl;
	cout << "multiset最大尺寸:" << c.max_size() << endl;//multiset 


	timeStart = clock();
	auto pItem = ::find(c.begin(), c.end(), "32131");
	cout << "::find所用时间:" << ((clock() - timeStart)/60000) <<"mins"<< endl;

	if (pItem != c.end())
	{
		cout << "find success:" << *pItem << endl;
	}
	else
	{
		cout << "find fail" << endl;
	}

	timeStart = clock();
	c.find("32131");
	cout << "c.find所用时间:" <<  ((clock() - timeStart)/60000) <<"mins"<< endl;

	if (pItem != c.end())
	{
		cout << "c.find success:" << *pItem << endl;
	}
	else
	{
		cout << "c.find fail" << endl;
	}
}

```



### 容器rb_tree

