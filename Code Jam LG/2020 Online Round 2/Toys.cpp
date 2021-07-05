// https://codejam.lge.com/problem/19240

// build: g++ -o Toys Toys.cpp -std=c++11 && Toys

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
int M;

/*

Subtask 1 (4 Points)
3 ≤ N ≤ 16
1 ≤ M ≤ 16
Subtask 2 (8 Points)
3 ≤ N ≤ 300,000
1 ≤ M ≤ 300,000

TC:

3
3 3
1 2
2 3
3 1
4 4
1 2
2 3
3 4
4 1
6 6
1 2
2 3
1 4
1 5            
6 2
4 6

*/

struct Diff {
    int A;
    int B;
    Diff(int AA = 0, int BB = 0) : A(AA), B(BB) {}
};


void solve() {
    // input
	cin >> N;
    cin >> M;
    vector<Diff> ts;
    // Diff t;
    int A;
    int B;
    for (int i = 0; i < M; i++) {
        scanf("%d", &A);
        scanf("%d", &B);
        if (A <= B) {
            ts.push_back(Diff(A, B));
        } else {
            ts.push_back(Diff(B, A));
        }
    }

    sort(ts.begin(), ts.end(), [](Diff a, Diff b) {
        return (a.A < b.A) || (a.B < b.B);
    });

    // for (int i = 0; i < M; i++) {
    //     cout << ts[i].A << ", " << ts[i].B << endl;
    // }

    vector<int> toy(N + 1, 0);
    bool ans = true;

    for (int i = 0; i < M; ++i) {
        int toy1 = ts[i].A;
        int toy2 = ts[i].B;

        // check 2 element existed
        if (toy[toy1] != 0 && toy[toy2] != 0) {
            if (toy[toy1] * toy[toy2] > 0) {
                // cout << "break: toy1 " << toy1 << ": " << toy[toy1] << ";;;" << ", toy2: " << toy2 << ": " << toy[toy2] << endl;
                ans = false;
                break;
            }
            continue;
        }

        if (toy[toy1] == 0 && toy[toy2] == 0) {
            toy[toy1] = 1;
            toy[toy2] = -1;
            continue;
        }

        if (toy[toy1] != 0) {
            toy[toy2] = (toy[toy1] == 1) ? -1 : 1;
        } else {
            toy[toy1] = (toy[toy2] == 1) ? -1 : 1;
        }
    }
    
    if (ans) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
}

int main() {
    cin >> T;
    while (T > 0) {
        solve();
        T--;
    }
}
