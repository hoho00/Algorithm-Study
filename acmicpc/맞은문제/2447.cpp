#include <cstdio>

using namespace std;

char a[7000][7000];

void star_fill(int x, int y, int n, char c) {
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			a[i][j] = c;
		}
 	}
}

void solve(int x, int y, int n, char c) {
	if(n == 1) {
		a[x][y] = c;
		return;
	}
	
	if (c == ' ') {
		star_fill(x, y, n, c);
		return;
	}
	
	star_fill(x, y, n, c);
	
	int m = n / 3;
	char newChar;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if(i == 1 && j == 1) {
				newChar = ' ';
			}
			
			else {
				newChar = '*';
			}
			
			solve(x + m * i, y + m * j, m, newChar);
		}
	}
}


int main()
{
	int n;
	scanf("%d", &n);
	//star_fill(0, 0, n, '%');
	solve(0, 0, n, '*');
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%c", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
