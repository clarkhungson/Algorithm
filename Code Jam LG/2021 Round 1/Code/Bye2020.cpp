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

bool checkMeaning(int number) {
    if (number < 0) {
        return false;
    }

    int digits = (int)log10(number); 
    int firsts = (int)(number / pow(10, digits - 3)); 

	if (firsts == 2020) {
		return true;
	}
	return false;
}

void solve() {
	const int MODULE = 10000;
    cin >> n;

    std::unordered_map<int, vector<int>> data;

	// input integer numbers
	int d;
    for (int i = 0; i < n; ++i) {
    	cin >> d;
    	auto it = data.find(d % MODULE);
    	if (it != data.end()) {
    		it->second.push_back(d);
		} else {
			data.emplace(d % MODULE, vector<int>{d});
		}
	}
	
// 	cout << "data.size() : " << data.size() << endl;
	
	int count = 0;
	
	// count
    
    for (const auto& e : data) {
    	int lastDigits_1 = e.first;
		int lastDigits_2 = 2021 - lastDigits_1;
		if (lastDigits_2 < 0) {
			lastDigits_2 = 10000 + lastDigits_2;
		}
		if (lastDigits_2 >= 10000) {
			lastDigits_2 = lastDigits_2 - 10000;
		}
// 		cout << "lastDigits_1 : " << lastDigits_1 << endl;
// 		cout << "lastDigits_2 : " << lastDigits_2 << endl;
		
		auto it2 = data.find(lastDigits_2);
		if (it2 == data.end()) {
			continue;
		}
		const vector<int>& set1 = e.second;
		const vector<int>& set2 = it2->second;
// 		cout << "set1.size() : " << set1.size() << endl;
// 		cout << "set1.size() : " << set1.size() << endl;
		for (auto e1 : set1) {
			for (auto e2 : set2) {
				if (checkMeaning(e1 + e2)) {
					count++;
				}
			}
		}
	}
	
	cout << count / 2 << endl;

    
}

int main() {
    cin >> T;
    while (T > 0) {
        solve();
        T--;
    }
//	cout << (-2024) % 10 << endl;
}
