#include <iostream>
using namespace std;

int N;
int A[30 + 10];
int sol[30 + 10];

void InputData(){
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> A[i];
	}
}

void OutputData(){
	cout << N << endl;
	for(int i=0;i<N;i++){
		cout << sol[i] << " ";
	}
	cout << endl;
}

int main(){
	InputData();//	?? ??

	//	??? ?????
	sol[0] = A[0];
	int last_index = 0;
	for (int i = 1; i < N; ++i) {
		int index = (last_index + sol[last_index]) % N;
		while (sol[index] != 0) {
			index = (index + 1) % N;
		}
		sol[index] = A[i];
		last_index = index;
		
	}

	OutputData();//?? 
	return 0;
}
