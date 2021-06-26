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
int n;
vector<int> primes;

void solve() {
	cin >> n;
	vector<int> x;
	int xx;
	for (int i = 0; i < n; ++i) {
		cin >> xx;
		x.push_back(xx);
	}
	
	sort(x.begin(), x.end());
	
//	cout << "x array:" << endl;
//	for (auto e : x) {
//		cout << e << " ";
//	}
//	cout << endl;
	
	int min = 9999999;
	for (int i = 0; i < primes.size() - 1 - n; i++) {
		int sum = 0;
		for (int j = 0; j < n; ++j) {
			sum += abs(x[j] - primes[i + j]);
		}
//		if (i < 30) {
//			cout << "i: " << i << "sum: " << sum << endl;
//		}	
		if (sum < min) {
			min = sum;
		}
	}
	cout << min << endl;
}

int main() {
	primes.push_back(2);
	primes.push_back(3);
	primes.push_back(5);
	for (int i = 6; i < 100000; ++i) {
		bool isPrime = true;
		for (int j = 2; j <= sqrt(i); ++j) {
			if (i % j == 0) {
				isPrime = false;
				break;
			}
		}
		if (isPrime) {
			primes.push_back(i);
		}
	}
	
//	cout << "primes:" << endl;
//	for (int i = 0; i < 30; i++) {
//		cout << primes[i] << " ";
//	}

    cin >> T;
    while (T > 0) {
        solve();
        T--;
    }
	return 0;
}

