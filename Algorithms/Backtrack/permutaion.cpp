/*
Input N, for example: N = 3
Output : 123, 132, 213, 231, 312, 321
*/

#include <iostream>
#include <vector>

using namespace std;

// result container
vector<int> data(100, 0);

// print data
void printResult(int N) {
    for (int i = 1; i <= N; ++i) {
        cout << data[i];
    }
    cout << endl;
}

void permutation(int N, int count) {
    for (int i = 1; i <= N; ++i) {
        // Check condition: one number does not appear more than 1 time
        bool isUsed = false;
        for (int k = 1; k <= count - 1; ++k) {
            if (data[k] == i) {
                isUsed = true;
                break;
            }
        }
        if (isUsed == true) {
            continue;
        }

        // do something
        data[count] = i;
        
        // Check break condition, or recursive
        if (N == count) {
            printResult(N);
        } else {
            permutation(N, count + 1);
        }
    }
    
}

int main()
{
    int N;
    cin >> N;
    permutation(N, 1);
    return 0;
}


