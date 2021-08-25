#include <iostream>
#include <vector>

using namespace std;

int parent[1000002];
bool chk;
int res;

typedef struct {
	int from;
	int to;
}E;


int find (int u) {
	if(parent[u] == u) return u;
	return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
	chk = false;
	u = find(u);
	v = find(v);
	
	if(u == v) return;
	if(u > v) {
		parent[u] = v;
	}
	else {
		parent[v] = u;
	}
	
	chk = true;
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}
	
	for (int i = 0; i < m; i++) {
		int c;
		E tmp;
		scanf("%d %d %d", &c, &tmp.from, &tmp.to);
		//edge.push_back(tmp);
		if(c == 0) {
			merge(tmp.from, tmp.to);
		}
		
		else if (c == 1) {
			if(find(tmp.from) == find(tmp.to)) {
				printf("YES\n");
			}
			else {
				printf("NO\n");
			}
		}
	}
	return 0;
}
