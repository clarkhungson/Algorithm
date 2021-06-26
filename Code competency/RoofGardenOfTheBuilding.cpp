#include <iostream>
#include <vector>
#include <stack>
#include <cstdint>
using namespace std;

int N;//Number of buildings
int H[80010];//Height of buildings

void Input_Data(void){
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> H[i];
	}
}

int main(){
	long long ans = -1;
	Input_Data();		//	Input function

	//	Write the code
	H[N] = 1000000001;
	ans = 0;
	stack<int> s;
	for (int i = 0; i < N + 1; ++i) {
		while (!s.empty() && H[s.top()] <= H[i]) {
			int j = s.top();
			ans += (i - j) - 1;
			s.pop();
		}
		s.push(i);
	}
	
	cout << ans << endl;	//	Output right answer
	return 0;
}

