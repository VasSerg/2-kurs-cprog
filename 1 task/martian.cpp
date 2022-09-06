#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>
using namespace std;

int main()
{
	string name;
	int price;
	string  back;
	int maxTemp;
	cout << "Product's name: ";
	cin >> name;
	cout << "Product's price Is cash: ";
	cin >> price;
	cout << "Is cash-back available for this product ? (true/false): ";
	cin >> back;
	cout << "Maximum storing temperature: ";
	cin >> maxTemp;
	stringstream priceHex;
	
	priceHex << hex << price;
	string ph(priceHex.str());
	transform(ph.begin(), ph.end(), ph.begin(), ::toupper);
	string zeros = "";
	for (int i = 0; i < 8 - ph.length(); i++){
		zeros += "0";}
	ph = zeros + ph;
	cout << name << "\n";
	cout << right  << setfill('.') << "Price: " << setw(20) << ph << endl;
	cout << right  << setfill('.') << "Has cash-back: " << setw(20 - 8) << back << endl;
	cout << right  << setfill('.') << "Max temperature: " << setw(20 -12)<<  "+" << maxTemp << endl;
	cout << "\n";
}
