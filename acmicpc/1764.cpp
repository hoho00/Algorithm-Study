#include <iostream>
#include <string>
#include <set>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	set<string> s1, s2;
	priority_queue<string, vector<string>, greater<string>> q;
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		s1.insert(tmp);
	}
	
	for (int i = 0; i < m; i++) {
		string tmp;
		cin >> tmp;
		s2.insert(tmp);
	}
	
	for (set<string> ::iterator iter = s2.begin(); iter != s2.end(); iter++) {
		if(s1.find(*iter) != s1.end()) {
			q.push(*iter);
		}
		else {
			
		}
	}
	cout << q.size() << '\n';
	while(!q.empty()) {
		cout << q.top() << '\n';
		q.pop();
	}
	return 0;
}
