#ifdef 0
  使用 const enum inline 替换 #define
  
  #define PI 3.1415926535 ---> const double PI = 3.1415926535
  
  类内的宏定义是没有作用域的，使用enum可以防止取地址操作
  enum { AAA }  ---> 
 
  inline 函数

#endif




