#include <iostream>
using namespace std;
int main()
{
	int num;
	int value;
	cout << "Please choose what unit of measurement do you want to transfer. Type one of the following numbers:" << endl;
	cout << "1. Mass in kilogramms to weight in Newtons." << endl;
	cout << "2. Time in hours to time in minutes." << endl;
	cout << "3. Energy in Joules to energy in electronvolts" << endl;
	cin >> num;
	cout << "Please enter your value" << endl;
	cin >> value;
	switch (num) {
	default:
		cout << "You have choosen wrong number";
		break;

	case 1: 
		cout << value * 9.81;
		break;
	case 2: 
		cout << value * 60;
		break;
	case 3: 
		cout << value * 6.242e+18;
		break;

	}
	cout << "\n" ;
}