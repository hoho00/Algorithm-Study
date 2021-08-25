#include <iostream>

using namespace std;

int parent[1000001];
int root[1000001];
int n, m;

int find(int a) {
	if(parent[a] == a) {
		return a;
	}
	else {
		return parent[a] = find(parent[a]);
	}
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	
	parent[a] = b;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}
	
	for (int i = 0; i < m; i++) {
		int cmd, a, b;
		cin >> cmd >> a >> b;
		
		if(cmd == 0) {
			merge(a, b);
		}
		
		if(cmd == 1) {
			if(find(a) != find(b)) {
				cout << "NO" << '\n';
			}
			else {
				cout << "YES" << '\n';
			}
		}
	}
	
	
	return 0;
}
