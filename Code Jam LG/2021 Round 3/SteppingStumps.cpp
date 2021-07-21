// https://codejam.lge.com/contest/problem/672/4
// build: 

// 
/*

g++ -o SteppingStumps SteppingStumps.cpp -std=c++11 && SteppingStumps

*/

#include <iostream>
#include <vector>
using namespace std;
#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>

#include <iostream>
#include <vector>
using namespace std;

void cal(int n, vector<int>& h, vector<int>& r) {
    int MIN_idx = -1;
    int MAX_idx = -1;
    int MIN_val = INT_MAX;
    int MAX_val = 0;

    for (int i = 0; i < n; i++) {
        if (h[i] > MAX_val) {
            MAX_val = h[i];
            MAX_idx = i;
        }
        if (h[i] < MIN_val) {
            MIN_val = h[i];
            MIN_idx = i;
        }
    }

    // go through all cases

    bool f0 = false;

    for (int i = 0; i < pow(2, n) - 1; ++i) {

        vector<int> left;
        vector<int> right;
        for (int j = 0; j < n; j++) {  // j: index of element
            if (j == MIN_idx || j == MAX_idx) {
                continue;
            }
            // cout << "i: " << i << ", j: " << j << endl;
            int check = i & (1 << j);
            // cout << "check: " << check << endl;
            if (check != 0) {
                // cout << "1. push: " << j << endl;
                left.push_back(j);
            } else {
                // cout << "2. push: " << j << endl;
                right.push_back(j);
            }
        }

        if (right.empty()) {
            continue;
        }

        // cout << "*** i: " << i << endl;
        sort(left.begin(), left.end(), [&](int a, int b) {
            return h[a] < h[b];
        });
        // for (auto e : left) {
        //     cout << e << " ";
        // }
        // cout << endl;

        sort(right.begin(), right.end(), [&](int a, int b) {
            return h[a] > h[b];
        });
        // for (auto e : right) {
        //     cout << e << " ";
        // }
        // cout << endl;


        vector<int> idx;
        idx.push_back(MIN_idx);
        for (auto e : left) {
            idx.push_back(e);
        }
        idx.push_back(MAX_idx);
        for (auto e : right) {
            idx.push_back(e);
        }

        bool flag = true;
        for (int i = 0; i < idx.size() - 1; i++) {
            if (h[idx[i]] == h[idx[i + 1]]) {
                flag = false;
                break;
            }
        }

        if (flag == false) {
            continue;
        }

        // cout << "-------------------------- i: " << i <<  endl;
        // cout << "idx" << endl;
        // for (auto e : idx) {
        //     cout << e << " ";
        // }
        // cout << endl;


        // cout << "h" << endl;
        // for (auto e : idx) {
        //     cout << h[e] << " ";
        // }
        // cout << endl;

        // cout << "r" << endl;
        // for (auto e : idx) {
        //     cout << r[e] << " ";
        // }
        // cout << endl;

        int inc = (r[idx[0]] < r[idx[1]]) ? 1 : -1;

        if (r[idx[0]] == r[idx[1]]) {
            continue;
        }

        bool f = true;
        // cout << "inc: " << inc << endl;
        // cout << "inc: " << inc << endl;
        // cout << "inc: " << inc << endl;
        for (int i = 1; i < idx.size() - 1; i++) {
            if ((inc == 1) && r[idx[i]] <= r[idx[i + 1]]) {
                f = false;
                // cout << "error, i: " << i << endl;
                break;
            } else if ((inc == -1) && r[idx[i]] >= r[idx[i + 1]]) {
                f = false;
                //  cout << "error, i: " << i << endl;
                break;
            }
            inc = -inc;
        }

        if (f == true) {
            for (auto e : idx) {
                cout << e + 1 << " ";
            }
            cout << endl;
            f0 = true;
            break;
        }

    }
    if (f0 == false) {
        cout << "-1" << endl;
    }

}   


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> h(n);
        for (int i=0; i<n; i++) {
            cin >> h[i];
        }
        vector<int> r(n);
        for (int i=0; i<n; i++) {
            cin >> r[i];
        }

        // Insert code here

        cal(n, h, r);
        // End of insertion
    }
    return 0;
}

