#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		v.push_back(tmp);
	}
	if(next_permutation(v.begin(), v.end())) {
		for (int i = 0; i < v.size(); i++) {
			printf("%d ", v[i]);
		}
	}
	
	else {
		printf("-1");
	}
	
	return 0;
} 
