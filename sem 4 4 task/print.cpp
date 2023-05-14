#include <functional>
#include <iostream>

using namespace std;

void Print() {}

template<typename Head, typename... Tail>
void Print(Head&& head, Tail&&... tail) {
	cout << head << "  ";
	Print(forward<Tail>(tail)...);
}

int main() {
	string str = "Yes";
	int a = 3;
	const int& s = 12;
	Print(a, str, s, move(str));
}

