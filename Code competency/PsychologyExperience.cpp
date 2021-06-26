#include <iostream>
using namespace std;

int N;//The number of candidates
int A[100000 + 10];//Temperament value

void InputData(){
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
}

int main(){
    InputData();//	Input function

	//	Create the code
	
	int i = 0;
	int j = N - 1;
	int minAbs = 9999;
	int x, y;
	while (i != j) {
		if (minAbs > abs(A[i] + A[j])) {
			minAbs = abs(A[i] + A[j]);
			x = i;
			y = j;
		}
		if (A[i] + A[j] < 0) {
			i++;
		} else {
			j--;
		}
	}
	
	cout << x << " " << y << endl;
	
	
    return 0;
}

