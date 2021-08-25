#include <iostream>
#include <limits.h>

using namespace std;

int P[1001];
int a[1001];

int main()
{
	int n;
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++) {
		scanf("%d", &P[i]);
	}
	a[0] = 0;
	a[1] = P[1];
	for (int i = 2; i <= n; i++) {
		int min = INT_MAX;
		for(int j = 0; j < i; j++) {
			if((a[j] + P[i - j]) < min) {
				min = a[j] + P[i - j];
			}
		}
		a[i] = min;
	}
	printf("%d", a[n]);
	return 0;
}
