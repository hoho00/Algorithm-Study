#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<pair<int, int>> v;
	v.push_back(make_pair(0, 0));
	for (int i = 1; i <= N; i++) {
		int a;
		cin >> a;
		v.push_back(make_pair(a, 0));
	}
	//vector<int> max;
	
	//max.push_back(0);
	stack<int> max;
	for (int i = 1; i < v.size(); i++) {
		if (v[i].first < v[i - 1].first) {
			v[i].second = i - 1;
			max.push(i - 1);
		}
		else {
			while(!max.empty()) {
				if(v[max.top()].first > v[i].first) {
					v[i].second = max.top();
					max.push(i);
					break;
				}
				else {
					max.pop();
				}
			}
//			for (int j = max.size() - 1; j >= 0; j--) {
//				if(v[max[j]].first > v[i].first) {
//					v[i].second = max[j];
//					//cout << max[j] << endl;
//					break;
//				}
//			}
//			max.push_back(i);
		}
	}
	
	for (int i = 1; i < v.size(); i++) {
		cout << v[i].second << " ";
	}
	return 0;
}
