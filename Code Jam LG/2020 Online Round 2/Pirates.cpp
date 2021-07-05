// https://codejam.lge.com/problem/19241

// build: g++ -o Pirates Pirates.cpp -std=c++11 && Pirates

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
1 ≤ N ≤ 100,000
0 ≤ A[i], B[i] ≤ 100,000

TC:

5
3
10 5
100 90
2 0
3
90 100
5 10
0 2
3
10 100
100 10
50 60
4
20 10
15 20
5 8
8 9
3
0 100
0 1000
0 10

*/

struct Treasure {
    int A;
    int B;
    Treasure(int AA = 0, int BB = 0) : A(AA), B(BB) {}
};


void solve() {
    // input
	cin >> N;
    vector<Treasure> ts;
    // Treasure t;
    int A;
    int B;
    for (int i = 0; i < N; i++) {
        scanf("%d", &A);
        scanf("%d", &B);
        ts.push_back(Treasure(A, B));
    }
    sort(ts.begin(), ts.end(), [](Treasure t1, Treasure t2) {
        return t1.A + t1.B >= t2.A + t2.B;
    });

    // for (int i = 0; i < N; i++) {
    //     cout << ts[i].A << ", " << ts[i].B << endl;
    // }

    int64_t a = 0;
    int64_t b = 0;

    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {
            a += ts[i].A;
        } else {
            b += ts[i].B;
        }
    }
    // cout << a - b << endl;
    int64_t ans = a - b;
    printf("%ld\n", ans);
    
}

int main() {
    cin >> T;
    while (T > 0) {
        solve();
        T--;
    }
}
