// https://codejam.lge.com/problem/17433

// build: g++ -o MysteriousNumber MysteriousNumber.cpp -std=c++11 && MysteriousNumber

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

4
5
2 4 6 8 10
5
162 72 54 63 57
5
-20 -30 -50 80 75
4
5 5 5 5

*/

// Function to return gcd of a and b
int64_t gcd(int64_t a, int64_t b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

// Function to find gcd of array of
// numbers
int64_t findGCD(const vector<int64_t>& arr)
{
    int64_t result = arr[0];
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        result = gcd(arr[i], result);
 
        if(result == 1)
        {
           return 1;
        }
    }
    return result;
}

void solve() {
    // input
	cin >> N;
    
    vector<int64_t> x;
    int64_t e;

    for(int i = 0; i < N; ++i) {
        scanf("%lld", &e);
        x.push_back(e);
    }

    sort(x.begin(), x.end());
    
    vector<int64_t> y;
    for (int i = 0; i < x.size() - 1; i++) {
        y.push_back(x[i + 1] - x[i]);
    }

    sort(y.begin(), y.end());

    int64_t ans = findGCD(y);

    if (ans == 0) {
        cout << "INFINITY" << endl;
    } else {
        cout << ans << endl;
    }

}

int main() {
    cin >> T;
    while (T > 0) {
        solve();
        T--;
    }
}
