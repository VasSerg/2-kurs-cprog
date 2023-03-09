#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class LRU{
private:
    int capacity;
    int siz = 0;
    list<int> priority;
    unordered_map<int,int> mem;
public:
    LRU(int cap = 10){
        capacity = cap;
    };
    ~LRU(){
        mem.clear();
        priority.clear();
        siz = 0;
        capacity = 0;
    };

    int get(int key){
        int el = mem[key];
        if (el){
            priority.remove(key);
            priority.push_back(key);
        }
        return el;
        //работает за О(1) тк используемые здесь операции для unordered_map и list работают за О(1)
    };
    void put(int key, int value){
        if(mem[key])
            priority.remove(key);
        else if (siz < capacity){
            siz++;
        }
        else{
            mem.erase(priority.front());
            priority.pop_front();
            priority.push_back(key);
        }
        priority.push_back(key);
        mem[key] = value;
        //работает за О(1) тк используемые здесь операции для unordered_map и list работают за О(1)
    };
    void pop(int key){
        mem.erase(key);
        priority.remove(key);
        siz--;
    }
};


int main()
{
    LRU a(3);
    a.put(10,12);
    a.put(15,13);
    a.put(20,14);
    cout <<a.get(10)<< endl;
    cout <<a.get(15)<< endl;
    cout <<a.get(20)<< endl;
    cout << endl;
    //все элементы выводятся

    a.put(25,15);
    cout <<a.get(25)<< endl;
    cout <<a.get(10)<< endl<< endl;
    //добавление 4-го стирает первый

    a.put(15,16);
    a.put(35,17);
    cout <<a.get(15)<< endl;
    cout <<a.get(20)<< endl<< endl;
    //перезапись первого в очереди элемента спасло его от удаления, удалился второй в очереди

    cout <<a.get(25)<< endl<< endl;
    // элемент с ключом 35 не вызывали с get, поэтому он стал первым в очереди на удаление
     a.put(40,18);
     cout <<a.get(35)<< endl;
     //вот он и удалился

}

