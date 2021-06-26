#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;

int T;

struct Pos {
    Pos(int x1, int y1) : x(x1), y(y1) {}
    int x;
    int y;
};

Pos getPos(char c) {
    switch (c) {
        // Row 1
        case 'Q' :
            return Pos(0, 0);
            break;
        case 'W' :
            return Pos(0, 2);
            break;
        case 'E' :
            return Pos(0, 4);
            break;
        case 'R' :
            return Pos(0, 6);
            break;
        case 'T' :
            return Pos(0, 8);
            break;
        case 'Y' :
            return Pos(0, 10);
            break;
        case 'U' :
            return Pos(0, 12);
            break;
        case 'I' :
            return Pos(0, 14);
            break;
        case 'O' :
            return Pos(0, 16);
            break;
        case 'P' :
            return Pos(0, 18);
            break;
        // ------ Row 2
        case 'A' :
            return Pos(1, 1);
            break;
        case 'S' :
            return Pos(1, 3);
            break;
        case 'D' :
            return Pos(1, 5);
            break;
        case 'F' :
            return Pos(1, 7);
            break;
        case 'G' :
            return Pos(1, 9);
            break;
        case 'H' :
            return Pos(1, 11);
            break;
        case 'J' :
            return Pos(1, 13);
            break;
        case 'K' :
            return Pos(1, 15);
            break;
        case 'L' :
            return Pos(1, 17);
            break;
        // Row 3
        case 'Z' :
            return Pos(2, 2);
            break;
        case 'X' :
            return Pos(2, 4);
            break;
        case 'C' :
            return Pos(2, 6);
            break;
        case 'V' :
            return Pos(2, 8);
            break;
        case 'B' :
            return Pos(2, 10);
            break;
        case 'N' :
            return Pos(2, 12);
            break;
        case 'M' :
            return Pos(2, 14);
            break;
        default :
            break;
    }
}

int subtract(Pos p1, Pos p2) {
    if (p1.y == p2.y && p1.x != p2.x) {
        return 4;
    }
    return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}


void solve() {
    string s;
    cin >> s;
    int result = 0;
    for (unsigned i = 0; i < s.size() - 1; ++i) {
        result += 1;
        result += subtract(getPos(s[i]), getPos(s[i + 1]));
    }
    result += 1;
    cout << result << endl;
    
}

int main() {
    cin >> T;
    while (T > 0) {
        solve();
        T--;
    }
}
