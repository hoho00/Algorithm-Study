#include <iostream>

using namespace std;

pair<int, int> a[21];
pair<int, int> dp[21];
int main()
{
	int N;
	cin >> N;
	//first는 체력, second는 기쁨 
	for (int i = 0; i < N; i++) {
		cin >> a[i].first; 
	}
	for (int i = 0; i < N; i++) {
		cin >> a[i].second;
	}
	
	if(a[0].first >= 100) {
		dp[0].first = 0;
		dp[0].second = 0;
	}
	else {
		dp[0].first = a[0].first;
		dp[0].second = a[0].second;
	}
	
	for (int i = 1; i < N; i++) {
		if(a[i].first >= 100) {
			dp[i].first = dp[i - 1].first;
			dp[i].second = dp[i - 1].second;
			continue;
		}
		if(dp[i - 1].first + a[i].first >= 100) {
			if(dp[i - 1].second > a[i].second) {
				dp[i].first = dp[i - 1].first;
				dp[i].second = dp[i - 1].second;
			}
			else if(dp[i - 1].second == a[i].second){
				dp[i].first = min(dp[i - 1].first, a[i].first);
				dp[i].second = a[i].second;
			}
			else {
				dp[i].first = a[i].first;
				dp[i].second = a[i].second;
			}
		}
		else {
			dp[i].first = dp[i - 1].first + a[i].first;
			dp[i].second = dp[i - 1].second + a[i].second;
		}
	}
	cout << dp[N - 1].second;
	return 0;
}
