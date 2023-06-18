#include <iostream>
#include <string>

using namespace std;

int main()
{
	const int year = 2000;
	const int hcane = 3;
	const int equake = 5;
	const int tnado = 2;
	const int pandemic = 20;
	cout << "What is the current year? ";
	int curyear;
	cin >> curyear;
	int diff = curyear - year;

	cout << "Bob has been on the island for " << diff << " years. Since then:" << endl;
	cout << "Bob has gone through " << diff / hcane << " hurricanes. The next hurricane is in the year " << curyear + (hcane - diff % hcane) << endl;
	cout << "Bob has gone through " << diff / equake << " earthquakes. The next earthquakes is in the year " << curyear+(equake-diff%equake) << endl;
	cout << "Bob has gone through " << diff / tnado << " tornadoes. The next tornadoes is in the year " << curyear+(tnado-diff%tnado) << endl;
	cout << "Bob has gone through " << diff / pandemic << " pandemics. The next pandemic is in the year " << curyear+(pandemic-diff%pandemic) << endl;
	cout << "Villagers want to buy Bobs potatoes, how many do they want? " << endl;
	int potato;
	cin >> potato;
	int crate, sack, basket, single;
	crate = potato / 50;
	potato %= 50;
	sack = potato / 20;
	potato %= 20;
	basket = potato / 6;
	potato %= 6;
	single = potato / 1;
	cout << "The villagers will need to carry " << crate << " crates " << sack << " sacks " << basket << " baskets and " << single << " single potatos carried by his pet donkey.";
	return 0;
}


