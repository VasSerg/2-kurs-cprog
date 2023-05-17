#include <iostream>
#include <memory>
#pragma once
using namespace std;

template <typename T, class deleter>
class Counter{
private:
    unsigned int num;
    T* linkedptr;
public:
    Counter(T* pt){
        num = 0;
        linkedptr = pt;
    }
    Counter(const Counter&) = delete;
    Counter& operator=(const Counter&) = delete;
    unsigned int get(){
      return num;
    }
    void operator++(int)
    {
      num++;
    }
    void operator--(int)
    {
      num--;
    }
    friend ostream& operator<<(ostream& os, const Counter& c)
    {
        os << "Counter: " << c.num << endl;
        return os;
    }
    ~Counter(){
        deleter()(linkedptr);
    }
};

template <typename T, class deleter = default_delete<T>>
class poter{
private:
    Counter<T,deleter>* counte;
    T* ptr;

public:
    // ne copy
    explicit poter(T* p = nullptr) : ptr(p)
    {
        counte = new Counter<T,deleter>(ptr);
        (*counte)++;
    }
    // copy
    poter(poter<T,deleter>& po) : ptr(po.ptr), counte(po.counte)
    {
        (*counte)++;
    }

    poter operator=(poter po){
        this -> ~poter();
        ptr = po.ptr;
        counte =po.counte;
        (*counte)++;
        return *this;
    }
    unsigned int UseCount() {
        return counte -> get();
    }
    T* get()
    {
      return ptr;
    }
    T& operator*()
    {
    if (ptr)
        return *ptr;
    else
        throw runtime_error("nullptr error");
    }

    T* operator->()
    {
    if (ptr)
        return ptr;
    else
        throw runtime_error("nullptr get ptr error");
    }
    ~poter()
    {
    (*counte)--;
    if (counte ->get() == 0)
        delete counte;
    else
        throw runtime_error("nullptr delete error");
    }

    friend ostream& operator<<(ostream& os, poter<T,deleter>& sp)
    {
        os << "ptr: " << sp.get() << endl
;
        os << "count: " << *sp.counte << endl;
        return os;
    }

};


template <typename T, typename... Args>
poter<T, default_delete<T>> make_shared_(Args&&... args) {
    auto counterr = new Counter<T, default_delete<T>>(new T(forward<Args>(args)...));
    return poter<T, default_delete<T>>(counterr);
}
