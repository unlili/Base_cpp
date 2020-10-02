### tuple

可变参数模板递归继承

#### 创建一个tuple

```c++
tuple<int,double,string> t;
tuple<int,double,string> t(12,34.23,"hwquhe");
auto t1 = make_tuple(22,44,"stacy");
```



#### 引用tuple元素

```c++
get<0>(t); //获得t的第0个元素
get<2>(t1) = get<1>(t)//  get函数模板返回的是引用	
```



#### 捆绑一个tuple

```c++
tuple<string, int, double> t("qwqeqwe",12,34.34);
string str;
int in;
double dou;
tie(str, in, dou) = t;

```



#### 秀 meat programing

```c++
typedef tuple<int, float, double> TupleType;

cout << tuple_size<TupleType>::value << endl;      //tuple中的个数
tuple_element<1, TupleType>::type f1=23;           //使用TupleType中第一个类型声明一个变量
typedef tuple_element<1, TupleType>::type TupleType_Type_0;//使用TupleType中第一个类型改个名字
TupleType_Type_0 f2=17;
```

