#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

typedef struct {
	int x, y;
}Point;

int r, c;
string a[51];
int field[51][51];
int beaverField[51][51];
queue<Point> water;
queue<Point> beaverLoad;
Point beaver;
Point cave;
int waterLevel = 1;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

void bfs() {
	while(!water.empty()) {
		Point p = water.front();
		water.pop();
		for (int i = 0; i < 4; i++) {
			int newX = p.x + dx[i];
			int newY = p.y + dy[i];
			if(0 <= newX && newX < c && 0 <= newY && newY < r && a[newY][newX] == '.') {
				Point newP;
				newP.x = newX;
				newP.y = newY;
				water.push(newP);
				a[newY][newX] = 'L';
				field[newY][newX] = field[p.y][p.x] + 1;
			}
		}
	}
}

void beaverBfs() {
	while(!beaverLoad.empty()) {
		Point p = beaverLoad.front();
		beaverLoad.pop();
		for (int i = 0; i < 4; i++) {
			int newX = p.x + dx[i];
			int newY = p.y + dy[i];
			if(0 <= newX && newX < c && 0 <= newY && newY < r && field[newY][newX] > beaverField[newY][newX] && beaverField[newY][newX] == 0) {
				Point newP;
				newP.x = newX;
				newP.y = newY;
				beaverLoad.push(newP);
				beaverField[newY][newX] = beaverField[p.y][p.x] + 1;
			}
		}
	}
}

int main()
{
	scanf("%d %d", &r, &c);
	for (int i = 0; i < r; i++) {
		cin >> a[i];
	}
	
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if(a[i][j] == '*') {
				Point p;
				p.x = j;
				p.y = i;
				water.push(p);
				//field[i][j] = -1;
			}
			if (a[i][j] == 'D') {
				cave.x = j;
				cave.y = i;
				//field[i][j] = -1;
			}
			if (a[i][j] == 'S') {
				beaver.x = j;
				beaver.y = i;
				beaverLoad.push(beaver);
				//beaverField[i][j] = -1;
			}
			
		}
	}
	
	bfs();
	beaverBfs();
	for (int i = 0; i < r; i++) {
		cout << a[i] << '\n';
	}
	
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << field[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << beaverField[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
