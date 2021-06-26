#include <bits/stdc++.h>
#include <map>

using namespace std;


int main() {
    multiset<int> s;
    s.insert(6);
    s.insert(5);
    s.insert(9);
    s.insert(9);
    s.insert(3);
    s.insert(12);
    for (auto e : s) {
    	cout << e << ", ";
	}
	cout << endl;
	cout << distance(s.begin(), s.find(5)) << endl;
	cout << distance(s.begin(), s.find(3)) << endl;
	cout << distance(s.begin(), s.find(9)) << endl;
	cout << distance(s.begin(), s.find(12)) << endl;
	multiset<int> s2;
    return 0;
}
