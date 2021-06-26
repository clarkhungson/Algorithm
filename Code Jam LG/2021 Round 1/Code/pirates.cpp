#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

class Treasure {
public:
    int a;
    int b;
public:
    Treasure(int a, int b) {
        this->a = a;
        this->b = b;
    }
    int value() {
        return a-b;
    }
};

int result(std::vector<Treasure>& T) {

    // sort T

    for (int i = 0; i < T.size() - 1; ++i) {
        for (int j = i + 1; j < T.size(); ++j) {
            if (T[i].value() > T[j].value()) {
                auto t = T[i];
                T[i] = T[j];
                T[j] = t;
            }
        }
    }

    for (int i = 0; i < T.size(); ++i) {
        std::cout << T[i].value() << ", " << std::endl;
    }

    int a = 0;
    int b = 0;
    int mid_point;
    if (T.size()%2 == 0) {
        mid_point = T.size()/2;
    } else {
        mid_point = (T.size() + 1)/2;
    }
    for (int i = 0; i < mid_point; ++i) {
        a += T[i].a;
    }
    for (int i = mid_point; i < T.size(); ++i) {
        b += T[i].b;
    }
    
    return a-b;
}

int main() {
    int number_testcases;
    std::cin >> number_testcases;
    std::vector<std::vector<Treasure>> T;

    for (int i = 0; i < number_testcases; ++i) {
        int N;
        std::cin >> N;
        int a;
        int b;
        std::vector<Treasure> T1;
        for (int j = 0; j < N; ++j) {
            std::cin >> a;
            std::cin >> b;
            Treasure t(a, b);
            T1.push_back(t);
        }
    
        T.push_back(T1);

        // std::cout << "T[i][j]:" << std::endl;
        // for (int j = 0; j < N; ++j) {
        //     std::cout << T[i][j] << " ";
        // }
        // std::cout << std::endl;
    }

    for (int i = 0; i < number_testcases; ++i) {
        std::cout << result(T[i]) << std::endl;
    }
    return 0;
}
