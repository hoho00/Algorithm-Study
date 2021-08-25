#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int m, n;
int a[1001][1001];
vector<int> startPoint;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

typedef struct {
	int y, x;
}Tomato;

queue<Tomato> q;


void bfs() {
	while(!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		q.pop();
		//printf("%d %d\n", x, y);
		for (int i = 0; i < 4; i++) {
			int newX = x + dx[i];
			int newY = y + dy[i];
			if (0 <= newX && newX < m && 0 <= newY && newY < n && a[newY][newX] == 0) {
				Tomato newTomato;
				newTomato.x = newX;
				newTomato.y = newY;
				q.push(newTomato);
				a[newY][newX] = a[y][x] + 1;
			}
		}
	}
}

int main()
{
	scanf("%d %d", &m, &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int tmp;
			scanf("%d", &tmp);
			a[i][j] = tmp;
			if(tmp == 1) {
				Tomato tomato;
				tomato.x = j;
				tomato.y = i;
				q.push(tomato);
			}
		}
	}
//	
//	while(!q.empty()) {
//		printf("%d %d\n", q.front().x, q.front().y);
//		q.pop();
//	}
	bfs();
	int maxNum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 0) {
				printf("-1");
				exit(0);
			}
			if (maxNum < a[i][j]) {
				maxNum = a[i][j];
			}
		}
	}
	printf("%d", maxNum - 1);
	return 0;
}
