#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	cin >> n;
	string out = "";
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if(i == 0) {
			out.append(s);
		}
		
		else {
			for (int j = 0; j < s.size(); j++) {
				if(out.at(j) != s.at(j)) {
					out[j] = '?';
				}
			}
		}
	}
	cout << out;
	return 0;
}
