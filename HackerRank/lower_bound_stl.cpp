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
	int Q;
	cin >> Q;
	for (int i=0; i<Q; i++) {
		int q;
		vector<int>::iterator lb;
		cin >> q;
		lb = lower_bound(vec.begin(), vec.end(), q);
		if (*lb == q) cout << "Yes ";
		else cout << "No ";
		cout << lb-vec.begin()+1 << endl;
	}
    return 0;
}
