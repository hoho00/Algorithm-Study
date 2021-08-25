#include <iostream>

using namespace std;

int a[302];
int n, m;



int main()
{
	
	cin >> n >> m;
	a[1] = n - 1;
	for (int i = 2; i <= m; i++) {
		a[i] = a[i - 1] + a[1] + 1;
	}
	
	cout << a[m];
	return 0;
}
