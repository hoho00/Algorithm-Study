#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
int visited[1001][1001];

int main()
{
	ios_base::sync_with_stdio(false);
	
	int n, ans = -1;
	cin >> n;
	memset(visited, -1, sizeof(visited));
	queue<pair<int, int>> q;
	q.push(make_pair(1, 0));
	visited[1][0] = 0;
	
	while(!q.empty()) {
		int screen = q.front().first;
		int clipboard = q.front().second;
		q.pop();
		if(visited[screen][screen] == -1) {// clipboard copy
			visited[screen][screen] = visited[screen][clipboard] + 1;
			q.push(make_pair(screen, screen));
		}
		
		if(screen + clipboard <= n && visited[screen + clipboard][clipboard] == -1) {
			visited[screen + clipboard][clipboard] = visited[screen][clipboard] + 1;
			q.push(make_pair(screen + clipboard, clipboard));
		}
		
		if(screen > 0 && visited[screen - 1][clipboard] == -1) {
			visited[screen - 1][clipboard] = visited[screen][clipboard] + 1;
			q.push(make_pair(screen - 1, clipboard));
		}
	}
	
	for (int i = 0; i <= n; i++) {
		if(visited[n][i] != -1) {
			if(ans == -1 || ans > visited[n][i]) {
				ans = visited[n][i];
			}
		}
	}
	
	cout << ans;
	return 0;
}
