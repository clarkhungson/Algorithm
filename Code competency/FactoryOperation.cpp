#include <iostream>
using namespace std;

int N;//Day
int S;//Storage cost
int C[50010];//Price
int Y[50010];//Capacity

void Input_Data(void){
	int i;
	cin >> N >> S;
	for (int i = 0; i < N; i++){
		cin >> C[i] >> Y[i];
	}
}

int main(){
	long long ans = -1;
	Input_Data();		//Input function

	// TODO : Write your codes.
	
	ans = 0;
	
	int best_day = 0;
	int best_cost = C[0];
	
	for (int i = 0; i < N; ++i) {
		// check needed update the best
		if (C[i] - best_cost < (i - best_day) * S) {
			best_day = i;
			best_cost = C[i];
		}
		// cal
		ans += best_cost * Y[i] + (i - best_day) * Y[i] * S;
	}
	
	
	cout << ans << endl;	//	Answer output
	return 0;
}

