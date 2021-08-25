#include <iostream>
#include <queue>

using namespace std;

int a[21][21];
int N;
pair<int, int> startPoint;
int mySize = 2;
//up, left, down, right
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

pair<int, int> findFeed(int x, int y) {
	pair<int, int> p;
	if(a[y][x] != 0 && a[y][x] < mySize) {
		return make_pair(x, y);
	}
	for (int i = 0; i < 4; i++) {
		if(y + dy[i] >= 0 && y + dy[i] < N && x + dx[i] >= 0 && x + dx[i] < N && a[y + dy[i]][x + dx[i]] <= mySize) {
			findFeed(x + dx[i], y + dy[i]);
		}
		else break;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> N;
	
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int tmp;
			cin >> tmp;
			a[i][j] = tmp;
			if(tmp == 9) {
				startPoint.first = j;
				startPoint.second = i;
			}
		}
	}
	//cout << startPoint.first << startPoint.second << endl;
	pair<int, int> p = findFeed(startPoint.first, startPoint.second);
	
	while(true){

        init_check();

        bfs(shark_x, shark_y);
 
        if(min_x != max_int && min_y != max_int){

            result += check[min_x][min_y];

            eat_cnt++;
            

            if(eat_cnt == shark_size){

                shark_size++;
                eat_cnt = 0;
            }
            

            a[min_x][min_y] = 0;
            
            // 상어의 위치를 갱신해줍니다.
            shark_x = min_x;
            shark_y = min_y;
        }
        
        else{
            break;
        }
    }
	cout << p.first << p.second;
	
	return 0;
}
