// https://codejam.lge.com/problem/19592

// build: g++ -o ToyRace ToyRace.cpp -std=c++11 && ToyRace

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
int N; int X; int Y;

/*

5
3 12 11
3 2 1
3 12 9
3 2 1
3 12 10
3 4 5
3 80 80
80 60 70
3 80 80
70 50 60

*/

void solve() {
	cin >> N;
    cin >> X;
    cin >> Y;
    vector<int> v;
    int vv;
    for(int i = 0; i < N; ++i) {
        cin >> vv;
        v.push_back(vv);
    }
    int vmax = 0;
    for (int i = 0; i < N - 1; ++i) {
        if (v[i] > vmax) {
            vmax = v[i];
        }
    }

    if (vmax < v[N-1]) {
        cout << "0" << endl;
        return;
    }

    // cout << "vmax: " << vmax << endl;
    float val = X- ( (float) X / (float) vmax - 1) * v[N - 1];
    int Z = (int) val;
    Z++;
    if (Z > Y) {
        Z = -1;
    }
    cout << Z << endl;
}

int main() {
    cin >> T;
    while (T > 0) {
        solve();
        T--;
    }
}
