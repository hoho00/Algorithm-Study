#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int w[11][11];
int visit[11] = {0, };
int sum = 0;
vector<int> d;


int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &w[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		d.push_back(i+1);
	}
	
	do {
		for (int i = 0; i < n; i++) {
			printf("%d ", d[i]);
		}
		printf("\n");
	}while(next_permutation(d.begin(), d.end()));
	printf("%d", sum);
	return 0;
}
