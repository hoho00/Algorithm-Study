#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(int n, int k, vector<string> cmd) {
	stack<int> deleted;
	string str = "";
	int curIndex = k;
	for (int i = 0; i < n; i++) {
		str.push_back('O');
	}
	
	for (int i = 0; i < cmd.size(); i++) {
		if (cmd[i][0] == 'U') {
			int moving = cmd[i][2] - '0';
			while(moving > 0) {
				if(str[curIndex] == 'X') {
					curIndex --;
				}
				else {
					curIndex--;
					moving--;
				}
			}
		}
		
		else if (cmd[i][0] == 'D') {
			int moving = cmd[i][2] - '0';
			while(moving > 0) {
				if(str[curIndex] == 'X') {
					curIndex ++;
				}
				else {
					curIndex++;
					moving--;
				}
			}
		}
		
		else if (cmd[i][0] == 'C') {
			str[curIndex] = 'X';
			deleted.push(curIndex);
			if(curIndex == str.size()) curIndex--;
			else curIndex ++;
			
		}
		
		else if (cmd[i][0] == 'Z') {
			str[deleted.top()] = 'O';
			deleted.pop();
		}
	}
	return str;
}

int main()
{
	int n, k;
	vector<string> cmd;
	string test = "";
	cin >> n >> k;
	for (int i = 0; i < 10; i++) {
		string tmp;
		getline(cin, tmp);
		cmd.push_back(tmp);
	}
	
	cout << solution(n, k, cmd);
	return 0;
}
