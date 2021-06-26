#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

class Conflict {
public:
    int a;
    int b;
public:
    Conflict(int a, int b) {
        this->a = a;
        this->b = b;
    }
};

bool result(std::vector<Conflict>& T, int N) {

    std::vector<int> N(400000, 0);
    for (int i = 0; i < )
    
    return true;
}

int main() {
    int number_testcases;
    std::cin >> number_testcases;
    std::vector<std::vector<Conflict>> C;
    std::vector<int> N;

    for (int i = 0; i < number_testcases; ++i) {
        int N1;
        int M;
        std::cin >> N1;
        std::cin >> M;
        int a;
        int b;
        std::vector<Conflict> C1;
        for (int j = 0; j < M; ++j) {
            std::cin >> a;
            std::cin >> b;
            Conflict c(a, b);
            C1.push_back(c);
        }
    
        C.push_back(C1);
        N.push_back(N1);

        // std::cout << "T[i][j]:" << std::endl;
        // for (int j = 0; j < N; ++j) {
        //     std::cout << T[i][j] << " ";
        // }
        // std::cout << std::endl;
    }

    for (int i = 0; i < number_testcases; ++i) {
        std::cout << result(C[i], N[i]) << "..." << std::endl;
    }
    return 0;
}
