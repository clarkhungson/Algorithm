// https://codejam.lge.com/contest/problem/672/1
// build: g++ -o SplitHexString SplitHexString.cpp -std=c++11 && SplitHexString


#include <algorithm>
#include <unordered_map>
#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

/*

4
0070
FED
42
002021

*/

string removeZero(string str)
{
    // Count trailing zeros
    int i = 0;
    while (str[i] == '0')
       i++;
  
    // The erase function removes i characters
    // from given index (0 here)
    str.erase(0, i);
  
    return str;
}
// bool smaller(string a, string b) {
//     a = removeZero(a);
//     b = removeZero(b);
//     if (a.size() < b.size()) {
//         return true;
//     }
//     if (a.size() > b.size()) {
//         return false;
//     }
//     return (a <= b);
// }
unordered_map<char, int> hashMap;
bool smaller(string a, string b) {
	// debug(a, b);
	int n = a.length();
	int m = b.length();
	int i = 0, j = 0;
	while(i < n && a[i] == '0')
		i++;
	while(j < m && b[j] == '0')
		j++;
	// a = a.substr(i);
	// b = b.substr(j);
    a.erase(0, i);
    b.erase(0, j);
	n = a.length();
	m = b.length();
	//debug(a, b);
	if(n > m)
		return true;
	if(m > n)
		return false;

    // return a < b;
	for(i = 0; i < n; ++i) 
	{
		if(hashMap[a[i]] < hashMap[b[i]])
			return false;
        if(hashMap[a[i]] > hashMap[b[i]])
			return true;
	}
	return true;
}

bool checkResult(vector<string> v) {
    bool ans = true;
    int size = v.size();
    for (auto i = 0; i < size - 1; i++) {
        if (smaller(v[i], v[i + 1]) == false) {
            ans = false;
        }
    }
    return ans;
}

void cal(string& s) {
    // s = "002021";
    int n = s.size();
    int ans = 0;
    ans++; // i = 0
    
    for (int i = 1; i < pow(2, n - 1); i++) {
        vector<string> ss;
        int last = 0;
        for (int j = 0; j < n - 1; j++) {
            // cout << "-------------------------- i = " << i << endl;
            if (i & (1 << j)) {
                string sub;
                if (last == 0) {
                    sub = s.substr(0, j + 1);
                    // cout << "sub1 : " << sub << endl;
                } else {
                    sub = s.substr(last, j - last + 1); // get sub string
                    // cout << "sub2 : " << sub << endl;
                }
                
                ss.push_back(sub);
                // cout << "i: " << i << "last: " << last << ", j: " << i << "sub: " << sub << endl;
                last = j + 1;
            }
        }
        if (last != n) {
            ss.push_back(s.substr(last, n - 1));
        }
        if (checkResult(ss) != false) {
        // if (true) {
            ans++;
            // cout << "array" << endl;
            // for (auto e : ss) {
            //     cout << e << " ";
            // }
            // cout << endl;
        }
    }

    cout << ans << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // Insert code here

        cal(s);
        // End of insertion
    }
    return 0;
}
