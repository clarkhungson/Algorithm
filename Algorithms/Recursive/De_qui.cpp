#include <stdio.h>
#include <iostream>
#include <cstdint>
#include <vector>

#define MAX_SIZE 1000

std::vector<int128_t> values(MAX_SIZE, 0);


int64_t fibonaci(int n) {
	if(values[n] != 0) {
		return values[n];
	}
	if (n==1 || n==2) {
		return 1;
	}
	int64_t value = fibonaci(n-1) + fibonaci(n-2);
	values[n] = value;
	return value;
}

int main() {
    for (int i=1; i < 100; ++i){
    	std::cout << fibonaci(i) << ", ";
	}
    return 0;
}

