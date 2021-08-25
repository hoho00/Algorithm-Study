#include <iostream>
#include <stack>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	long long count = 0;
	cin >> n;
	stack<int> s;
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		
		if(i == 0) {
			s.push(input);
		}
		else {
			if(s.top() < input) {
				while(1){
					s.pop();
					if(!s.empty() && s.top() >= input) {
						count++;
						break;
					}
				}
				s.push(input);
				count++;
			}
			else if (s.top() == input) {
				while(1){
					s.pop();
					if(!s.empty() && s.top() >= input) {
						count++;
						break;
					}
				}
				s.push(input);
				count++;
			}
			else {
				s.push(input);
				count++;
			}
		}
	}
	
	cout << count;
	return 0;
}
