// https://codejam.lge.com/problem/16237

// build: g++ -o Movers Movers.cpp -std=c++11 && Movers

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

10 8 2 7 3

*/



void solve() {
	int N = 5;
    int A;
    int B;
    int C;
    int D;
    int E;
    scanf("%d", &A);
    scanf("%d", &B);
    scanf("%d", &C);
    scanf("%d", &D);
    scanf("%d", &E);

    int sum = 0;
    sum += E; // E = 0
    sum += D;

    if (A > D) {
        A = A - D;
    } else {
        A = 0;
    }

    if (B > C) {
        sum += C;
        B = B - C;
        if (B % 2 == 0) {
            sum += B / 2;
            A -= (B / 2);
            if (A > 0) {
                sum += (A / 5) + ((A % 5 == 0) ? 0 : 1);
            }
        } else {
            sum += B / 2;
            A -= (B / 2);
            B = 1;
            if (A < 0) {
                sum += B;
            } else {
                sum += B;
                A -= 3;
                if (A > 0) {
                    sum += (A / 5) + ((A % 5 == 0) ? 0 : 1);
                }
            }
        }
    } else {
        
        sum += B;
        C = C - B;
        sum += C;
        A -= 2 * C;
        if (A > 0) {
            sum += (A / 5) + ((A % 5 == 0) ? 0 : 1);
        }
    }

    cout << sum << endl;
}

int main() {
    solve();
}
