#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while(T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;
		
		long long dec_A = A;
		cout << resetiosflags(ios::uppercase) << setw(0);
		cout << showbase << hex << dec_A << endl;
		cout << setw(15) << setfill('_')
			 << internal << showpos << right
			 << setprecision(2) << fixed << B << endl;
		cout << scientific << setprecision(9) << resetiosflags(ios::showpos) << uppercase << C << endl;
	}
	return 0;
}