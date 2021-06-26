#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

bool is_cheater(const std::vector<std::string>& c1, const std::vector<std::string>& c2) {
    // create 2 2-dimension array for statistics
    std::vector<std::vector<int>> s1(3, std::vector<int>(10, 0));
    std::vector<std::vector<int>> s2(3, std::vector<int>(10, 0));
    // for (int i = 0; i < 3; ++i) {
    //     for (int j = 0; j < 10; ++j) {
    //         s1[i][j] = 0;
    //         s2[i][j] = 0;
    //     }
    // }

    // make statistic
    for (int i = 0; i < c1.size(); ++i) {
        const std::string card = c1[i];
        int m, n;
        if (card[0] == 'R') {
            m = 0;
        } else if (card[0] == 'Y') {
            m = 1;
        } else {
            m = 2;
        }
        n = card[1] - '0';
        s1[m][n] += 1;
    }
    for (int i = 0; i < c2.size(); ++i) {
        const std::string card = c2[i];
        int m, n;
        if (card[0] == 'R') {
            m = 0;
        } else if (card[0] == 'Y') {
            m = 1;
        } else {
            m = 2;
        }
        n = card[1] - '0';
        s2[m][n] += 1;
    }

    // do compare
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (s1[i][j] != s2[i][j]) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    int number_of_testcases;
    std::cin >> number_of_testcases;
    std::vector<std::vector<std::string>> c1(10);
    std::vector<std::vector<std::string>> c2(10);

    for (int i = 0; i < number_of_testcases; ++i) {
        int number_of_cards;
        std::cin >> number_of_cards;
        std::string card;
        for (int j = 0; j < number_of_cards; ++j) {
            std::cin >> card;
            c1[i].push_back(card);
        }
        for (int j = 0; j < number_of_cards; ++j) {
            std::cin >> card;
            c2[i].push_back(card);
        }
        // std::cout << "c1[i]:" << std::endl;
        // for (int j = 0; j < number_of_cards; ++j) {
        //     std::cout << c1[i][j] << " ";
        // }
        // std::cout << std::endl;

        // std::cout << "c2[i]:" << std::endl;
        // for (int j = 0; j < number_of_cards; ++j) {
        //     std::cout << c2[i][j] << " ";
        // }
        // std::cout << std::endl;
    }

    for (int i = 0; i < number_of_testcases; ++i) {
        if (is_cheater(c1[i], c2[i]))
        {
            std::cout << "CHEATER" << std::endl;
        } else {
            std::cout << "NOT CHEATER" << std::endl;
        }
    }
    return 0;
}
