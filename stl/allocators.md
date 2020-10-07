### operator new

```c++
void * operator new (size_t size,const std::nothrow_t &)  _THROW0()
{
    void * p;
    while((p=malloc(size))==0)
    {
        _TRY_BEGIN
        if(_callnewh(size)==0) break;
        _CATCH(std::bad_alloc) return (0);
        _CATCH_END
    }
    return (p);
}
```



### malloc

```c++

```



### 分配器allocators



### alloc

内部

