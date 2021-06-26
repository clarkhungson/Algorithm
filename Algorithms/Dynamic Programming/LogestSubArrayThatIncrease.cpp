#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>

// Input: 3,4,5,6,1,2,3,7,8
// Output: 3,4,5,6,7,8

using namespace std;

int main() {
	// input
	vector<int> data = {30,40,50,60,1,2,3,4,5,70,80};
	
	// put 0 and 99 to begin and end
	data = {0,30,40,50,60,1,2,3,4,5,70,80, 999};
	
	int N = data.size();
	
	vector<int> D(N, 0);
	D[N - 1] = 1;
	for (int i = N - 2; i >= 0; --i) {
		int j = i + 1;
		int max = 0; // max of D[j] that data[j] > data[i]
		for (; j <= N - 1; ++j) {
			if (data[i] <= data[j]) {
				if (D[j] > max)
					max = D[j];
			}
		}
		D[i] = 1 + max;
	}
	
//	cout << "D:" << endl;
//	
//	for (int i = 0 ; i < N ; ++i) {
//		cout << D[i] << " ";
//	}
//	
//	cout << endl;
//	
//	cout << "Result:" << endl;

	int found = 1;
	for (int i = 1; i < N - 1; ++i) {
		if(D[i] == D[0] - found) {
			cout << data[i] << " ";
			found++;
		}
	}
	
	return 0;
}
