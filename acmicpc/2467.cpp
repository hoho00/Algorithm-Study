#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> v;
	for(int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	int i = 0;
	int j = N - 1;
	int minNum = INT_MAX;
	int lowRes = 0;
	int highRes = 0;
	while(i < j) {
		int low = v[i];
		int high = v[j];
		if(minNum > abs(low + high)) {
			lowRes = i;
			highRes = j;
			minNum = abs(low + high);
		}
		if (low + high > 0) {
			j--;
		}
		else {
			i++;
		}
	}
	cout << v[lowRes] << " " << v[highRes];
	
	return 0;
}
