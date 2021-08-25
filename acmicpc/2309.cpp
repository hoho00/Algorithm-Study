#include <iostream>
#include <algorithm>

using namespace std;

int a[10];


int main()
{
	int sum = 0;
	for (int i = 0; i < 9; i++) {
		cin >> a[i];
		sum += a[i];
	}
	int flag = -1;
	sum -= 100;
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
	for (int i = 0; i < 9; i++) {
		if(a[i] > 0) {
			cout << a[i] << '\n';
		}
		
		
	}
	
	return 0;
}
