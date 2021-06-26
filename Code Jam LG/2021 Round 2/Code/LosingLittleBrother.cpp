#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

int T;
string s;


// ALBERT
// ALICE

int score_ALBERT(int i) {
	char c = s[i];
	if (c == 'A' || c == 'L' || c == 'B' || c == 'E' || c == 'R' || c == 'T') {
		return 2;
	}
	return 0;
}

int score_ALICE(int i) {
	char c = s[i];
	if (c == 'A' || c == 'L' || c == 'I' || c == 'C' || c == 'E') {
		return 1;
	}
	return 0;
}

int memo[150][150][150];

// play(int m, int i, int j)
// return minimum value that > m in range (i, j)
// need to calculate play(0, n - 1)

int play(int m, int i, int j) {
	
	if (memo[i][j][m + 75] > -1) {
		return memo[i][j][m + 75];
	}
	
//	cout << "Play with i: " << i << ", j: " << j << ", m: " << m  << endl;
//	if (m < 0) {
//		return -10000;
//	}
	
	if (i == j) {
		if (score_ALBERT(i) > m) {
//			cout << "----value with i: " << i << ", j: " << j << ", IS:  " << score_ALBERT(i)  << endl;
			return score_ALBERT(i);
		} else {
//			cout << "----value with i: " << i << ", j: " << j << ", IS:  " << -1  << endl;
			return -999999;
		}
	}
	
	if (i == j - 1) {
		int v1 = score_ALBERT(i) - score_ALICE(j);
		int v2 = score_ALBERT(j) - score_ALICE(i);
		int v = -999999;
		if (v1 > m) {
//			cout << "***, v1: " << v1 << ", m: " << m << endl;
			v = v1;
		}
		if (v2 > m && v2 < v1) {
			v = v2;
//			cout << "***2, v1: " << v1 << ", m: " << m << endl;
		}
//		cout << "----value with i: " << i << ", j: " << j << ", IS:  " << v  << endl;
//		if (v < 0) {
//			v = -1;
//		}
		return v;
	}
	
	int value = -1;
	// case 1: ALBERT get j, remain: i ... j - 1
	int value1 = -1;
	int value2 = -1;
	if (score_ALBERT(i) == 2) {
//		cout << "x1" << endl;
		value1 = 2 - score_ALICE(j) + play(m - (2 - score_ALICE(j)), i + 1, j - 1);
		value2 = 2 - score_ALICE(i + 1) + play(m - (2 - score_ALICE(i + 1)), i + 2, j);
	} else if (score_ALBERT(j) == 2) {
//		cout << "x2" << endl;
		value1 = 2 - score_ALICE(j - 1) + play(m - (2 - score_ALICE(j - 1)), i , j - 2);
		value2 = 2 - score_ALICE(i + 1) + play(m - (2 - score_ALICE(i + 1)), i  + 2, j);
	} else {
//		cout << "x3" << endl;
		value1 = 0 - score_ALICE(j) + play(m - (2 - score_ALICE(j - 1)), i , j - 2);
		value2 = 0 - score_ALICE(i + 1) + play(m - (2 - score_ALICE(i + 1)), i  + 2, j);
	}
//	cout << "value1: " << value1 << ", value2: " << value2 << endl;
	if (value1 > m) {
		value = value1;
	}
	if (value2 > m && value2 < value1) {
		value = value2;
	}
	
	memo[i][j][m + 75] = value;

//	cout << "-----value with i: " << i << ", j: " << j << ", IS:  " << value  << endl;

	return value;
}

void solve() {
	memset(memo, -1, sizeof(memo));
	cin >> s;
	int n = (int)s.size();
	int result = 0;
	result = play(0, 0, n - 1);
	if (result < 0) {
		result = -1;
	}
	cout << result << endl;
}


int main() {
    cin >> T;
    while (T > 0) {
        solve();
        T--;
    }
	return 0;
}

