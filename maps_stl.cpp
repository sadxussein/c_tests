#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    int Q, c, mark;
	string name;
	map<string, int> s;
	cin >> Q;
	for (int i=0; i<Q; i++) {
		cin >> c;
		switch(c) {
			case 1:
				cin >> name >> mark;
				s[name] += mark;
				break;
			case 2:
				cin >> name;
				s.erase(name);
				break;
			case 3:
				map<string, int>::iterator it;
				cin >> name;
				it = s.find(name);
				if (it != s.end()) cout << s[name] << endl;
				else cout << "0" << endl;
				break;
		}
	}
    return 0;
}