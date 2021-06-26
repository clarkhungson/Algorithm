#include <iostream>
using namespace std;
#include <string.h>
#include <vector>

int N;//Map Size
char map[110][110];//Map information

void Input_Data(){
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> map[i];
	}
}

int main(){
	int ans = -1;
	Input_Data();		//	Input function


	//	Write the code
	int data[110][110];
	int M = strlen(map[0]);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			data[i][j] = map[i][j] - '0';
		}
	}

	vector<vector<int>> value(110, vector<int>(110, 99999));
	value[0][0] = 0;
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (i == N -1 && j == M-1) continue;
				if (i > 0 && value[i-1][j] > value[i][j] + data[i-1][j]) {
					value[i-1][j] = value[i][j] + data[i-1][j];
				}
				if (i < N - 1 && value[i+1][j] > value[i][j] + data[i+1][j]) {
					value[i+1][j] = value[i][j] + data[i+1][j];
				}
				if (j > 0 && value[i][j - 1] > value[i][j] + data[i][j - 1]) {
					value[i][j - 1] = value[i][j] + data[i][j - 1];
				}
				if (j < M - 1 && value[i][j + 1] > value[i][j] + data[i][j + 1]) {
					value[i][j + 1] = value[i][j] + data[i][j + 1];
				}
			}
		}
		
	}
	
	ans = value[N - 1][M - 1];
	
	
	cout << ans << endl;	//	Output answer

	return 0;
}

