#include <iostream>
#include <vector>
using namespace std;

int main() {
	uint64_t cnt, rho, W, H, D;
	cin >> cnt >> rho;
	uint64_t M = 0;
	for (unsigned int i=0; i<cnt; i++) {
		cin >> W >> H >> D;
		M += rho*W*H*D;
	}
	cout << M;
}
