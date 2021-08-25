#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool visit[2001] = {false,};
vector<int> v[2001];
int n, m;

void dfs(int x, int count) {
	visit[x] = true;
	if (count == 4) {
		printf("1");
		exit(0);
	}
	
	for (int i = 0; i < v[x].size(); i++) {
		if(!visit[v[x][i]]) {
			dfs(v[x][i], count + 1);
		}
	}
	
	visit[x] = false;
}

int main()
{
	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	for (int i = 0; i < n; i++) {
		dfs(i, 0);
	}
	printf("0");
	return 0;
}
