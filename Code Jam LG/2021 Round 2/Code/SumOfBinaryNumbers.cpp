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
int x;

void solve() {
	cin >> n;
	cin >> x;
	int vv;
//	vector<int> v;
	unordered_map<int, long> data;
	for (int i = 0; i < n; ++i) {
		cin >> vv;
//		v.push_back(vv);
		auto it = data.find(vv);
		if (it != data.end()) {
			it->second++;
		} else {
			data.emplace(vv, 1);
		}
	}
//	sort(v.begin(), v.end());
	
	long count1 = 0;
	long count2 = 0;
	for (const auto& e : data) {
		int a = e.first;
		int b = x ^ a;
//		cout << "a: " << a << endl;
//		cout << "b: " << b << endl;
		if (a == b) {
			count1 += e.second * (e.second - 1) / 2;
		} else {
			auto it = data.find(b);
			int number_b = 0;
			if (it != data.end()) {
				number_b = it->second;
			}
			count2 += e.second * number_b;
		}
	}
	
	long count = count1 + count2 / 2;
	
	cout << count << endl;
	
}

int main() {
    cin >> T;
    while (T > 0) {
        solve();
        T--;
    }
	return 0;
}

