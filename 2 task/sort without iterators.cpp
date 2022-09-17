#include <iostream>
#include <vector>
using namespace std;
int main() {
	int size;
	int inp;
	int i;
	int key;
	vector<int> v;
	cout << "Please write your vector's size: " << endl;
	cin >> size;
	cout << "Please write your vector: " << endl;

	for (int i = 1; i <= size; i++) {
		cin >> inp;
		v.push_back(inp);
	}

	for (int j = 0; j <= size - 1; j++) {
		key = v[j];
		i = j - 1;
		while (i >= 0 and v[i] > key) {
			swap(v[i + 1], v[i]);
			i = i - 1;
		}
		v[i + 1] = key;
	}


	cout << "Sorted vector: ";
	for (auto i = v.begin(); i != v.end(); ++i)
		cout << *i << " ";

	cout << endl;
}