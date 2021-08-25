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

void bfs() {
	while(!q.empty()) {
		int row = q.front().first;
		int column = q.front().second;
		if(row == N - 1 && column == M - 1) {
			return;
		}
		isVisited[row][column] = 1;
		for (int i = 0; i < 4; i++) {
			int dCol = column + dir[i][1];
			int dRow = row + dir[i][0];
			if(dCol >= 0 && dCol < M && dRow >= 0 && dRow < N) {
				if(isVisited[dRow][dCol] == false && field[dRow][dCol] == 1) {
					isVisited[dRow][dCol] = true;
					A[dRow][dCol] = A[row][column] + 1;
					q.push(make_pair(dRow, dCol));
				}
			}
		}
		q.pop();
		
		
	}
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string line;
		cin >> line;
		for (int j = 0; j < line.size(); j++) {
			field[i][j] = line.at(j) - '0';
		}
	}
	
	
	
	q.push(make_pair(0, 0));
	A[0][0] = 1;
	bfs();
	cout << A[N - 1][M - 1] << '\n';
	
	return 0;
}
