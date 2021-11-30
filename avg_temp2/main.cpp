#include <iostream>
#include <vector>
using namespace std;

int main() {
	int K;
	cin >> K;
	vector<int> t(K);
	long long s=0;
	for (int& t_i: t) {
		cin >>t_i;
		s+=t_i;
	}
	int avg = s / K;
	int cnt = 0;
	for (const int& t_i: t) {
		if (t_i > avg) {
			cnt++;
		}
	}
	cout << cnt << endl;
	for (size_t i=0; i<t.size(); i++) {
			if (t[i] > avg) {
				cout << i << " ";
			}
		}
	return 0;
}
