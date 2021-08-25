#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	double ans = - 1;
	cin >> n;
	vector<double> v(n);
	double dp[10001] = {0};
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		dp[i] = v[i];
	}
	
	for (int i = 0; i < n; i++) {
		double tmpAnswer = dp[i];
		for (int j = i - 1; j >= 0; j--) {
			if(tmpAnswer < dp[i] * v[j]) {
				tmpAnswer = dp[i] * v[j];
			}
			dp[i] = dp[i] * v[j];
		}
		if(ans < tmpAnswer) {
			ans = tmpAnswer;
		}
	}
	printf("%0.3f", ans);
	return 0;
}
