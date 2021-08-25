#include <iostream>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	for (int k = 0; k < T; k++) {
		int n;
		long long max = 1;
		scanf("%d", &n);
		while (1) {
			if (n > max) {
				max = n;
			}
			if (n == 1) {
				printf("%d\n", max);
				break;
			}
			
			if (n % 2 == 0) {
				n /= 2;
			}
			
			else {
				n = n * 3 + 1;
			}
		}
		
	}
	return 0;
}
