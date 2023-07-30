#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    int Q, x, y;
	set<int> s;
	cin >> Q;
	for (int i=0; i<Q; i++) {
		cin >> y >> x;
		switch(y) {
			case 1:
				s.insert(x);
				break;
			case 2:
				s.erase(x);
				break;
			case 3:
				set<int>::iterator it;
				it = s.find(x);
				if (it != s.end()) cout << "Yes" << endl;
				else cout << "No" << endl;
				break;
		}
	}
    return 0;
}