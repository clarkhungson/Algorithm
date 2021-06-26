#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int T;
string s;

void solve() {
    cin >> s;
    for (unsigned i = 0; i < s.size(); ++i) {
    	if ('6' == s[i]) {
    		s[i] = '9';
		}
	}
	sort(s.begin(), s.end());
	int64_t number1 = 0;
	int64_t number2 = 0;
	for (int i = s.size() - 1; i > 0; i -= 2) {
		int64_t try1;
		int64_t try2;
		int64_t try11;
		int64_t try22;

		try1 = number1 * 10 + (s[i] - '0');
		try2 = number2 * 10 + (s[i - 1] - '0');
		
		try11 = number1 * 10 + (s[i - 1] - '0');
		try22 = number2 * 10 + (s[i] - '0');
		
		if (try1 * try2 > try11 * try22) {
			number1 = try1;
			number2 = try2;
		} else {
			number1 = try11;
			number2 = try22;
		}
	}
	if (s.size() % 2 != 0) {
		if (number1 < number2) {
			number1 = number1 * 10 + (s[0] - '0');
		} else {
			number2 = number2 * 10 + (s[0] - '0');
		}
	}
	
	int64_t product = number1 * number2;
	cout << product << endl;
    
}

int main() {
    cin >> T;
    while (T > 0) {
        solve();
        T--;
    }
}
