#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <vector>

int sum_of_row(const std::vector<std::vector<bool>>& M, int i) {
    int sum = 0;
    for (long unsigned int j = 0; j < M[0].size(); ++j) {
        if (M[i][j] == true) {
            ++sum;
        }
    }
    return sum;
}

void process(std::vector<std::vector<bool>>& M, const std::vector<int>& nn) {

    // for (int i = 0; i < 3; ++i) {
    //     for (int j = 0; j < M[0].size(); ++j) {
    //         std::cout << M[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }

    // remove on columm
    for (long unsigned int j = 0; j < M[0].size(); ++j) {
        std::vector<int> i_considered;
        for (int i = 0; i < 3; ++i) {
            if (M[i][j] == true) {
                i_considered.push_back(i);
            }
        }
        if (i_considered.size() > 1) {
            int min_index = i_considered[0];
            int min_columm = sum_of_row(M, min_index);
            for (long unsigned int k = 1; k < i_considered.size(); ++k) {
                int new_columm = sum_of_row(M, i_considered[k]);
                if (new_columm < min_columm) {
                    min_columm = new_columm;
                    min_index = i_considered[k];
                }
            }
            for (long unsigned int k = 0; k < i_considered.size(); ++k) {
                if (i_considered[k] != min_index) {
                    M[i_considered[k]][j] = false;
                }
            }
        }
    }

    // remove on row
    for (int i = 0; i < 3; ++i) {
        int max_in_column = nn[i];
        for (long unsigned int j = 0; j < M.size(); ++j) {
            if (M[i][j] == true) {
                if (max_in_column > 0) {
                    max_in_column--;
                } else {
                    M[i][j] = false;
                }
            }
        }
    }

    // print
    int max = 0;
    for (const auto& r : M) {
        for (const auto e : r) {
            if (e == true) {
                ++max;
            }
        }
    }
    std::cout << max << std::endl;
    for (long unsigned int j = 0; j < M[0].size(); ++j) {
        for (int i = 0; i < 3; ++i) {
            std::string letter;
            if (i == 0) {
                letter = "A";
            } else if (i == 1) {
                letter = "B";
            } else {
                letter = "C";
            }
            if (M[i][j] == true) {
                std::cout << j+1 << " " << letter << std::endl;
            }
        }
    }

    // for (int i = 0; i < 3; ++i) {
    //     for (int j = 0; j < M[0].size(); ++j) {
    //         std::cout << M[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }

}

int main() {
    int T;
    std::cin >> T;
    std::vector< std::vector<std::vector<bool>> > M_vector;
    std::vector< std::vector<int> > nn_vector;

    for (int i = 0; i < T; ++i) {
        int n;
        std::cin >> n;
    
        std::string line2;
        std::cin.ignore();
        std::getline(std::cin, line2);
        std::istringstream r2(line2);
        int na, nb, nc;
        r2 >> na;
        r2 >> nb;
        r2 >> nc;
        std::vector<int> nn;
        nn.push_back(na);
        nn.push_back(nb);
        nn.push_back(nc);

        std::vector<std::vector<bool>> M(3, std::vector<bool>(15000, false));

        std::string line3;
        std::getline(std::cin, line3);
        std::istringstream r3(line3);
        int ma;
        r3 >> ma;
        int index3;
        for (int i = 0; i < ma; ++i) {
            r3 >> index3;
            M[0][index3 - 1] = true;
        }

        std::string line4;
        std::getline(std::cin, line4);
        std::istringstream r4(line4);
        int mb;
        r4 >> mb;
        int index4;
        for (int i = 0; i < mb; ++i) {
            r4 >> index4;
            M[1][index4 - 1] = true;
        }

        std::string line5;
        std::getline(std::cin, line5);
        std::istringstream r5(line5);
        int mc;
        r5 >> mc;
        int index5;
        for (int i = 0; i < mc; ++i) {
            r5 >> index5;
            M[2][index5 - 1] = true;
        }

        M_vector.push_back(std::move(M));
        nn_vector.push_back(std::move(nn));

        // process(M, nn);

    }

    for (long unsigned int i = 0; i < M_vector.size(); ++i) {
        process(M_vector[i], nn_vector[i]);
    }

    return 0;
}
