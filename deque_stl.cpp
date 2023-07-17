#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

void printKMax(int arr[], int n, int k){
    deque<int> arr_deque(arr, arr + k);
    auto max = max_element(arr_deque.begin(), arr_deque.end());

    cout << *max << ' ';
    for (int i = 1; i < n - k + 1; i ++) {
        if (max != arr_deque.begin()) {
            arr_deque.push_back(arr[i + k - 1]);
            arr_deque.pop_front();
            if (arr_deque.back() > *max) {
                cout << arr_deque.back() << ' ';
                max = arr_deque.end() - 1;
            } else {
                cout << *max << ' ';
            }
        } else {
            arr_deque.push_back(arr[i + k - 1]);
            arr_deque.pop_front();
            max = max_element(arr_deque.begin(), arr_deque.end());
            cout << *max << ' ';
        }
    }
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    while(t>0) {
        int n,k;
        cin >> n >> k;
        int i;
        int arr[n];
        int input;
        for(i=0;i<n;i++)
            cin >> arr[i];
        printKMax(arr, n, k);
        t--;
    }
    return 0;
}