#include <iostream>
#include <cstdio>

using namespace std;

//n개의 원판이 있는데 x에서 y로 옮기고 싶다. 
void solve (int n, int x, int y) {
	//탈출조건
	if(n == 0) return; 
	//먼저 n-1개의 원판을 x에서 z로 옮겨야 한다.
	//z를 구하는 공식은 6 - x - y이다. 왜냐면 장대의 넘버링이 1, 2, 3이기 때문이다.
	solve(n - 1, x, 6 - x - y);
	printf("%d %d\n", x, y);
	solve(n - 1, 6 - x - y, y);
}

int main()  
{
	int n;
	scanf("%d", &n);
	// 2의 n승을 구하고 싶으면 1 << n을 사용해라!! 
	printf("%d\n", (1 << n) - 1);
	solve(n, 1, 3);
	return 0;
}
