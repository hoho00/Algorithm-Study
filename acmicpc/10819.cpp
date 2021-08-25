#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> v;

int main()
{
	int n;
	int maxSum = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		v.push_back(tmp);
	}
	
	sort(v.begin(), v.end());
	while(next_permutation(v.begin(), v.end())) {
		int sum = 0;
		for (int i = 1; i < v.size(); i++) {
			sum += abs(v[i - 1] - v[i]);
		}
		if (maxSum < sum) {
			maxSum = sum;
		}
	}
	printf("%d", maxSum);
	return 0;
}
