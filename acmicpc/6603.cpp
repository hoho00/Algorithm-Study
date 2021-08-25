#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int a[14];
int visited[50];


void DFS(int num, int cnt) {
	if(cnt > 6) {
		for (int i = 1; i <= 49; i++) {
			if(visited[i] != 0) {
				printf("%d ", i);
			}
		}
		printf("\n");
		return;
	}
	
	for (int i = num; i<= n; i++) {
		if(visited[a[i]] == 0) {
			visited[a[i]] = 1;
			DFS(i + 1, cnt + 1);
			visited[a[i]] = 0;
		}
	}
}

int main()
{
	while(1) {
		scanf("%d", &n);
		if(n == 0) {
			break;
		}
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		
		DFS(1,1);
		if(n != 0) {
			printf("\n");
		}
	}
	return 0;
}
