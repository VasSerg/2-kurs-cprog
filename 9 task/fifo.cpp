#include <deque>
#include <vector>
#include <string>
#include <iostream>

using namespace std;


template <class T, class container = deque <T>>
class MyFIFO{
private:
    container cont;

public:
    void push(const T& el){
        cont.push_back(el);
    }
    T get() {
        if (cont.size() != 0){
            T tim = cont.front();
            cont.pop_front();
            return tim;
        }
        else
            return NULL;
    }
};

template <>
class MyFIFO<char, string> {
private:
	string cont;

public:
	void push(const char c){
		cont += c;
	}
	char get() {
		if (cont.size() != 0){
			char tmp = cont[0];
			cont = cont.substr(1, cont.size() - 1);
			return tmp;
		}
		else
            return NULL;
	}
};



template <class T>
class MyFIFO<T,vector<T>> {
private:
    vector<T> cont;
public:
    void push(const T& el) {
        cont.push_back(el);
    }
    T get() {
         if (cont.size() != 0){
            T tmp = cont[0];
            for (int i = 0; i < cont.size()-1; i++) {
                cont[i] = cont[i + 1];
            }
            cont.resize(cont.size() - 1);
            return tmp;
        }
        else
            return NULL;
    }
};

