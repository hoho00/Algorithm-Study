#include <iostream>

using namespace std;

int main()
{
	int a, b, c;
	int x = 1;
	
	scanf("%d %d %d", &a, &b, &c);
	while(1) {
		if(a == 1 && b == 1 && c== 1) {
			printf("%d", x);
			break;
		}
		if((x) % 15 == (a - 1) && (x) % 28 == (b - 1) && (x) % 19 == (c - 1)) {
			printf("%d", x + 1);
			break;
		}
		//printf("%d\n", x);
		x++;
		
	}
	return 0;
}
