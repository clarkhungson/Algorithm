// https://codejam.lge.com/problem/19597

// build: g++ -o StringReversal StringReversal.cpp -std=c++11 && StringReversal

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
int N;

/*

1 ≤ T ≤ 50
2 ≤ N ≤ 150
2 ≤ Length (S[i]) ≤ 20
For every i ≠ j, Reverse(S[i]) ≠ S[j] and S[i] ≠ S[j] always hold.
For each test case, there always exists at least one Reversal String that sorts the input strings in lexicographic order.

TC:

2
5
CAA
DAA
EAA
DBA
AAD
3
ABC
XC
DZ

*/

// string reverse(string s) {
//     return reverse(s.begin(), s.end());
// }

string reverse(string str)
{
    int n = str.length();
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
    return str;
}

void solve() {
    // input
	cin >> N;
    vector<string> s;
    string ss;
    for (int i = 0; i < N; ++i) {
        cin >> ss;
        s.push_back(ss);
    }

    // process
    string ans = "0";

    for (int i = 1; i < N; ++i) {
        // if current string lager than or equal previous string, then put a '0'
        if (s[i] >= s[i - 1]) {
            ans += "0";
            continue;
        }

        // if not, then revert previous string
        if (reverse(s[i]) < s[i - 1]) {
            s[i - 1] = reverse(s[i - 1]);
            ans[i - 1] = (ans[i - 1] == '1') ? '0' : '1';
        }

        // check if need to revert current string or NOT
        if (s[i - 1] > s[i]) {
            s[i] = reverse(s[i]);
            ans += '1';
        } else {
            ans += '0';
        }
    
        // check previous strings need to revert or NOT
        if (i == 1) {
            continue;
        }
        for (int j = i - 1; j > 0; j--) {
            if (s[j] < s[j - 1]) {
                s[j - 1] = reverse(s[j - 1]);
                ans[j - 1] = (ans[j - 1] == '1') ? '0' : '1';
            }
        }
    }
    
    cout << ans << endl;
}

int main() {
    cin >> T;
    while (T > 0) {
        solve();
        T--;
    }
}
