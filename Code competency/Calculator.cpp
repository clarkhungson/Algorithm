#include <iostream>
using namespace std;
#include <string.h>
#include <string>
#include <vector>

int N;//the number of test cases
int B;//number system
char S[110];//first integer
char D[110];//second integer

void InputData(){
	cin >> B >> S >> D;
}

int char2int(const char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	return c - 'A' + 10;
}

char int2char(int i) {
	if (i >= 0 && i <=9) {
		return i + '0';
	}
	return (i - 10 + 'A');
}

int main(){
	int i;
	scanf("%d", &N);
	for(i = 0; i < N; i++){
		InputData();//input function
		//	write the code
		
		if (string(S) == "0" || string(D) == "0") {
			cout << 0 << endl;
			continue;
		}
		
		// 1. Get sign of 2 number
		
		bool sign1 = (S[0] != '-') ? true : false;
		bool sign2 = (D[0] != '-') ? true : false;
		
		// 2. Get absolute value of S, D into vector
		// ex: S "12345"-> num1 = 54321, D "6789" -> num2 = 9876
		
		vector<int> num1;
		vector<int> num2;
		
		for (int j = strlen(S) - 1; j >=0; j--) {
			if (S[j] == '-') {
				continue;
			}
			num1.push_back(char2int(S[j]));
		}
		
		for (int j = strlen(D) - 1; j >=0; j--) {
			if (D[j] == '-') {
				continue;
			}
			num2.push_back(char2int(D[j]));
		}
		
		// for (auto j : num1) {
		// 	cout << j;
		// }
		// cout << endl;
		// for (auto j : num2) {
		// 	cout << j;
		// }
		// cout << endl;
		
		// 3. calculate products when product num1 and num2
		
		vector<vector<int>> products;
		
		for (int j = 0; j < num2.size(); ++j) {
			vector<int> product(j, 0);
			int remember = 0;
			for (int k = 0; k < num1.size(); k++) {
				int value = num1[k] * num2[j] + remember;
				product.push_back(value % B);
				remember = value / B;
			}
			if (remember != 0) {
				product.push_back(remember);
			}
			products.push_back(product);
		}
		
		// for (auto p : products) {
		// 	for (auto e : p) {
		// 		cout << e;
		// 	}
		// 	cout << endl;
		// }
		
		// 4. sum all product in products
		
		vector<int> result;
		int remember = 0;
		for (int j = 0; j < products.back().size(); j++) {
			int value = remember;
			for (auto product : products) {
				if (j <= product.size() - 1) {
					value += product[j];
				}
			}
			remember = value / B;
			result.push_back(value % B);
		}
		
		while (remember > 0) {
			result.push_back(remember % B);
			remember = remember / B;
		}
		
		// 5. Output value
		
	  if (sign1 != sign2) {
			cout << "-";
		}
		for(int j = result.size() - 1; j >=0 ; j--) {
			cout << int2char(result[j]);
		}
		cout << endl;
		
		

	}
	return 0;
}
