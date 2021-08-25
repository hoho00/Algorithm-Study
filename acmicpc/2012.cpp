#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> v;
	map<int, int> m;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	long long ans = 0;
	for (int i = 0; i < N; i++) {
		ans += abs(v[i] - (i + 1));
	}
	cout << ans;
	return 0;
}
