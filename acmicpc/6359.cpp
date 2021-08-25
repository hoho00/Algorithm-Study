#include <iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int k = 0; k < T; k++) {
		int n;
		int count = 0;
		cin >> n;
		
		int* a = new int[n + 1];
		for (int i = 0; i <= n; i++) {
			a[i] = 0;
		}
		
		for (int i = 2; i <= n; i++) {
			int j = i;
			int c = 1;
			while(1) {
				int indx = j * c;
				if(indx > n) {
					break;
				}
				a[indx]++;
				c++;
			}
		}
		
		for (int i = 1; i <= n; i++) {
			if(a[i] == 0 || a[i] % 2 == 0) {
				count ++;
			}
		}
		
		cout << count << endl;
	}
	return 0;
}
