#include <iostream>
#include <string>
#include <map>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	map<string, string> h;
	priority_queue<string> member;
	priority_queue<string> memberLeft;
	for (int i = 0; i < n; i++) {
		string name, cmd;
		cin >> name >> cmd;
		member.push(name);
		if(cmd.compare("leave") == 0) {
			memberLeft.push(name);
		}
	}
	
	while(!member.empty()) {
		if(!memberLeft.empty() && member.top().compare(memberLeft.top()) == 0) {
			member.pop();
			member.pop();
			memberLeft.pop();
		}
		else {
			cout << member.top() << '\n';
			member.pop();
		}
	}
	return 0;
}
