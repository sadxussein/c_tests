#include <cmath>
#include <cstdio>
#include <sstream>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N;
	vector<int> vec;	
	string input;
	cin >> N;
	cin.ignore();
	getline(cin, input);
	stringstream ss(input);
	int num;
	while (ss >> num) {
		vec.push_back(num);
	}
	sort(vec.begin(), vec.end());
	for (auto n : vec) {
		cout << n << ' ';
	}
    return 0;
}
