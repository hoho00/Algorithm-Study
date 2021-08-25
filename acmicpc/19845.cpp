#include <iostream>

using namespace std;

int a[250001];

int bSearch(int low, int high, int n) {
	if(low > high) {
		return 0;
	}
	int mid = (low + high) / 2;
	if (n > a[mid]) bSearch(mid + 1, high, n);
	else if (n < a[mid]) bSearch(low, mid, n);
	else if (n == a[mid]) return a[mid];
	return a[mid];
}

int main()
{
	int N, Q;
	scanf("%d %d", &N, &Q);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &a[i]);
	}
	int sum = 0;
	for (int i = 0; i < Q; i++) {
		int x ,y;
		scanf("%d %d", &x, &y);
		sum += (a[y] - x);
		if(a[N] >= x) {
			sum += (N - y);
		}
		else {
			sum += (N - y - 1);
		}
		sum++;
		if(sum < 0 || a[y] < x) {
			sum = 0;
		}
		printf("%d\n", sum);
		sum = 0;
	}
	return 0;
}
