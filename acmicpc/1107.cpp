#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n, m;
set<int> s;
int a[10];

int main()
{
	scanf("%d", &n);
	scanf("%d", &m);
	
	for (int i = 0; i < m; i++) {
		int b;
		scanf("%d", &b);
		s.insert(b);
	}
	int button = 0;
	int ch = 100;
	
	int tmp = n;
	int level = 0;
	while (1) {
		printf("%d\n", tmp%10);
		if(tmp == 0) {
			break;
		}
		tmp /= 10;
		level++;
	}
	
	
//	while(1) {
//		tmp = n;
//		if(tmp == ch) {
//			break;
//		}
//		ch++;
//		while (1) {
//			if(tmp == 0) {
//				break;
//			}
//			tmp /= 10;
//			
//		}
//	}
	
	//printf("%d", button);
	
	return 0;
}
