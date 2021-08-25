#include <iostream>

using namespace std;
long long divThing = (long long)1000000007;
int N, M, K;
long long a[1000001];
long long tree[5000001];


long long initTree(int start, int end, int node) {
	if(start == end) return tree[node] = a[start] % divThing;
	int mid = (start + end) / 2;
	return tree[node] = ((initTree(start, mid, node * 2) % divThing) * (initTree(mid + 1, end, node * 2 + 1) % divThing)) %divThing;
}

long long mulTree(int start, int end, int node, int left, int right) {
	if(left > end || right < start) return 1;
	if(left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return (((mulTree(start, mid, node * 2, left, right)) % divThing) * ((mulTree(mid + 1, end, node * 2 + 1, left, right)) % divThing)) % divThing;
}

long long updateTree(int start, int end, int node, int index, long long dif) {
	if(index < start || index > end) return tree[node];
	if(start == end) return tree[node] = dif;
	int mid = (start + end) / 2;
	return tree[node] = (((updateTree(start, mid, node * 2, index, dif) % divThing)) * ((updateTree(mid + 1, end, node * 2 + 1, index, dif)) % divThing)) % divThing;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	
	initTree(0, N - 1, 1);
//	cout << mulTree(0, N - 1, 1, 0, 4) << endl;
//	cout << updateTree(0, N - 1, 1, 3, 7) << endl;
//	cout << mulTree(0, N - 1, 1, 0, 4);
	
	
	for (int i = 0; i < M + K; i++) {
		int q, l, r;
		cin >> q >> l >> r;
		
		switch(q) {
			case 1 : {
				updateTree(0, N - 1, 1, l - 1, r);
				break;
			}
			case 2 : {
				cout << mulTree(0, N - 1, 1, l - 1, r - 1) % divThing << '\n';
				break;
			}
		}
	}
	return 0;
}
