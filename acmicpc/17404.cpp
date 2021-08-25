#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>

typedef long long ll;

using namespace std;

int a[1001][3];
ll dp[1001][3];
int rgbIndx [1001];

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i][0] >> a[i][1] >> a[i][2];
	}
	for (int i = 0; i < 3; i++) {
		dp[0][i] = a[0][i];
	}
	ll ans = LLONG_MAX;
	int starter[3] = {a[0][0], a[0][1], a[0][2]};
	//starter 중 하나를 고정 시키고 시작 
	for (int i = 0; i < 3; i++) {
		dp[1][i] = 1e9;
		for (int j = 0; j < 3; j++) {
			if(j == i) continue;
			dp[1][j] = starter[i] + a[1][j];
		}
		
		for (int j = 2; j < N; j++) {
			dp[j][0] = min(dp[j - 1][1], dp[j - 1][2]) + a[j][0];
			dp[j][1] = min(dp[j - 1][0], dp[j - 1][2]) + a[j][1];
			dp[j][2] = min(dp[j - 1][0], dp[j - 1][1]) + a[j][2];
		}
		
		dp[N - 1][i] = LLONG_MAX;
			
		for (int k = 0; k < 3; k++) {
			if(dp[N - 1][k] < ans) ans = dp[N - 1][k];
		}
		dp[1][i] = 0;
	}
	
	cout << ans;
	return 0;
}
