#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int dp[101][10001];

int main()
{
	ios_base::sync_with_stdio(false);
	int T, k;
	cin >> T;
	cin >> k;
	vector<pair<int, int>> v;
	
	for (int i = 0; i < k; i++) {
		int p, n;
		cin >> p >> n;
		v.push_back(make_pair(p, n));
	}
	
	for (int i = 0; i < k; i++) {
		dp[i][0] = 1;
	}
	sort(v.begin(), v.end());
	
//	for (int i = 0; i < k; i++) {
//		cout << v[i].first << ' ' << v[i].second << endl;
//	}
		
	for (int i = 0; i < k; i++) {
		for (int j = 1; j <= T; j++) {
			for (int l = 1; l <= v[i].second; l++) {
				if(i == 0) {
					if(j - v[i].first * l >= 0) {
						dp[i][j] = dp[i][j - v[i].first * l];
					}
					
				}
				else {
					if(j - v[i].first * l >= 0) {
						dp[i][j] = dp[i][j - v[i].first * l] + dp[i - 1][j];
					}
					
				}
			}
		}
	}
	for (int i = 0; i < k; i++) {
		for (int j = 0; j <= T; j++) {
			cout << dp[i][j] << ' ';
		}
		cout << endl;
	}
	cout << dp[k - 1][T];
	return 0;
}
