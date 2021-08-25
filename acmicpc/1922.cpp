#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int parent[1002];
int res = 0;
bool chk;
typedef struct {
	int from;
	int to;
	int val;
}KS;

vector <KS> edge;

bool comp(KS d1, KS d2) {
	return d1.val < d2.val;
}


int find (int u) {
	if (u == parent[u]) return u;
	return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
	chk = false;
	u = find(u);
	v = find(v);
	
	if(u == v) return;
	parent[u] = v;
	chk = true;
}

int main()
{
	int N, M;
	scanf("%d", &N);
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		KS k;
		scanf("%d %d %d", &k.from, &k.to, &k.val);
		edge.push_back(k);
	}
	
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}
	sort(edge.begin(), edge.end(), comp);
//	printf("\n\n\n");
//	for (int i = 0;  i < edge.size(); i++) {
//		printf("%d %d %d\n", edge[i].from, edge[i].to, edge[i].val);
//	}
	for (int i = 0; i < M; i++) {
		merge(edge[i].from, edge[i].to);
		if(chk) res += edge[i].val;
	}
	
	printf("%d", res);
	return 0;
}
