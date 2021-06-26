#include <iostream>
#include <vector>
using namespace std;

int N;//The number of goods to send 
int C[10];//The number of BOXes(in order of 1, 5, 10, 50, 100, 500, 1000, 3000, 6000, 12000)
int sol[10];//The number of boxes to send

void InputData(){
	int i;
	cin >> N;
	for(i = 0; i < 10; i++){
		cin >> C[i];
	}
}
void OutputData(int ans){
	int i;
	cout << ans << endl;
	for(i = 0; i < 10; i++){
		cout << sol[i] << " ";
	}
	cout << endl;
}
int main(){
	int ans = -1;

	InputData();//	Input function
    
	//	Create the code
	
	vector<int> v ={1, 5, 10, 50, 100, 500, 1000, 3000, 6000, 12000};
	int i = 0;
	int sum = 0;
	while (i < 10 && sum < N) {
		sum = sum + v[i] * C[i];
		i++;
	}

	while (i > 0) {
		i--;
		sum = sum - v[i] * C[i];
		// cout << "i : " << i << endl;
		// cout << "N : " << N << endl;
		// cout << "sum : " << sum << endl;
		sol[i] = (N - sum) / v[i] + ((N - sum) % v[i] == 0 ? 0 : 1);
		// cout << "sol(" << i << ")" << sol[i] << endl;
		N = N - sol[i] * v[i];
	}
	
	ans = 0;
	for (auto e : sol) {
		ans = ans + e;
	}

	OutputData(ans);//	Output function

	return 0;
}
