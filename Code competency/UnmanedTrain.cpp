#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Point {
public:
	Point(int x1, int y1) : x(x1), y(y1) {}
	int x;
	int y;
};

int main() {
	int data[50][50];
	int N;
	int M;
	cin >> N;
	cin >> M;
	
	// 1. Input data
	
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> data[i][j];
		}
	}
	
	// 2. Find line 1
	
	vector<Point> line1;
	Point p1(0, 0);
	
	bool found = false;
	for (int i = 0; !found && i < N; ++i) {
		for (int j = 0; !found && j < M; ++j) {
			if(data[i][j] == 1) {
				p1.x = i;
				p1.y = j;
				found = true;
			}
		}
	}
	
	// cout << "First point:    x: " << p1.x << ", y : " << p1.y << endl;
	

	// BFS to fill line1
	queue<Point> q;
	q.push(p1);
	data[p1.x][p1.y] = 2;

	while (!q.empty()) {
		Point element = q.front();
		q.pop();
		int x = element.x;
		int y = element.y;
		
		line1.push_back(Point(x, y));
		
		// cout << "x: " << x << ", y : " << y << endl;

		if (x > 0 && data[x-1][y] == 1) {
			q.push(Point(x-1, y));
			data[x-1][y] = 2;
		}
		if (x < N - 1 && data[x+1][y] == 1) {
			q.push(Point(x+1, y));
			data[x+1][y] = 2;
		}
		if (y > 0 && data[x][y-1] == 1) {
			q.push(Point(x, y - 1));
			data[x][y-1] = 2;
		}
		if (y < M - 1 && data[x][y+1] == 1) {
			q.push(Point(x, y + 1));
			data[x][y+1] = 2;
		}
	}
	
	// cout << "line1:" << endl;
	
	for (auto e : line1) {
		// cout << "e.x: " << e.x << ", e.y: " << e.y << endl;
	}
	
	// 3. BFS to calcualte distance
	
	int distance = 0;
	
	queue<Point> q2;
	for (auto e : line1) {
		q.push(e);
	}

	while (!q.empty()) {
		Point element = q.front();
		q.pop();
		int x = element.x;
		int y = element.y;
		
		// cout << "x: " << x << ", y : " << y << endl;

		if (x > 0) {
			if (data[x-1][y] == 0) {
				q.push(Point(x-1, y));
				data[x-1][y] = data[x][y] + 1;
			} else if (data[x-1][y] == 1) {
				distance = data[x][y] - 1;
				break;
			}
		}
		if (x < N - 1) {
			if (data[x+1][y] == 0) {
				q.push(Point(x+1, y));
				data[x+1][y] = data[x][y] + 1;
			}  else if (data[x+1][y] == 1){
				distance = data[x][y] - 1;
				break;
			}
		}
		if (y > 0) {
			if ( data[x][y-1] == 0) {
				q.push(Point(x, y - 1));
				data[x][y-1] = data[x][y] + 1;
			}  else if (data[x][y-1] == 1) {
				distance = data[x][y] - 1;
				break;
			}
		}
		if (y < M - 1) 
		{
			if(data[x][y+1] == 0) {
				q.push(Point(x, y + 1));
				data[x][y+1] = data[x][y] + 1;
			}  else if (data[x][y+1] == 1){
				distance = data[x][y] - 1;
				break;
			}
		}
	}
	
	cout << distance - 1 << endl;
	
	return 0;
}
