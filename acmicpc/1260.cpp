#include <iostream>
#include <queue>

using namespace std;

int dfs_graph[1010][1010];
int bfs_graph[1010][1010];
int dfs_isVisited[1010];
int bfs_isVisited[1010];

queue<int> q;
static int bfs_count = 1;

int N, M, V;

void dfs(int v) {
	if(dfs_isVisited[v] == 0) {
		cout << v << ' ';
	}
	
	for (int i = 1; i <= N; i++) {
		if(dfs_graph[v][i] == 1) {
			dfs_isVisited[v] = 1;
			dfs_graph[v][i] = 0;
			dfs_graph[i][v] = 0;
			dfs(i);
		}
	}
}


void bfs(int v) {
	if(bfs_count > N) {
		return;
	}
	if(bfs_isVisited[v] == 0) {
		cout << v << ' ';
		bfs_count++;
	}
	bfs_isVisited[v] = 1;
	for (int i = 1; i <= N; i++) {
		if(bfs_graph[v][i] == 1) {
			
			bfs_graph[v][i] = 0;
			bfs_graph[i][v] = 0;
			q.push(i);
		}
	}
	if(q.empty()) {
		return;
	}
	int next = q.front();
	q.pop();
	bfs(next);
}

int main()
{	
	cin >> N >> M >> V;
	
	for (int i = 0; i < M; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		dfs_graph[v1][v2] = 1;
		dfs_graph[v2][v1] = 1;
		bfs_graph[v1][v2] = 1;
		bfs_graph[v2][v1] = 1;
	}
	
	dfs(V);
	cout << '\n';
	bfs(V);
	
	return 0;
}
