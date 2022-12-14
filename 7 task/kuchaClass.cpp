#include "kucha.h"
#include<iostream>


template <typename T>
Kucha<T> ::Kucha()
{
    sizeh = 0;
    capacityh = 0;
    h = NULL;
}

template <typename T>
Kucha<T>::Kucha(const Kucha<T>& a)
{
    sizeh = a.sizeh;
    capacityh = sizeh;
    h = NULL;
    if (sizeh != 0)
        h = new T[sizeh];
    else
        h = 0;
    for (int i = 0; i < sizeh; ++i)
        h[i] = a.h[i];
}

template <typename T>
Kucha<T>::~Kucha()
{
    if (h)
        delete[] h;
};

template <typename T>
Kucha<T>::Kucha(int a)
{
    sizeh = a;
    capacityh = a;
    if (a)
        h = new T[a];
    else
        h = 0;
}

template <typename T>
void Kucha<T>::resizeh(int size)
{
    if (size > capacityh)
    {
        int new_capacity = size;
        T* new_data = new T[new_capacity];
        for (int i = 0; i < sizeh; ++i)
            new_data[i] = h[i];
        delete[] h;
        h = new_data;
        capacityh = new_capacity;
    }
    sizeh = size;
}

template <typename T>
void Kucha<T>::push(T n)
{
    resizeh(sizeh + 1);
    int i, parent;
    i = sizeh - 1;

    h[i] = n;
    parent = (i - 1) / 2;
    while (parent >= 0 and i > 0) {
        if (h[i] > h[parent]) {
            int temp = h[i];
            h[i] = h[parent];
            h[parent] = temp;
        }
        i = parent;
        parent = (i - 1) / 2;
    }
}

template <typename T>
void Kucha<T>::showHeap() {
    int i = 0;
    int k = 1;
    while (i < sizeh) {
        while ((i < k) && (i < sizeh)) {
            cout << h[i] << " ";
            i++;
        }
        cout << endl;
        k = k * 2 + 1;
    }
}

template <typename T>
void Kucha<T>::showArray() {
    for (int i = 0; i < sizeh; i++) {
        cout << h[i] << " ";
    }
    cout << endl;
}

template <typename T>
void Kucha<T>::sorth(int i) {
    int  l, r;
    int temp;
     l = 2 * i + 1;
     r = 2 * i + 2;
    if ( l < sizeh) {
        if (h[i] < h[ l]) {
            temp = h[i];
            h[i] = h[ l];
            h[ l] = temp;
            sorth( l);
        }
    }
    if (r < sizeh) {
        if (h[i] < h[r]) {
            temp = h[i];
            h[i] = h[r];
            h[r] = temp;
            sorth(r);
        }
    }
}

template<typename T>
T Kucha<T>::top() {
    return h[0];
}
