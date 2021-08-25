#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <map>

using namespace std;

int N, H;

int compare(int a, int b) {
	return a > b;
}
int main()
{
	vector<int> up;
	vector<int> down;
	map<int, int> minCount;
	cin >> N >> H;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		if(i % 2 == 0) up.push_back(tmp);
		else down.push_back(H - tmp);
	}
	
	sort(up.begin(), up.end());
	sort(down.begin(), down.end());
	//reverse(down.begin(), down.end());
	
	int min = INT_MAX;
	for (int i = 1; i <= H; i++) {
		//cout << upper_bound(up.begin(), up.end(), i) - up.begin() << " ";
		int upcount =  N/2 - (upper_bound(up.begin(), up.end(), i - 1) - up.begin());
		int downcount =  (lower_bound(down.begin(), down.end(), i) - down.begin());
		int sum = upcount + downcount;
		//cout << "i : "<< i << " up :  " << upcount << " down : " <<downcount<< endl;
		if (min >= sum) {
			min = sum;
			minCount[min]++;
		}
		
	}
	cout << min << " " << minCount[min];
	
	
	return 0;
}
