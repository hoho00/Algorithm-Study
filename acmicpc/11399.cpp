#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, res = 0;
	vector<int> a;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		a.push_back(tmp);
	}
	
	sort(a.begin(), a.end());
	
	for (int i = 0; i < n; i++) {
		for (int j = i; j >= 0; j--) {
			res += a[j];
		}
	}
	
	cout << res;
	return 0;
}
