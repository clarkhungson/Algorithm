// https://codejam.lge.com/problem/16200

// build: g++ -o TeamFormation TeamFormation.cpp -std=c++11 && TeamFormation

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
2 2 2 2 2 3 3 3 3

*/


void solve() {
	int N;
    scanf("%d", &N);

    vector<int> x;
    int e;
    for (int i = 0; i < N; i++) {
        scanf("%d", &e);
        x.push_back(e);
    }

    sort(x.begin(), x.end());

    int ans = 0;

    int i = 0;

    while (i < x.size()) {
        if (i + x[i] <= x.size() - 1) {
            ans += 1;
            i += x[i];
        } else {
            ans += 1;
            i = x.size();
        }
        
    }


    cout << ans << endl;
}

int main() {
    solve();
}
