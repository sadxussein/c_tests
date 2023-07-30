#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> arr(n);

    for (int i = 0; i < n; i++) {
        int tmp, len;
        cin >> len;
        arr[i].resize(len);
        for (int j = 0; j < len; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < q; i++) {
        int m, n;
        cin >> n >> m;
        cout << arr[n][m] << endl;
    }

    return 0;
}