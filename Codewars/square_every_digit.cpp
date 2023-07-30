#include <iostream>

using namespace std;

int square_digits(int num) {
    if (num == 0) {
        return 0;
    }

    string num_str = to_string(num);
    string res, test;

    for (char c : num_str) {
        res += to_string(int(c - '0') * int(c - '0'));
    }

    return stoi(res);
}

int main() {
    int num;
    cin >> num;
    cout << square_digits(num) << endl;
    return 0;
}