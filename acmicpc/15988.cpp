#include<iostream>

using namespace std;
long long a[1000001];

int main()
{
	int T;
	scanf("%d", &T);
	a[1] = 1;
	a[2] = 2;
	a[3] = 4;
	for (int i = 0; i < T; i++) {
		int n;
		scanf("%d", &n);
		for(int i = 4; i <= n; i++) {
			a[i] = a[i - 1] + a[i - 2] + a[i - 3];
			a[i] = (a[i]) % 1000000009;
		}
		printf("%d\n", (a[n]) % 1000000009);
	}
	return 0;
}
