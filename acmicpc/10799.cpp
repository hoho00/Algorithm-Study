#include <iostream>
#include <cstdio>
#include <stack>
#include <string>

using namespace std;

int main()
{
	stack<char> st;
	string input_str;
	int count = 0;
	int sticks = 0;
	ios::sync_with_stdio (false); 
	cin.tie (0);
	
	cin >> input_str;
	
	for (int i = 0; i < input_str.size(); i++) {
		if (input_str.at(i) == '(') {
			st.push(input_str.at(i));
		}
		
		else if (input_str.at(i) == ')') {
			if(input_str.at(i - 1) == '(' ) {
				st.pop();
				count += st.size();
			}
			else {
				st.pop();
				count++;
			}
		}
	}
	
	cout << count;
	return 0;
}
