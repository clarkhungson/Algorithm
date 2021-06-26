#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>

using namespace std;

int T;
long long a;
long long b;
long long c;

long long count_digit(long long number) {
   return floor(log10(number) + 1);
}

void solve() {
	scanf("%lld", &a);
	scanf("%lld", &b);
	scanf("%lld", &c);
	long long initial_digits = count_digit(a);

	// c small or equal than a size
	if (c <= initial_digits) {
		long long r =  (long long)(a / pow(10, initial_digits - c ));
		printf("%lld\n", r % 10);
		return;
	}
	
	long long count = 0; // digital_count
	long long i = 1; // staring i
	while (true) {
		long long number = a + (i - 1) * b;
		long long max_same_digitals_size = pow(10, count_digit(number)) - 1;	
		long long j = (long long)(max_same_digitals_size - a) / b + 1;

		long long count_tmp = count + (j - i + 1) * count_digit(number);
		if (count_tmp >= c) {
			i--;
			break;
		}
		count = count_tmp;
		i = j + 1;
	}
	
	long long current_digits = count_digit(a + (i) * b);
	long long left_digits = c - count;
	
	long long x = left_digits / current_digits;
	long long y = left_digits % current_digits;

	if (y == 0) {
		y = current_digits;
	} else {
		x++;
	}

	// find digit y (th) of number (i + x) (th)
	long long N = a + (i + x - 1) * b;
	long long r =  (N / (long long)pow(10, current_digits - y ));
	printf("%lld\n", r % 10);

}

int main() {
    cin >> T;
    while (T > 0) {
        solve();
        T--;
    }
	return 0;
}

