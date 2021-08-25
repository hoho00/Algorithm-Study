#include <iostream>
#include <queue>

using namespace std;

int n, k, count = 0;

int visit[100001] = {0, };
queue<int> q;


int bfs() {
	while(!q.empty()) {
		int current = q.front();
		q.pop();
		if (current == k) {
			return visit[current] - 1;
		}
		
		if(current + 1 <= 100000 && visit[current + 1] == 0) {
			visit[current + 1] = visit[current] + 1;
			q.push(current + 1);
		}
		
		if(current - 1 >= 0 && visit[current - 1] == 0) {
			visit[current - 1] = visit[current] + 1;
			q.push(current - 1);
		}
		
		if(current * 2 <= 100000 && visit[current * 2] == 0) {
			visit[current * 2] = visit[current] + 1;
			q.push(current * 2);
		}
	}
}

int main()
{
	scanf("%d %d", &n, &k);
	q.push(n);
	visit[n] = 1;
	printf("%d", bfs());
	return 0;
}
