// https://codejam.lge.com/problem/16238

// build: g++ -o EagleandLambs EagleandLambs.cpp -std=c++11 && EagleandLambs

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

/*

TC:

5
1 10 4 10 1

*/



void solve() {
	cin >> N;
    vector<int> x;
    int e;
    for (int i = 0; i < N; i++) {
        scanf("%d", &e);
        x.push_back(e);
    }

    sort(x.begin(), x.end());
    int sum = 0;
    for (int i = N - 1; i >= 0; i--) {
        if (x[i] > (N - 1) - i) {
            sum += x[i] - (N - 1) + i;
        }
    }
    cout << sum << endl;
}

int main() {
    solve();
}
