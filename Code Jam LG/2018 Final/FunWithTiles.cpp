// https://codejam.lge.com/problem/16201

// build: g++ -o FunWithTiles FunWithTiles.cpp -std=c++11 && FunWithTiles

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>
using namespace std;

/*

4 5 6
1 2
1 3
3 1
4 3
4 4
4 5

1 3 0


*/

struct Point {
    int x;
    int y;
    Point(int xx, int yy) : x(xx), y(yy) {}
};

void solve() {
	int R;
    int C;
    int k;
    scanf("%d", &R);
    scanf("%d", &C);
    scanf("%d", &k);

    vector<Point> x;
    int x1;
    int x2;
    for (int i = 0; i < k; i++) {
        scanf("%d", &x1);
        scanf("%d", &x2);
        x.push_back(Point(x1, x2));
    }

    unordered_map<int, vector<int>> m;

    for (auto e : x) {
        auto it = m.find(e.x);
        if (it != m.end()) {
            it->second.push_back(e.y);
        } else {
            m.emplace(e.x, vector<int>{e.y});
        }
        // m[e.x].push_back(e.y);
    }

    for (auto e : m) {
        sort(e.second.begin(), e.second.end());
    }

    int64_t sum1 = 1;
    int64_t tile1 = 0;
    int64_t no_full_fill_tile = R - m.size();
    if (C % 2 == 1) {
        for (int i = 0; i < no_full_fill_tile; i++) {
            sum1 *= (C / 2) + 1 ;
            sum1 = sum1 % 1000000007;
        }
    } else {
        // sum1 += 1;
        // sum1 = sum1 % 1000000007;
    }

    tile1 = (C / 2) * no_full_fill_tile;

    int64_t sum2 = 1;
    int tile2 = 0;

    for (auto e : m) {
        auto& row = e.second;
        if (row[0] >= 3) {
            // cout << "a" << endl;
            if ((row[0] - 1) % 2 == 0) {
                // cout << "a1" << endl;
                // sum2++;
            } else {
                // cout << "a2" << endl;
                sum2 *= (row[0] - 1) / 2 + 1;
            }
            tile2 += (row[0] - 1) / 2;
        }
        for (int i = 1; i < row.size(); i++) {
            //  cout << "b" << endl;
            int val = row[i] - row[i - 1];
            if (val >= 2) {
                if (val % 2 == 0) {
                    // sum2++;
                } else {
                    sum2 *= val / 2 + 1;
                }
            }
            tile2 += (val / 2);
        }
        if (C - row.back() >= 2) {
            //  cout << "c" << endl;
            if ((C - row.back()) % 2 == 0) {
                // sum2++;
            } else {
                sum2 *= (C - row.back()) / 2 + 1;
            }
            tile2 += (C - row.back()) / 2;
        }
        sum2 = sum2 % 1000000007;
    }

    // cout << "sum1: " << sum1 << endl;
    // cout << "sum2: " << sum2 << endl;

    int64_t ans = 0;

    ans = (sum1 * sum2) % 1000000007;

    // cout << "tile1: " << sum1 << endl;
    // cout << "tile2: " << sum2 << endl;

    int64_t tile = tile1 + tile2;

    cout << tile << " " << ans << endl;
}

int main() {
    solve();
}
