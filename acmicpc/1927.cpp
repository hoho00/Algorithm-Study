#include <iostream>
#include <functional>
#include <queue>
#include <vector>

using namespace std;

int n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); 
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		if (input == 0) {
			if(pq.empty()) {
				cout << 0 << '\n';
			}
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else {
			pq.push(input);
		}
	}
	return 0;
}
