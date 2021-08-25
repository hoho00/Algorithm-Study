#include <iostream>
#include <vector>

using namespace std;

int dp[1001];

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> p(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		dp[i] = p[i];
	}
	
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if(dp[i] > p[j] + dp[i - j]) {
				dp[i] = p[j] + dp[i - j];
			}
		}
	}
	
	cout << dp[n];
	return 0;
}
