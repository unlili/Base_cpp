### 特化

```c++
template<typename T> //泛化
T max(T a,T b)
{
    return a < b ? b : a;
}

template<> //特化一个版本
int max(int a,int b)
{
    return a < b ? a : b; 
}
//--------------------------------------------------------------
template<class T,class Alloc = alloc> 
class vector {}

//局部特化.偏特化
template<class Alloc> 
class vector<bool,Alloc> {}
```

