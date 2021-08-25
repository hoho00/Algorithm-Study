#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;
	vector<int> v;
	
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	long long low = v[0];
	long long high = v[0] + K;
	long long answer = 0;
	while (low <= high) {
		long long mid = (low + high) / 2;
		long long sum = 0;
		for (int i = 0; i < N; i++) {
			if(mid - v[i] > 0) {
				sum += mid - v[i];
			}
			else {
				break;
			}
		}
		if(sum > K) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
			answer = mid;
		}
	}
	cout << answer;
	return 0;
}
