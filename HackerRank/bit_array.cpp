#include <iostream>
#include <climits>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    auto m = static_cast<int64_t>(std::numeric_limits<int>::max());
    int n, s, p ,q;
    std::cin >> n >> s >> p >> q;
    int cnt{n - 1};
    int64_t t{s}, prev{t};
    int res{1};
    while(cnt--) {
        t = t * p + q;
        t &= m;
        if(t == prev) continue;
        prev = t;
        ++res;
    }
    std::cout << res;
    return 0;
}