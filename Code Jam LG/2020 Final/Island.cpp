// https://codejam.lge.com/problem/19592

// build: g++ -o Island Island.cpp -std=c++11 && Island

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

1 ≤ T ≤ 10
2 ≤ N ≤ 1,000
1 ≤ Seed, A, B ≤ 1,000,000,000 

TC:

4
4 2020 2 3
4 2020 3 4
4 2020 9 7
5 2020 4 7
*/

#define M 2000

int64_t T;
int64_t N;
int64_t seed;
int64_t A;
int64_t B;



int64_t parent[M];
int64_t Rank[M];

void init() {
    for (int64_t i=0; i< M; i++) {
        parent[i] = i;
        Rank[i] = 0;
    }
}

int64_t find(int64_t u) {
    if (parent[u] != u) parent[u] = find(parent[u]);
    return parent[u];
}

void join(int64_t u, int64_t v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    if (Rank[u] == Rank[v]) Rank[u]++;
    if (Rank[u] < Rank[v]) parent[u] = v;
    else parent[v] = u;
}

void solve() {
    // cout << "start, T: " << T << endl;
	cin >> N;
    cin >> seed;
    cin >> A;
    cin >> B;
    // scanf("%d %d %d %d", &N, &seed, &A, &B);

    vector<int64_t> E(N * N  + 1, 0);
    vector<int64_t> X(N * N  + 1, 0);
    vector<int64_t> Y(N * N + 1, 0);

    init();
    // cout << "-----------" << endl;
    // for (int64_t i = 0; i < N; ++i) {
        // cout << "parent[i]: " << parent[i] << ", Rank[i]: " << Rank[i] << endl;
    // }
    // cout << "-----------" << endl;

    E[0] = (seed) % (N * N);
    X[0] = E[0] / N;
    Y[0] = E[0] % N;
    if (X[0] != Y[0]) {
        join(X[0], Y[0]);
        if (N == 2) {
            cout << 1 << endl;
            return;
        }
        // cout << "join: " << X[0] << " and " << Y[0] << endl;
    }

    int64_t ans = 0;
    
    for (int64_t i = 1; i <  N * N  + 1; i++) {
        E[i] = (E[i - 1] * A + B) % (N * N);
        X[i] = E[i] / N;
        Y[i] = E[i] % N;
        if (X[i] != Y[i]) {
            join(X[i], Y[i]);
            // cout << "join: " << X[i] << " and " << Y[i] << endl;
        }
        // checl all connected
        int64_t p = find(0);
        bool flag = true;
        for (int64_t j = 0; j < N; ++j) {
            if (find(j) != p) {
                // cout << "flag true -> false" << endl;
                flag = false;
                // cout << "p: " << p << ", break when j: " << j << endl;
                break;
            }
        }
        // cout << "-----------" << endl;
        // for (int64_t j = 0; j < N; ++j) {
        //     cout << "find[j]: " << find(j) << ", Rank[j]: " << Rank[j] << endl;
        // }
        // cout << "-----------" << ", flag: " << flag << endl;
        if (flag == true) {
            ans = 1 + i;
            // cout << "got ans" << endl;
            break;
        }
        // cout << "end for" << endl;
    }
    cout << ans << endl;
    // cout << "endl, T: " << T << endl;
}

int main() {
    int64_t T;
    cin >> T;

    for (int64_t i = 0; i < T; i++) {
        solve();
    }
}
