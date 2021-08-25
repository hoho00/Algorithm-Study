#include <iostream>
#include <cstdio>

using namespace std;

//n���� ������ �ִµ� x���� y�� �ű�� �ʹ�. 
void solve (int n, int x, int y) {
	//Ż������
	if(n == 0) return; 
	//���� n-1���� ������ x���� z�� �Űܾ� �Ѵ�.
	//z�� ���ϴ� ������ 6 - x - y�̴�. �ֳĸ� ����� �ѹ����� 1, 2, 3�̱� �����̴�.
	solve(n - 1, x, 6 - x - y);
	printf("%d %d\n", x, y);
	solve(n - 1, 6 - x - y, y);
}

int main()  
{
	int n;
	scanf("%d", &n);
	// 2�� n���� ���ϰ� ������ 1 << n�� ����ض�!! 
	printf("%d\n", (1 << n) - 1);
	solve(n, 1, 3);
	return 0;
}
