
#include<iostream>
#include<tuple>

using namespace std;

template <typename T>
void printElem(const T& x) {
    cout << x << " ";
};

template <typename TupleT, size_t... Is>
void printTupleManual(const TupleT& tp, index_sequence<Is...>) {
    (printElem(get<Is>(tp)), ...);
}

template <typename TupleT, size_t TupSize = tuple_size_v<TupleT>>
void printTuple(const TupleT& tp) {
    printTupleManual(tp, make_index_sequence<TupSize>{});
}


int main() {
    tuple a{ 6, 'a', "klim", 3.1415};
    printTuple(a);
    cout << endl;
}