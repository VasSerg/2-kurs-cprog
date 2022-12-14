#pragma once

#include<iostream>
using namespace std;


template<typename T>
class Kucha {
private:
	T* h;
	int sizeh, capacityh;
public:
	Kucha();
	Kucha(const Kucha<T>& a);
	Kucha(int a);
	~Kucha();

	void resizeh(int size);
	void push(T n);
	void showHeap();
	void showArray();
	void sorth(int i);
	T top();
};

