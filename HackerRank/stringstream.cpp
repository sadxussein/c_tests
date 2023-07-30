#include <sstream>
#include <vector>
#include <iostream>

using namespace std;

vector<int> parseInts(string str) {
	stringstream ss(str);
	vector<int> res;
	while(!ss.eof()) {
		string temp;
		getline(ss, temp, ',');
		res.push_back(stoi(temp));
	}
	return res;	
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}