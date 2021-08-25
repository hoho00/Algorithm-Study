#include <iostream>

using namespace std;

long long a[100001][4];
const int d = 1000000009;

int main()
{
	int T;
	scanf("%d", &T);
	a[1][1] = 1;
	a[2][1] = 0;
	a[2][2] = 1;
	a[3][1] = 1;
	a[3][2] = 1;
	a[3][3] = 1;
	a[4][1] = 2;
	a[4][2] = 0;
	a[4][3] = 1;
	
	for (int k = 0; k < T; k++) {
		int n;
		scanf("%d", &n);
		for (int i = 5; i <= n; i++) {
			a[i][1] = a[i - 1][2] + a[i - 1][3];
			a[i][1] %= d;
			a[i][2] = a[i - 2][1] + a[i - 2][3];
			a[i][2] %= d;
			a[i][3] = a[i - 3][1] + a[i - 3][2];
			a[i][3] %= d;
		}
		printf("%d\n", ((a[n][1] % d) + (a[n][2] % d) + (a[n][3] % d)) % d);
	}
	return 0;
}
