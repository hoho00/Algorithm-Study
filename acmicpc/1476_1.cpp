#include <iostream>

using namespace std;

int main()
{
	int E, S, M;
	
	scanf("%d %d %d", &E, &S, &M);
	
	if(E == 1 && S == 1 && M == 1) {
		printf("1");
	}
	else {
		int x = 1;
		while (1) {
			if (x % 15 == (E - 1) && x % 28 == (S - 1) && x % 19 == (M - 1)) {
				printf("%d", x + 1);
				break;
			}
			x++;
		}
		
	}
	return 0;
}
