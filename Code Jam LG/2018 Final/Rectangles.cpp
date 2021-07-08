// https://codejam.lge.com/problem/16207

// build: g++ -o Rectangles Rectangles.cpp -std=c++11 && Rectangles

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

9
10 3 4 4 4 5 6 6 6

*/


void solve() {
	int N;
    scanf("%d", &N);

    vector<int64_t> x;
    int e;
    for (int64_t i = 0; i < N; i++) {
        scanf("%d", &e);
        x.push_back(e);
    }

    sort(x.begin(), x.end());

    int64_t sum = 0;


    bool flag = false;

    for (int64_t i = N - 1; i > 0; i--) {
        if (flag == true) {
            flag = false;
            continue;
        }
        if (x[i - 1] == x[i]) {
            flag = true;
            continue;
        }
        if (x[i - 1] == x[i] - 1) {
            x[i] = x[i] - 1;
            flag = true;
            continue;
        }
        x[i] = 0;
    }

    vector<int64_t> y;
    for (int64_t i = 0; i < N; i++) {
        if (x[i] != 0) {
            y.push_back(x[i]);
        }
    }

    for (int64_t i = y.size() - 1; i >= 3; i -= 4) {
        sum += y[i] * y[i - 2];
    }

    cout << sum << endl;
}

int main() {
    solve();
}
