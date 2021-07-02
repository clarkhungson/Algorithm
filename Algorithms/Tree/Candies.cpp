// https://lqdoj.edu.vn/problem/querysum
// https://vnoi.info/wiki/algo/data-structures/fenwick.md
// build & run: g++ -o Candies Candies.cpp -std=c++11; ./Candies

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>
using namespace std;

int N;
int Q;

vector<int64_t> a;

vector<int64_t> bit;

int64_t getSum(int64_t p) {
    int64_t idx = p, ans = 0;
    while (idx > 0) {
        ans += bit[idx];
        idx -= (idx & (-idx));
    }
    return ans;
}

void update(int64_t u, int64_t v) {
    int64_t idx = u;
    while (idx <= bit.size()) {
        bit[idx] += v;
        idx += (idx & (-idx));
    }
}

int type; // 1  pi xi, 2  ui vi

void solve() {
    cin >> type;
    if (type == 1) {
        int64_t p;
        int64_t x;
        cin >> p;
        cin >> x;
        update(p, x);
    } else {
        int64_t u;
        int64_t v;
        cin >> u;
        cin >> v;
        int64_t ans;
        if (u <= 1) {
            ans = getSum(v);
        } else {
            ans = getSum(v) - getSum(u - 1);
        }
        cout << ans << endl;
    }
}

int main() {
    cin >> N;
    cin >> Q;
    int64_t val;
    a.push_back(0);
    for (int64_t i = 0; i < N; ++i) {
        cin >> val;
        a.push_back(val);
    }
    bit.resize(a.size());

    // cout << "a:" << endl;
    // for (int i = 1; i < a.size(); i++) {
    //     cout << a[i] << " ";
    // }
    // cout << endl << "-----" << endl;

    // fill bit
    for (int64_t i = 1; i < a.size(); i++) {
        for (int64_t j = i; j > i - (i & (-i)); j--) {
            bit[i] += a[j];
            // cout << "i : " << i << ", plus j: " << j << endl;
        }
    }

    // cout << "bit.size():" << bit.size() <<  endl;
    // for (int i = 1; i < bit.size(); i++) {
    //     cout << bit[i] << " ";
    // }
    // cout << endl << "-----" << endl;

    while (Q > 0) {
        solve();
        Q--;
    }

    return 0;
}
