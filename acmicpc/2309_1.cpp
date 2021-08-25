#include <iostream>
#include <algorithm>

using namespace std;

int a[10];

int main()
{
	int sum = 0;
	for (int i = 0; i < 9; i++) {
		scanf("%d", &a[i]);
		sum += a[i];
	}
	
	sum -= 100;
	int flag = -1;
	for (int i = 0; i < 9; i++) {
		if(flag == 0) break;
		for (int j = i + 1; j < 9; j++) {
			if(a[i] + a[j] == sum) {
				a[i] = -1;
				a[j] = -1;
				flag = 0;
				break;
			}
		}
	}
	
	sort(a, a+9);
	
	for (int i = 2; i < 9; i++) {
		printf("%d\n", a[i]);
	}
	
	
	return 0;
}
