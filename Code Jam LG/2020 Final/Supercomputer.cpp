// https://codejam.lge.com/problem/19594

// build: g++ -o Supercomputer Supercomputer.cpp -std=c++11 && Supercomputer

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

1 ≤ T ≤ 10
2 ≤ N ≤ 100,000
1 ≤ H[i], D[i] ≤ 1,000

TC:

4
3
2 4 6
3 5 8
3
4 9 1
10 9 20
3
4 3 5
2 1 3
5
8 1 2 6 2
8 9 6 2 1

*/

struct Data {
    int h;
    int d;
    Data(int hh, int dd) : h(hh), d(dd) {}
};

void solve() {
    // input
	cin >> N;
    vector<int> H;
    vector<int> D;
    int val;
    for(int i = 0; i < N; ++i) {
        scanf("%d", &val);
        H.push_back(val);
    }
    for(int i = 0; i < N; ++i) {
        scanf("%d", &val);
        D.push_back(val);
    }
    
    vector<Data> data;

    // sort by dateline, then update H, D
    for (int i = 0; i < N; i++) {
        data.push_back(Data(H[i], D[i]));
    }
    sort(data.begin(), data.end(), [](const Data& d1, const Data& d2) {
        return d1.d < d2.d;
    });

    for (int i = 0; i < N; i++) {
        H[i] = data[i].h;
        D[i] = data[i].d;
    }

    vector<int> sum(N, 0);
    sum[0] = H[0];
    for (int i = 1; i < N; i++) {
        sum[i] = sum[i - 1] + H[i];
    }

    // max_left, max_right contain MAX lately by left and right

    vector<int> max_left(N, 0);
    vector<int> max_right(N, 0);

    int MAX = INT_MIN;
    for (int i = 0; i < N; i++) {
        if (sum[i] - D[i] > MAX) {
            MAX = sum[i] - D[i];
        }
        max_left[i] = MAX;
    }


    MAX = INT_MIN;
    for (int i = N - 1; i >= 0; i--) {
        if (sum[i] - D[i] > MAX) {
            MAX = sum[i] - D[i];
        }
        max_right[i] = MAX;
    }

    // calculate ans

    int ans = INT_MAX;
    for (int i = 0; i < N; i++) {
        int max_late = 0;
        if (i == 0) {
            max_late = max_right[0] - (H[0] - 1);
            if (max_late < 0) {
                max_late = 0;
            }
            ans = min(ans, max_late);
            continue;
        }
        max_late = max(max_left[i - 1], max_right[i] - (H[i] - 1));
        if (max_late < 0) {
            max_late = 0;
        }
        ans = min(ans, max_late);
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
