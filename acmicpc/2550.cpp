#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <algorithm>

using namespace std;
int dp[10001];
int main()
{
	int N;
	cin >> N;
	vector<int>v;
	vector<int> v1;
	vector<int> v2(N + 1);
	vector<int>lis;
	map<int, int> m;
	vector<pair<int, int>> vCheck;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
		m[tmp] = i;
	}
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		v2[i] = m[tmp];
	}
	lis.push_back(v2[0]);
	vCheck.push_back(make_pair(v2[0], 0));
	for (int i = 1; i < N; i++) {
		if(lis.back() < v2[i]) {
			lis.push_back(v2[i]);
			vCheck.push_back(make_pair(v2[i], lis.size() - 1));
		}
		else {
			int a = lower_bound(lis.begin(), lis.end(), v2[i]) - lis.begin();
			lis[a] = v2[i];
			vCheck.push_back(make_pair(v2[i], a));
		}	
	}
	cout << lis.size() << endl;
	
	int secondC = lis.size() - 1;
	vector<int>res;
	for(int i = vCheck.size() - 1; i >= 0; i--) {
		if(vCheck[i].second == secondC) {
			//cout << vCheck[i].first << " ";
			secondC--;
			res.push_back(v[vCheck[i].first]);
		}
	}
	sort(res.begin(), res.end());
	for(auto e : res) {
		cout << e << " ";
	}
	return 0;
}
