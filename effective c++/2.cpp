#ifdef 0
  使用 const enum inline 替换 #define
  
  #define PI 3.1415926535 ---> const double PI = 3.1415926535
  
  类内的宏定义是没有作用域的，使用enum可以防止取地址操作
  enum { AAA }  ---> 
 
  inline 函数 替换宏函数

#endif


#define MAX(a,b) \
  do{\
    f( (a)>(b):(a)?(b) )\
  } while (0)
//---->

template<typename T>
inline T max(T a,T b)
{
    return f(a>b ? a : b)  
}


