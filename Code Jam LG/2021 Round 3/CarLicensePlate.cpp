// https://codejam.lge.com/contest/problem/672/1
// build: g++ -o CarLicensePlate CarLicensePlate.cpp -std=c++11 && CarLicensePlate

/*

5
4 3
AtY YtA aTy Ayt
4 4
AAaa AaAa aaAA AaaA
5 4
AAAA aaaa AAaa AAAa Aaaa
10 1
A a B b C c D d E e
2 10
ABCDEabcde abcdeEDCBA

*/


#include <iostream>
#include <vector>
using namespace std;
#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>


//char asciitolower(char in) {
//    if (in <= 'Z' && in >= 'A')
//        return in - ('Z' - 'z');
//    return in;
//}
//
// string lower(const string& data) {
//     std::transform(data.begin(), data.end(), data.begin(), asciitolower);
//     return data;
// }
 
 
string lower(string s) {
	for (auto& c : s) {
        if (c >= 'A' && c <= 'Z') {
            c += 'a' - 'A';
        }
    }
    sort(s.begin(), s.end());
    return s;
}

int num_of_Upper(string s) {
    int ans = 0;
    for (auto c : s) {
        if (c >= 'A' && c <= 'Z') {
            ans++;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<string> a(n);
        for (int i=0; i<n; i++) {
            cin >> a[i];
        }
        // Insert code here
        
         unordered_map<string, int> m;

         for (int i=0; i<n; i++) {
         	string key = lower(a[i]) + to_string(num_of_Upper(a[i]));
             m[key]++;
//             cout << "key: " << key << ", m[key]: " << m[key] << endl;
         }

         int64_t ans = 0;
         for (auto e : m) {
             int num = e.second;
             if (num > 1) {
                 ans += num * (num - 1) / 2;
             }
         }

         cout << ans << endl;
        
        // End of insertion
    }
    return 0;
}
