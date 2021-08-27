#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N ,M;
int a[100101];
int tree[500101];
int isOdd[500101];


int initTree(int start, int end, int node) {
	if(start == end) return tree[node] = isOdd[start];
	int mid = (start + end) / 2;
	return tree[node] = initTree(start, mid, node *2) + initTree(mid + 1, end, node * 2 + 1);
}

int sumOdd(int start, int end, int node, int left, int right) {
	if(left > end || right < start) return 0;
	if(left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return sumOdd(start, mid, node * 2, left, right) + sumOdd(mid + 1, end, node * 2 + 1, left, right);
	
}

void updateOdd(int start, int end, int node, int index, int dif) {
	if(index < start || index > end) return;
	tree[node] += dif;
	if(start == end) return;
	int mid = (start + end) / 2;
	updateOdd(start, mid, node * 2, index, dif);
	updateOdd(mid + 1, end, node * 2 + 1, index, dif);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		if(a[i] % 2 == 0) isOdd[i] = 0;
		else isOdd[i] = 1;
	}
	
	initTree(0, N - 1, 1);
//	cout << sumOdd(0, N - 1, 1, 4, 6) << endl;
//	updateOdd(0, N - 1, 1, 4, -1);
//	cout << sumOdd(0, N - 1, 1, 4, 6);
	
	cin >> M;
	for (int i = 0; i < M; i++) {
		int q, l ,r;
		cin >> q >> l >> r;
		switch(q) {
			case 1: {
				int dif = 0;
				if(r % 2 == 0 && a[l - 1] % 2 == 1) {
					a[l - 1] = r;
					updateOdd(0, N - 1, 1, l - 1, -1);
				}
				else if(r % 2 == 1 && a[l - 1] % 2 == 0){
					a[l - 1] = r;
					updateOdd(0, N - 1, 1, l - 1, 1);
				}
				else;
				
				break;
			}
			case 2: {
				int abstract = r - l + 1;
				cout << abstract - sumOdd(0, N - 1, 1, l - 1, r - 1) << '\n';
				break;
			}
			case 3: {
				cout << sumOdd(0, N - 1, 1, l - 1, r - 1) << '\n';
				break;
			}
		}
		
	}
	return 0;
}
