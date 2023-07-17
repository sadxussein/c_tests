#include <iostream>
#include <deque>
using namespace std;

void printKMax(int arr[], int n, int k){
    for (int i = 0; i < n - k + 1; i ++) {
        deque<int> arr_deque(arr + i, arr + i + k);
        int max = 0;
        while (!arr_deque.empty()) {
            if (arr_deque.back() > arr_deque.front()) {
                max = arr_deque.back();
                arr_deque.pop_front();
            } else {
                max = arr_deque.front();
                arr_deque.pop_back();
            }
        }
        cout << max << ' ';
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