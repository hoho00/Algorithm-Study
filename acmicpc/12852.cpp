#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

int N;
int a[1000001];
deque<int> visited;
int vis[1000001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	
	a[1] = 0;
	visited[1] = -123;
	for (int i = 2; i <= N; i++) {
		a[i] = a[i - 1] + 1;
		//visited.push_back(i - 1);
		vis[i - 1] = i;
		
		if(i % 3 == 0) {
			if(a[i] > a[i / 3] + 1) {
				a[i] = a[i / 3] + 1;
//				visited.pop_back();
//				visited.push_back(i / 3);
				vis[i/3] = i;
			}
		}
		if (i % 2 == 0) {
			if(a[i] > a[i/2] + 1) {
				a[i] = a[i / 2] + 1;
//				visited.pop_back();
//				visited.push_back(i / 2);
				vis[i/2] = i;
			}
		}
	}
	cout << a[N] << "\n";
	while(N != -123) {
		cout << N << " ";
		N = vis[N];
	}
	return 0;
}
