#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;

	int n = b - a + 1; // 원소 개수
	vector<int> sum(n);

	for (int i = 0, j = a; i < n && j <= b; i++, j++) {
		if (i == 0) sum[i] = j;
		else {
			sum[i] = sum[i - 1] + j;
		}
	}

	cout << sum[n - 1];
	return 0;
}
