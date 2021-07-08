// https://codejam.lge.com/problem/16206

// build: g++ -o RollCake RollCake.cpp -std=c++11 && RollCake

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

3 1
10 10 20

*/


void solve() {
	int N;
    int M;
    scanf("%d", &N);
    scanf("%d", &M);


    vector<int> x1;
    vector<int> x2;

    int e;
    for (int i = 0; i < N; i++) {
        cin >> e;
        if (e % 10 != 0) {
            x1.push_back(e);
        } else {
            x2.push_back(e);
        }
        
    }

    sort(x2.begin(), x2.end());

    int sum = 0;

    for (int i = 0; i < x2.size(); i++) {
        if ((x2[i] / 10) - 1 <= M) {
            sum += (x2[i] / 10);
            M -= (x2[i] / 10) - 1;
        } else {
            sum += M;
            M = 0;
        }
        if (M <= 0) {
            break;
        }
    }

    if (M <= 0) {
        cout << sum << endl;
        return;
    }

    for (int i = 0; i < x1.size(); i++) {
        if ((x1[i] / 10) <= M) {
            sum += (x1[i] / 10);
            M -= (x1[i] / 10);
        } else {
            sum += M;
            M = 0;
        }
        if (M <= 0) {
            break;
        }
    }

    cout << sum << endl;
}

int main() {
    solve();
}
