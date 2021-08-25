#include <iostream> 
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dir[4][2] = {
    {-1,0},
    {1,0},
    {0,1},
    {0,-1},
};
typedef struct memoThing {
    int value = 0;
    //x 로 움직였을 때 0, y로 움직였을 때 1, 처음 일 때는 -1
    int isPrevMoving = -1;
}MemoThing;

MemoThing memo[26][26];
queue<pair<int, int>> q;

int bfs(vector<vector<int>> board) {
    int N = board.size();
    int count = 0;
    q.push(make_pair(0,0));
    while(!q.empty()) {
        int x = q.front().second;
        int y = q.front().first;
        q.pop();
        if(x == N - 1 && y == N - 1) break;
        
        for (int i = 0; i < 4; i++) {
            int newX = x + dir[i][0];
            int newY = y + dir[i][1];
            if(newX >= 0 && newY >= 0 && newX < N && newY < N && board[newY][newX] != 1) {
                if(memo[newY][newX].value == 0) {
                    q.push(make_pair(newY, newX));
                    //y moving
                    if(i <= 1) {
                        if(memo[y][x].isPrevMoving != 1) {
                            memo[newY][newX].value = memo[y][x].value + 500;
                        }
                        else {
                            memo[newY][newX].value = memo[y][x].value + 100;
                        }
                    }
                    //x moving
                    else {
                        if(memo[y][x].isPrevMoving != 0) {
                            memo[newY][newX].value = memo[y][x].value + 500;
                        }
                        else {
                            memo[newY][newX].value = memo[y][x].value + 100;
                        }
                    }
                }
                //원래 값과 비교해서 작은것 넣기
                else {
                    //y moving
                    if(i <= 1) {
                        if(memo[y][x].isPrevMoving != 1) {
                            memo[newY][newX].value = min (memo[y][x].value + 500, memo[newY][newX].value);
                        }
                        else {
                            memo[newY][newX].value = min (memo[y][x].value + 100, memo[newY][newX].value);
                        }
                    }
                    //x moving
                    else {
                        if(memo[y][x].isPrevMoving != 0) {
                            memo[newY][newX].value = min (memo[y][x].value + 500, memo[newY][newX].value);
                        }
                        else {
                            memo[newY][newX].value = min (memo[y][x].value + 100, memo[newY][newX].value);
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << memo[i][j].value << " ";
        }
        cout << endl;
    }
    return memo[N - 1][N - 1].value;
}

int solution(vector<vector<int>> board) {
    int answer = bfs(board);
    
    return answer;
}

int main() 
{
	int N;
	cin >> N;
	vector<vector<int>> board(N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int t;
			cin >> t;
			board[i].push_back(t);
		}
	}
	solution(board);
	return 0;
}




