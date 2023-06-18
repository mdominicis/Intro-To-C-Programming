#include <iostream>
#include <vector>

using namespace std;

int maximum(vector <int> v);
int findIt(int x, vector <int> v);
void deleteLast(vector <int> v);

int main() {
	int num;
	cout << "How many elements do you want to store? ";
	cin >> num;
	vector <int> v(num);
	for (int i = 0; i < num; i++) {
		int response = 0;
		cout << "Enter a element: ";
		cin >> response;
		v[i] = response;
	}
	cout << "The largest inputted value was " << maximum(v) << " and it occured " << findIt(maximum(v), v) << " time(s)." << endl;;
	deleteLast(v);
}

int maximum(vector <int> v){
	int max = v.at(0);
	for (int i = 0; i < v.size(); i++) {
		if (max < v.at(i)) {
			max = v.at(i);
		}
	}
	return max;
}
int findIt(int x,vector <int> v){
	int count = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v.at(i) == x) {
			count++;
		}
	}
	return count;
}
void deleteLast(vector <int> v){
	v.pop_back();
	for (int i = 0; i < v.size(); i++) {
		cout << v.at(i) << " ";
	}
}