#include <iostream>
#include <string>

using namespace std;

int a[51][51];
int b[51][51];
int n, m, count = 0;

void flipOver(int x, int y) {
	if(x + 3 >= m || y + 3 >= n) {
		return;
	}
	for (int i = y; i < y + 3; i++) {
		for (int j = x; j < x + 3; j++) {
			if(a[i][j] == 0) {
				a[i][j] = 1;
			} else {
				a[i][j] = 0;
			}
		}
	}
}

bool checkEqual() {
	
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] != b[i][j]) {
				return false;
			}
		}
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	
	for (int i = 0 ; i < n; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < m; j++) {
			a[i][j] = (int)tmp[j] - '0';
		}
	}
	
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < m; j++) {
			b[i][j] = (int)tmp[j] - '0';
		}
	}
	bool equal = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if(a[i][j] != b[i][j]) {
				flipOver(i, j);
				count ++;
			}
			if(checkEqual()) {
				equal = true;
				break;
			}
		}
		if (equal) break;
	}
	
	cout << count;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			cout << b[i][j] << ' ';
//		}
//		cout << '\n';
//	}
	
	return 0;
}
