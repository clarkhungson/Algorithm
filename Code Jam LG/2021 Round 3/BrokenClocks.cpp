// https://codejam.lge.com/contest/problem/672/3
// build: 

// g++ -o BrokenClocks BrokenClocks.cpp -std=c++11 && BrokenClocks

#include <iostream>
#include <vector>
using namespace std;
#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>

/*
6
3
11:12:00 11:12:20 11:12:40
4 2 0
2
00:00:00 23:59:59
1 1
2
00:00:00 00:00:00
90000 3600
2
11:00:00 11:00:00
1 -1
3
11:00:00 11:00:00 23:00:00
1 -1 0
3
15:19:59 16:07:49 15:44:54
966 392 667
*/


const int M = 86400;

// 11:00:00
int64_t getValue(string s) {
    int64_t ans = 0;
    int h = (s[0] - '0') * 10 + (s[1] - '0');
    int m = (s[3] - '0') * 10 + (s[4] - '0');
    int second = (s[6] - '0') * 10 + (s[7] - '0');
    ans = h * 60 * 60 + m * 60 + second;
    
    return ans;
}

struct Line {
    int64_t a;
    int64_t b;
    Line(int64_t aa, int64_t bb) : a(aa), b(bb) {}
};

void cal(int n, const vector<string>& t, vector<int>& d) {

    vector<int64_t> val(n, 0);
    for (int i = 0; i < n; ++i) {
        int64_t v = getValue(t[i]) % M;
        val[i] = v;
    }

    // for (int i = 0; i < n; i++) {
    //     cout << val[i] << " ";
    // }
    // cout << endl;

    for (int i = 0; i < d.size(); i++) {
        // cout << "begin d[i]: " << d[i] << endl;
        if (d[i] >= 0) {
            d[i] = d[i] % M;
        } else {
            d[i] += ((-d[i]) / M + 2) * M;
            d[i] = d[i] % M;
        }
        // cout << "end d[i]: " << d[i] << endl;
    }

    // for (int i = 0; i < n; i++) {
    //     cout << d[i] << " ";
    // }
    // cout << endl;

    // normalize
    vector<Line> lines;
    unordered_map<int, int> m;
    bool nerver_cut = false;
    for (int i = 0; i < d.size(); i++) {
        if (m.count(d[i])) {
            // cout << "i: " << i << ". Got d[i]: " << d[i] << ", val[i]: " << val[i] << endl;
            if (m[d[i]] != val[i]) {
                // cout << "not equal" << endl;
                nerver_cut = true;
                break;
            }
        } else {
            m[d[i]] = val[i];
            lines.push_back(Line(val[i], d[i]));
            // cout << "line push back: " << val[i] << ", " << d[i] << endl;
        }
    }

    // all line never get in same time
    if (nerver_cut == true || lines.size() == 0) {
        cout << "0" << endl;
        return;
    }

    int ans = 0;

    // for (int i = 0; i < lines.size(); i++) {
    //     cout << lines[i].a << ", " << lines[i].b << endl;
    // }
    // cout << endl;

    for (int i = 1; i <= M; i++) {
        int64_t f0 = ((int64_t)(lines[0].a + i * lines[0].b)) % M;
        bool flag = true;
        if (i == M / 2) {
            // cout << "line0: " << lines[0].a << ", " << lines[0].b << endl;
            // cout << "f0: " << f0 << endl;
            // cout << "line0: " << lines[1].a << ", " << lines[1].b << endl;
            // cout << "f(1): " << ((int64_t)(lines[1].a + i * lines[1].b)) % M << endl;
            // cout << "f0 - f1: " << abs((lines[1].a + i * lines[1].b) % M - f0) << endl;
        }
        for (int j = 1; j < lines.size(); j++) {
            if (f0 != ((lines[j].a + i * lines[j].b) % M)) {
                flag = false;
                break;
            }
        }
        // cout << "i: " << i << endl;
        if (flag == true) {
            // cout << "ii: " << i << endl;
            ans++;
        }

    }


    cout << ans << endl;
}

// Recursive function to return gcd of a and b
int GCD(int a, int b)
{
    if (b == 0)
        return a;
    return GCD(b, a % b);
     
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<string> t(n);
        for (int i=0; i<n; i++) {
            cin >> t[i];
        }
        vector<int> d(n);
        for (int i=0; i<n; i++) {
            cin >> d[i];
        }
        // Insert code here

        cal(n, t, d);
        // End of insertion
    }
    return 0;
}
