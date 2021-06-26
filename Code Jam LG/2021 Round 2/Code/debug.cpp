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
   return (long long)(log10(number) + 1);
}

void solve() {
	cin >> a;
	cin >> b;
	cin >> c;

	long long initial_digits = count_digit(a);

	// c small
	if (c <= initial_digits) {
		int r =  (a / pow(10, initial_digits - c ));
		cout << r % 10 << endl;
		return;
	}
	
	long long count = 0;
	long long i = 1;
	while (true) {
//		cout << "---------------" << endl;
//		cout << "i: " << i << endl;
		long long number = a + (i - 1) * b;
//		cout << "number: " << number <<endl;
//		cout << "count_digit(number)): " << count_digit(number) << endl;
		long long max = pow(10, count_digit(number)) - 1;	
		long long j = (max - a) / b + 1;
//		cout << "j: " << j << endl;
		
		long long t = count + (j - i + 1) * count_digit(number);
		if (t >= c) {
			i--;
			break;
		}
		
//		count += (j - i + 1) * count_digit(number);
		count = t;
//		cout << "count end: " << count << endl;
		i = j + 1;
	}
//	cout << "count: " << count << endl;
//	cout << "i: " << i << endl;
	
	long long current_digits = count_digit(a + (i) * b);
	long long left_digits = c - count;
	
//	cout << "current_digits: " << current_digits << ", left_digits: " << left_digits << endl;
	
	long long x = left_digits / current_digits;
	long long y = left_digits % current_digits;
	
//	cout << "before: x " << x << ", y : " << y << endl;
	
	if (y == 0) {
		y = current_digits;
	} else {
		x++;
	}
	
//	cout << "after: x << " << x << ", y : " << y << endl;
	
	// find digit y of number i + x
	long long N = a + (i + x - 1) * b;
//	cout << "N: " << N << endl;
	long long r =  (N / pow(10, current_digits - y ));
//	cout << "r: " << r << endl;
	cout << r % 10 << endl;
	
}

int solve(long long a, long long b, long long c) {

	long long initial_digits = count_digit(a);

	// c small
	if (c <= initial_digits) {
		int r =  (a / pow(10, initial_digits - c ));
		return r % 10;
	}
	
	long long count = 0;
	long long i = 1;
	while (true) {
//		cout << "---------------" << endl;
//		cout << "i: " << i << endl;
		long long number = a + (i - 1) * b;
//		cout << "number: " << number <<endl;
//		cout << "count_digit(number)): " << count_digit(number) << endl;
		long long max = pow(10, count_digit(number)) - 1;	
		long long j = (max - a) / b + 1;
//		cout << "j: " << j << endl;
		
		long long t = count + (j - i + 1) * count_digit(number);
		if (t >= c) {
			i--;
			break;
		}
		
//		count += (j - i + 1) * count_digit(number);
		count = t;
//		cout << "count end: " << count << endl;
		i = j + 1;
	}
//	cout << "count: " << count << endl;
//	cout << "i: " << i << endl;
	
	long long current_digits = count_digit(a + (i) * b);
	long long left_digits = c - count;
	
//	cout << "current_digits: " << current_digits << ", left_digits: " << left_digits << endl;
	
	long long x = left_digits / current_digits;
	long long y = left_digits % current_digits;
	
//	cout << "before: x " << x << ", y : " << y << endl;
	
	if (y == 0) {
		y = current_digits;
	} else {
		x++;
	}
	
//	cout << "after: x << " << x << ", y : " << y << endl;
	
	// find digit y of number i + x
	long long N = a + (i + x - 1) * b;
//	cout << "N: " << N << endl;
	long long r =  (N / pow(10, current_digits - y ));
//	cout << "r: " << r << endl;
	return r % 10;
	
}

int main() {
//    cin >> T;
//    while (T > 0) {
//        solve();
//        T--;
//    }

	  long long a = 102322;
	  long long b = 1334242;
	  int C = 0;
	for (int i = 1; i < 160; i++) {
		long long number = a + (i - 1) * b;
		C += count_digit(number);
		cout << number;
	}
	cout << endl;
	for (long long c = 1; c <= C; c++) {
		cout << solve(a, b, c);
	}

	return 0;
}

