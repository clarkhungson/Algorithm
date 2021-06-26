#include <stdio.h>
#include <iostream>
#include <cstdint>
#include <vector>

#define MAX_SIZE 1000


int64_t ham_mu(int a, int n) {
	static std::vector<int> values(MAX_SIZE, 0);
	if (values[n] != 0) {
		return values[n];
	}
	if (n == 0) {
		return 1;
	}
	if (n == 1) {
		return a;
	} else if (n % 2 == 0) {
		auto value = ham_mu(a, n / 2) * ham_mu(a, n / 2);
		values[n] = value;
		return value;
	} else {
		auto value = ham_mu(a, n / 2) * ham_mu(a, n / 2) * a;
		values[n] = value;
		return value;
	}
}

int main() {
    int a = 2;
    int n = 13;
//    std::cout << ham_mu(a, n);
    for (int i = 0; i < 50; ++i) {
    	std::cout << ham_mu(a, i) << std::endl;
	}
    return 0;
}
