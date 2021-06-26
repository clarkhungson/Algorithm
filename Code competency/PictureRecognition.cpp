#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stdlib.h>
using namespace std;

struct Point {
	Point(int x1 = 0, int y1 = 0) : x(x1), y(y1) {}
	int x;
	int y;
};

int main() {
	
	int N;
	cin >> N;

	int data[10][10];
	
	// input data
	
	for (int i = 0; i < N; ++i) {
		string line;
		cin >> line;
		for (int j = 0; j < N; j++) {
			data[i][j] = line[j] - '0';
		}
	}
	
	// clasify Point 0, 1, 2, 3, ...
	
	vector<vector<Point>> L(10, vector<Point>());
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			L[data[i][j]].push_back(Point(i, j));
		}
	}
	
	// find rectangle of each 1,2,3...
	
	set<int> removed_point;
	
	for (int i = 1; i <= 9; ++i) {
		
		int x_min = 999, y_min = 999 , x_max = 0, y_max = 0;
		for (auto e : L[i]) {
			if (e.x < x_min) {
				x_min = e.x;
			}
			if (e.y < y_min) {
				y_min = e.y;
			}
			if (e.x > x_max) {
				x_max = e.x;
			}
			if (e.y > y_max) {
				y_max = e.y;
			}
		}
		
		for (int x = x_min; x <= x_max; ++x) {
			for (int y = y_min; y <= y_max; ++y) {
				if (data[x][y] != i) {
					removed_point.insert(data[x][y]);
				}
			}
		}
		
	}
	
	// calculate number = total_point - removed_point
	
	int total_point = 0;
	
	for (int i = 1; i <= 9; ++i) {
		if (!L[i].empty()) {
			total_point++;
		}
	
	}
	
	cout << total_point - removed_point.size() << endl;
	
	
	return 0;
}
