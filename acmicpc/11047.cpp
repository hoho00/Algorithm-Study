#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, k, count = 0;
	cin >> n >> k;
	vector<int> coin;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		coin.push_back(tmp);
	}
	
	//sort(coin.begin(), coin.end(), compare);
	
	for (int i = n - 1; i >= 0; i--) {
		if(k >= coin[i]) {
			while(1) {
				if(k - coin[i] < 0) {
					break;
				}
				k -= coin[i];
				count++;
				//cout << coin[i] << ' ';
				
			}
		}
	}
	
	cout << count;
	
	return 0;
}
