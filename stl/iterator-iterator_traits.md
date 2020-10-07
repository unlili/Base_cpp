### iterator需要遵循的原则

* **移动性质,迭代器所支持的操作**
* **value_type iterator所指元素的类型**
* **difference_type 两个iterator之间的距离用什么类型来表示**
* reference
* pointer



### traits

**用以分离 class iterators 和 non-class iterators**

**取得容器迭代器的typedef 用给algorithm**

**相当于加入了一个中间层**

* 分辨是c++天然的指针,还是容器的指针
* 容器的指针提供了特殊操作,但是两者行为一模一样



```c++
//不是native pointer 转交给容器自己提问
template<class T>
    struct iterator_traits{
      typedef typename I::value_type value_type;  
    };

//两个偏特化版本重新定义value_type类型
template<class T>
    struct iterator_traits<T *>{
      typedef T value_type;  
    };
template<class T>
    struct iterator_traits<const T *>{
      typedef T value_type;   //const T 无法被赋值没有意义
    };

template<typename I,...>
void algorithm(...)
{
    typename iterator_traits<T>::value_type v1;//加typename表白这是一个类型
}
```



许多traits

*  type traits
* iterator traits
* char traits
* allocator traits
* pointer traits
* array traits









































