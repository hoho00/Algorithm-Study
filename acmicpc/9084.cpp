#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	while(T > 0) {
		int n, m;
		cin >> n;
		vector<int> v(n + 1);
		for (int i = 1; i <= n; i++) {
			cin >> v[i];
		}
		cin >> m;
		int dp[m + 1] = {0};
		dp[0] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = v[i]; j <= m; j++) {
				dp[j] += dp[j - v[i]]; 
			}
		}
		cout << dp[m] << endl;
		T--;
	}
	return 0;
}
