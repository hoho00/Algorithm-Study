#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2) {
	return p1.first < p2.first;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	while(T != 0) {
		int N;
		cin >> N;
		vector<pair<int, int>> v;
		for (int i = 0; i < N; i++) {
			int a, b;
			cin >> a >> b;
			v.push_back(make_pair(a, b));
		}
		sort(v.begin(), v.end(), compare);
		int count = 1;
		int interview = v[0].second;
		for (int i = 1; i < v.size(); i++) {
			if(v[i].second < interview) {
				interview = v[i].second;
				count++;
			}
		}
		cout << count << '\n';
		T--;
	}
	return 0;
}
