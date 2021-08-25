#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> v;
	int d1, d2, d3;
	scanf("%d %d %d", &d1, &d2, &d3);
	v.push_back(d1);
	v.push_back(d2);
	v.push_back(d3);
	
	sort(v.begin(), v.end());
	//printf("%d %d %d\n", v[0], v[1], v[2]);
	if(v[2] >= v[0] + v[1]) {
		printf("-1");
	}
	else {
		printf("1\n");
		printf("%.1f %.1f %.1f", (float)(d1 + d2 - d3) / 2, (float)(d1 + d3 - d2) / 2, (float)(d2 + d3 - d1) / 2);
	}
	
	return 0;
}
