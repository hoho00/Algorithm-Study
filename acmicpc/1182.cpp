#include <iostream>

using namespace std;


int n, s, count = 0;
int a[21];

void dfs(int num, int sum) {
	if(num == n) return;
	if(sum + a[num] == s) {
		count++;
	}
	
	dfs(num + 1, sum);
	dfs(num + 1, sum + a[num]);
	
	
}

int main()
{
	
	cin >> n >> s;
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	dfs(0, 0);
	cout << count;
	
	return 0;
}
