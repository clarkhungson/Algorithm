#include <iostream>
using namespace std;

int N;//Number of mushrooms
int P[150000 + 10];//Mushroom value

void InputData(){
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> P[i];
	}
}

int main(){
	int ans = -1;

	InputData();			//	Input function

	//	Write the code
	
	int Q[150000 + 10];
	Q[0] = 1;
	for (int i = 1; i < N; i++) {
		Q[i] = P[i] - P[i-1];
	}
	int value;
	bool positive = true;
	for (int i = 0; i < N - 1; i++) {
		if (Q[i] * Q[i + 1] < 0) {
			if (positive) {
				value += P[i];
			} else {
				value -= P[i];
			}
			positive = (positive == true) ? false : true;
		}
	}
	
	if (Q[N-1] > 0) {
		value += P[N-1];
	}
	
	ans = value;
	
	cout << ans << endl;	//	Output answer
	return 0;
}
