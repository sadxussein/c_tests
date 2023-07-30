#include <cmath>
#include <cstdio>
#include <sstream>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N;
	cin >> N;
	vector<int> vec(N);
	for (int i=0; i<N; i++) {
		cin >> vec[i];
	}
	int e;
	cin >> e;
	vec.erase(vec.begin()+e-1);
	cout << vec.size() << endl;
	for (auto n: vec) {
		cout << n << ' ';
	}
	int ee;
	cin >> e >> ee;
	vec.erase(vec.begin()+e-1, vec.begin()+ee-1);	
	cout << vec.size() << endl;
	for (auto n: vec) {
		cout << n << ' ';
	}
    return 0;
}
