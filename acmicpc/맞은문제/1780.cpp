#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;


int a[3000][3000];
int cnt[3];

//배열의 모든 값들이 같으면 true, 다르면 false를 return 한 
bool same(int x, int y, int n) {
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if(a[x][y] != a[i][j]) {
				return false;
			}
		}
	}
	return true;
}


void solve (int x, int y, int n) {
	//모든 배열의 값이 다 같을 때 
	if(same(x, y, n)) {
		cnt[a[x][y] + 1] += 1; // cnt값에다가 +1 
		return;
	}
	//모든 배열의 값이 같지 않을 때
	
	// 종이를 9조각으로 나눈다. 
	
	/*
	0 1 2
	3 4 5
	6 7 8
	*/
	
	int m = n / 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			solve(x + i * m, y + j * m, m);
		}
	} 
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	
	solve(0, 0, n);
	
	for (int i = 0; i < 3; i++) {
		printf("%d\n", cnt[i]);
	}
	
	return 0;
}
