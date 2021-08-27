#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
long long a[500001];
long long tree[3000001];
long long countN = 0;

long long initTree(int start, int end, int node) {
	if(start == end) return tree[node] = a[start];
	int mid = (start + end) / 2;
	return tree[node] = max(initTree(start, mid, node * 2), (initTree(mid + 1, end, node * 2 + 1) )) ;
}

long long maxTree(int start, int end, int node, int left, int right) {
	if(left > end || right < start) return 0;
	if(left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return max(maxTree(start, mid, node * 2, left, right), maxTree(mid + 1, end, node * 2 + 1, left, right));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	initTree(0, N - 1, 1);
	for (int i = 1; i < N; i++) {
		int back = a[i - 1];
		countN += (long long) maxTree(0, N - 1, 1, i, N - 1);
	}
	cout << countN;
	return 0;
}
