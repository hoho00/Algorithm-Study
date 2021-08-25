#include <iostream>
#include <vector>

using namespace std;

int N;
int a[1000001];
int b[1000001];
int bCount = 1;

//int findL(int low, int high, int target) {
//	int mid = (low + high) / 2;
//	if(low >= high) {
//		return low;
//	}
//	if(v[mid] >= target) {
//		return findL(low, mid - 1, target);
//	}
//	else {
//		return findL(mid + 1, high, target);
//	}
//}

int myLowerBound(int target) {
	int low = 0, high = bCount - 1, mid;
	for(;;) {
		if(low > high) break;
		mid = (low + high) / 2;
		
		if(b[mid] >= target) high = mid - 1;
		else low = mid + 1;
	}
	return low;
}

int my_lower_bound(int n)
{
	int f = 0, l = bCount - 1, m;

	for (;;)
	{
		if (f > l) break;
		m = (f + l) / 2;
		
		if (b[m] >= n) l = m - 1;
		else f = m + 1;
	}

	return f;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	b[0] = a[0];
	for (int i = 1; i < N; i++) {
		if(b[bCount - 1] < a[i]) {
			b[bCount] = a[i];
			bCount++;
		}
		else {
			int index = myLowerBound(a[i]);
			b[index] = a[i];
		}
	}
	cout << bCount << '\n';
	return 0;
}
	
	
		
//	v.push_back(-1);
//	for (int i = 1; i < N; i++) {
//		int tmp;
//		cin >> tmp;
//		//v.push_back(tmp);
//		if(tmp > v.back()) {
//			v.push_back(tmp);
//			count++;
//		}
//		else {
//			//int index = myLowerBound(tmp);
//			int index = findL(0, v.size() -1, tmp);
//			v[index] = tmp;
//		} 
//	}
//
