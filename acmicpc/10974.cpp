#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

char input[16];
char output[16];
int isVisited[16];
int L, C;

void combination(int index, int n, int r, int target) {
	if(r == 0) {
		int jCount = 0; 
		int mCount = 0;
		for (int i = 0; i < index; i++) {
			if(output[i] == 'a' || output[i] == 'e' || output[i] == 'i' || output[i] == 'o' || output[i] == 'u') {
				mCount++;
			}
			else {
				jCount++;
			}
		}
		
		if(mCount >= 1 && jCount >= 2) {
			for (int i = 0; i < index; i++) {
				printf("%c", output[i]);
			}
			printf("\n");
		}
	}
	
	else if(target == n) return;
	
	else {
		output[index] = input[target];
		combination(index + 1, n, r - 1, target + 1);
		combination(index, n, r, target + 1);
	}
}

int main()
{
	
	cin >> L >> C;
	
	for (int i = 0; i < C; i++) {
		cin >> input[i];
	}
	
	sort(input, input + C);
	
	combination(0, C, L, 0);
	
	return 0;
}
