#include <iostream>
#include <queue>
using namespace std;
int H;//Height
int W;//Width
char map[500][510];//map

void input_data(){
	int i;
	cin >> H >> W;
	for(i=0 ; i<H ; i++){
		cin >> map[i];
	}
}

struct Point {
	Point(int x1, int y1, int value1) : x(x1), y(y1), value(value1) {}
	int x;
	int y;
	int value;
};

int main(){
	int ans = 0;
	input_data();
	// Todo : write the code

	Point root(0, 0, 0);
	
	queue<Point> q;
	q.push(root);
	map[0][0] = 'D';
	
	ans = -1;
	
	while (!q.empty()) {
		Point element = q.front();
		q.pop();
		int x = element.x;
		int y = element.y;
		int value = element.value;
		
		
		// std::cout << "x: " << x << ", y: " << y << ", value: " << value << endl;
		
		if (x == H - 1 && y == W - 1) {
			// if (ans > 0 && ans > value) {
				ans = value;
			// cout << "ANS: " << ans << endl;
			// }
			// continue;
			break;
		}
		
		if (x >= 1 && map[x-1][y] == '.') {
			q.push(Point(x-1, y, value + 1));
			map[x-1][y] = 'D';
		}
		if (x < H - 1 && map[x+1][y] == '.') {
			q.push(Point(x+1, y, value + 1));
			map[x+1][y] = 'D';
		}
		if (y >= 1 && map[x][y - 1] == '.') {
			q.push(Point(x, y - 1, value + 1));
			map[x][y-1] = 'D';
		}
		if (y < W - 1 && map[x][y + 1] == '.') {
			q.push(Point(x, y + 1, value + 1));
			map[x][y+1] = 'D';
		}
		
	}
	
	
	cout << ans  << endl;
	return 0;
}