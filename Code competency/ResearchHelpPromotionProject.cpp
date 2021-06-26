#include <iostream>
using namespace std;

int N;				//	# of stairs
int P[310];		//	P[i]: score earned when stepping on stair i

int Solve(){
	int sol=0;
	
	//	TODO : Write your codes.
	
	int M[310];
	
	if (N == 1) {
		return P[0];
	}
	
	if (N == 2) {
		return P[0] + P[1];
	}
	
	if (N == 3) {
		return max(P[0] + P[2], P[1] + P[2]);
	}
	
	if (N == 3) {
		return max(P[0] + P[2], P[1] + P[2]);
	}
	
	if (N == 4) {
		return max(P[0] + P[1] + P[3], P[0] + P[2] + P[3]);
	}
	
	if (N == 5) {
		return max(max(P[1] + P[2] + P[4], P[0] + P[2] + P[4]), (P[0] + P[1] + P[3] + P[4]));
	}
	
	M[0] = P[0];
	M[1] = P[0] + P[1];
	M[2] = max(P[0] + P[2], P[1] + P[2]);
	M[3] = max(P[0] + P[1] + P[3], P[0] + P[2] + P[3]);
	M[4] = max(max(P[1] + P[2] + P[4], P[0] + P[2] + P[4]), (P[0] + P[1] + P[3] + P[4]));
	
	for (int i = 0; i < N - 5; ++i) {
		M[i + 5] = max(
									max(M[i] + P[i+2] + P[i+3] + P[i+5],
											M[i+1] + P[i+3] + P[i+5]),
									max(M[i+2] + P[i+4] + P[i+5],
											M[i+3] + P[i+5])
							 );
	}

	sol = M[N-1];

	return sol;
}

void InputData(){
	cin >> N;
	for(int i=0 ; i<N ; i++){
		cin >> P[i];
	}
}

int main(){
	
	InputData();					//	Input function

	int sol = Solve();

	cout << sol << endl;		//	Answer output
	return 0;
}

