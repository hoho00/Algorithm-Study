#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	cin >> s;
	int sum = 0;
	for (int i = 0; i < s.size(); i++) {
		string tmp = "";
		while(isdigit(s[i])) {
			tmp += s[i];
			i++;
		}
		//cout << tmp << endl;
		while(tmp[0] == '0') tmp = tmp.substr(1);
		//cout << tmp << endl;
		sum += stoi(tmp);
	}
	cout << sum;
	return 0;
}
