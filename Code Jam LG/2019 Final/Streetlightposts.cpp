// https://codejam.lge.com/problem/17430

// build: g++ -o Streetlightposts Streetlightposts.cpp -std=c++11 && Streetlightposts

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



TC:

2
6
2 3
2 -3
2 1
-2 3
-2 1
-2 -3
6
2 4
2 -3
2 1
-2 3
-2 1
-2 -3

*/


void solve() {
    // input
	cin >> N;
    
    int x;
    int y;
    // vector<Point> p;

    unordered_set<string> m;
    for(int i = 0; i < N; ++i) {
        scanf("%d", &x);
        scanf("%d", &y);

        string key = std::to_string(x) + std::to_string(y);
        string key1 = std::to_string(x) + std::to_string(-y);
        string key2 = std::to_string(-x) + std::to_string(y);

        if (m.count(key1)) {
            m.erase(key1);
        } else if (m.count(key2)) {
            m.erase(key2);
        } else {
            m.insert(key);
        }
    }

    if (m.empty() == false) {
        printf("NOT BALANCED\n");
    } else {
        printf("BALANCED\n");
    }
    
}

int main() {
    cin >> T;
    while (T > 0) {
        solve();
        T--;
    }
}
