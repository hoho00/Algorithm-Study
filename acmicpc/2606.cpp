#include <iostream>
#include <queue>
#include <set>

using namespace std;

int n, m;
int a[101][101];
int visited[101];
set<int> res;
queue<int> q;

void bfs() {
	while(!q.empty()) {
		int current = q.front();
		q.pop();
		
		visited[current] = 1;
		
		//cout << current << endl;
		for (int i = 1; i <= n; i++) {
			if(i == current) continue;
			if(visited[i] == 0 && a[current][i] == 1) {
				q.push(i);
				res.insert(i);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	
	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		 int n1, n2;
		 cin >> n1 >> n2;
		 a[n1][n2] = 1;
		 a[n2][n1] = 1;
	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			cout << a[i][j] << ' ';
//		}
//		cout << endl;
//	}
	q.push(1);
	bfs();
	cout << res.size();
	return 0;
}
