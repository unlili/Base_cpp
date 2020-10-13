### map

* 红黑树
* 自动排序
* value(key|data)  一个value==key+data
* 禁止修改key,允许修改data

```c++
//set底层实现 gunc
tempalte<
    class Key,
    class T,
    class Compare = less<key>,  //底层默认调用小于比较,所以一般直接重载<就可以了
    class Alloc = alloc
    >
class map
{
public:
    typedef Key key_type;
    typedef T T_type;  //key_type和value_type是同一个东西
    typedef T mapped_type;
    typedef pair<const key,T> value_type;
    typedef Compare key_compare;
private:
    //select1st<value_type> 怎么样通过value取key
    typedef rb_tree<key_type,value_type,
    				select1st<value_type>,key_compare,Alloc>  rep_type;
    reptype t;//实例化一个红黑树
public:
  	typedef typename rep_type::iterator iterator;//map的迭代器就是红黑树的迭代器,允许修改data 
};
/*
map<int,string> imap;
===>map<int,
		string,
		less<int>,
		alloc
		>imap;
====>template<
			int,
			pair<const int,string>
			select1st<pair<const int,string>>,
			less<int>,
			alloc
			>class rb_tree;
*/
```



### map的operator[]

**通过key来修改data,如果key不存在的话会创建一个key放进去 **

**底层先调用二分查找第一个相同的元素,如果没有会得到一个最适合放这个元素的位置,并调用insert插进去 **



```c++
//测试
namespace cczh02
{
void test_multiset(long & value)
{
multimap<long,string> c;
clock_t timeStart = clock();

	for (long i = 0; i < value; ++i)
	{
		try
		{
			cout << i<<"\n";
			//multimap不能用[] 做插入
			c.insert(pair<long,string>(i, to_string((rand() % 32767) + 1)) );
            //c[i]=  to_string((rand() % 32767) + 1) 效率太低
		}
		catch (const std::exception&p)
		{
			cout << "i = " << i << p.what() << endl;
			abort();
		}
	}

	cout << "插入所用时间:" << ((clock() - timeStart) / 10000) << "s" << endl;
	cout << "multimap大小:" << c.size() << endl;
	cout << "multimap最大尺寸:" << c.max_size() << endl;//multiset 


	
	timeStart = clock();
	auto res = c.find(32131);
	cout << "c.find所用时间:" << ((clock() - timeStart)/10000) <<"s"<< endl;

	if (res != c.end())
	{
		cout << "c.find success:" << res->second << endl;
	}
	else
	{
		cout << "c.find fail" << endl;
	}
}


}
```













