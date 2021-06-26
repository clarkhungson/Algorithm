#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <vector>

void process(const std::vector<bool>& M) {
    
}

int main() {
    int T = 0;
    std::cin >> T;

    for (int i = 0; i < T; ++i) {
        int n;
        std::cin >> n;
    
        std::string line2;
        std::cin >> line2;
        std::istringstream r2(line2);
        int na, nb, nc;
        r2 >> na;
        r2 >> nb;
        r2 >> nc;
    
        std::vector<std::vector<bool>> M(3, std::vector<10000, false>));
        int ma, mb, mc;
    
        std::string line3;
        std::cin >> line3;
        std::istringstream r3(line3);
        r3 >> ma;
        int index3;
        for (int i = 0; i < ma; ++i) {
            r3 >> index3;
            M[0, index3 - 1] = true;
        }

        std::string line4;
        std::cin >> line4;
        std::istringstream r4(line4);
        r4 >> mb;
        int index4;
        for (int i = 0; i < mb; ++i) {
            r4 >> index4;
            M[0, index4 - 1] = true;
        }

        std::string line5;
        std::cin >> line5;
        std::istringstream r5(line5);
        r5 >> mc;
        int index;
        for (int i = 0; i < mc; ++i) {
            r5 >> index;
            M[0, index5 - 1] = true;
        }

        // calculate
        process(M);
    }

    return 0;
}
