#include <iostream>
#include "shared_ptr.cpp"

using namespace std;

//I — Написать shared_ptr ++
//Он должен:
//1) поддерживать кастомный deleter ++
//2) иметь хотя бы 2 обоснованных ситуации, в которых он бросает исключения
//3) поддерживать логические операции ++
//4) иметь свой make_shared
//5) быть CopyConstructible, CopyAssignable ++

template <typename T>
class CustomDeleter{
public:
  void operator()(T* p){
    cout << "custom deleter used" << endl;
    free(p);
  }
};



int main(){

    poter<int> a(new int(151));
    *a = 100;
    cout << "value: " << *a << endl;
    cout << a;

    poter<int> b = a;
    cout << b;
    {
     poter<int> c(a);
     cout <<  c;
    }
    cout << "counter: " << a.UseCount() << endl << endl;


    {
        poter<char, CustomDeleter<char>> d;
    }
    cout << endl;

    poter<int> y;
    cout <<  *y;

    return 0;
}

