#include <iostream>
using namespace std;

int N,Q;
int T[101];
int engineer[6];

void Input_Data(void){	
	cin >> N >> Q;				// Number of engineers, number of customers
	for(int i=1;i<=Q;i++){
		cin >> T[i];				// Customer’s work processing time
	}
}

int main(void){
	int sol;

	Input_Data();				// Input function

	// Write the code
	
	for (int i = 0; i < N; ++i) {
		engineer[i] = 0;
	}
	
	for (int i = 1; i <= Q; ++i) {
		int min_index = 0;
		for (int j = 1; j < N; ++j) {
			if (engineer[j] < engineer[min_index]) {
				min_index = j;
			}
		}
		engineer[min_index] += T[i];
	}
	
	int max = engineer[0];
	for (int i = 1; i < N; ++i) {
			if (engineer[i] > max) {
				max = engineer[i];
			}
		}

	sol = max;
	
	cout << sol << endl;	// Print answer
	return 0;
}
