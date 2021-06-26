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
vector<int> x(10, 0);

void solve() {
	// Input x[i]
	for (int i = 1; i <= 9; ++i) {
		cin >> x[i];
	}
	int n = 0;
	
	// Target max number
	string max_number;
	x[9] = x[6] + x[9];
	x[6] = 0;
	for (int i = 9; i >= 1; --i) {
		for (int j = 0; j < x[i]; ++j) {
			max_number += '0' + i;
		}
		n += x[i];
	}
//	cout << "max: " << max_number << endl;
	
	// Find inital number
	vector<char> inital_number(n, 0);
	for (int i = 0; i < n; ++i) {
		if (i % 2 == 0) {
			inital_number[i / 2] = max_number[i];
//			cout << "chan: i = " << i << ", at : " << i / 2 << endl;
//			cout << "inital_number of " << i / 2 << " = " << inital_number[i / 2] << endl;
		} else {
			inital_number[n - 1 - (i - 1) / 2] = max_number[i];
//			cout << "le: i = " << i << ", at : " << n - 1 - (i - 1) / 2 << endl;
//			cout << "inital_number of " << n - 1 - (i - 1) / 2 << " = " << inital_number[n - 1 - (i - 1) / 2] << endl;
		}
	}
//	if (n % 2 == 1) {
//		inital_number[n / 2 + 1]= max_number[n / 2 + 1];
//	}
	
//	cout << "inital: " << endl;
	for (int i = 0; i < n; ++i) {
		cout << inital_number[i] << " ";
	}
	cout << endl;
}

int main() {
    cin >> T;
    while (T > 0) {
        solve();
        T--;
    }

}

