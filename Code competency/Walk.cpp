#include <iostream>
#include <cstdint>
#include <algorithm>
using namespace std;

int N;//Number of employees
int T;//Walking Time (in minutes)
int P[100000 + 10];//Starting location of emplyees
int S[100000 + 10];//Walking speed of emplyees (per minute)

void InputData(){
	cin >> N >> T;
	for (int i = 0; i < N; i++){
		cin >> P[i] >> S[i];
	}
}

int main(){
	int ans = -1;

	InputData();			//	Input function

	//	Write the code
	
	int64_t schedule_location[N];
	// int64_t actual_location[N];
	
	for (int i = 0; i < N; i++) {
		schedule_location[i] = P[i] + S[i] * T;
	}
	
	// actual_location[N - 1] = schedule_location[N - 1];
	int64_t last_value = schedule_location[N - 1];
	ans = 1;
	for (int i = N - 2; i >= 0; --i) {
		if (schedule_location[i] > schedule_location[i + 1]) {
			schedule_location[i] = schedule_location[i + 1];
			
			
		}
		if (schedule_location[i] != last_value) {
				last_value = schedule_location[i];
				ans++;
			}
	}
	
	
	cout << ans << endl;	//	Output right answer
	return 0;
}
