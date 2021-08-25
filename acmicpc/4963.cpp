#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int field[101][101];
bool isVisited[101][101];
int A[101][101];
int dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
int N, M;

queue<pair <int, int>> q;

void dfs(int row, int col, int count) {
	field[row][col] = count;
	if(row - 1 >= 0 && row -1 < M && col >= 0 && col < N && field[row - 1][col] == 1) {
		dfs(row - 1, col, count);
	}
	if(row + 1 >= 0 && row + 1 < M && col >= 0 && col < N && field[row + 1][col] == 1) {
		dfs(row + 1, col, count);
	}
	if(row >= 0 && row < M && col - 1 >= 0 && col - 1< N && field[row][col - 1] == 1) {
		dfs(row, col - 1, count);
	}
	if(row >= 0 && row < M && col + 1 >= 0 && col + 1 < N && field[row][col + 1] == 1) {
		dfs(row, col + 1, count);
	}
	
	//- -
	if(row - 1 >= 0 && row - 1 < M && col - 1 >= 0 && col - 1 < N && field[row - 1][col - 1] == 1) {
		dfs(row - 1, col - 1, count);
	}
	
	//- +
	if(row - 1 >= 0 && row - 1 < M && col + 1 >= 0 && col + 1 < N && field[row - 1][col + 1] == 1) {
		dfs(row - 1, col + 1, count);
	}
	
	//+ -
	if(row + 1 >= 0 && row + 1 < M && col - 1 >= 0 && col - 1 < N && field[row + 1][col - 1] == 1) {
		dfs(row + 1, col - 1, count);
	}
	
	//+ +
	if(row + 1 >= 0 && row + 1 < M && col + 1 >= 0 && col + 1 < N && field[row + 1][col + 1] == 1) {
		dfs(row + 1, col + 1, count);
	}
}

int countIsland(int count) {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if(field[i][j] == 1) {
				count--;
				dfs(i, j, count);
			}
		}
	}
	return count;
}

int main()
{
	while(1) {
		cin >> N >> M;
		if(N == 0 && M == 0) {
			break;
		}
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				cin >> field[i][j];
			}
		}
	
		cout << -countIsland(0) << endl;
	}
	
	return 0;
}
