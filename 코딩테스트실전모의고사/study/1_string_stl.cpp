#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

int main()
{
	string a = "it is time to study", res;
	int maxLen = 0, pos;
	while (1) {
		pos = a.find(' ');
		if(pos == std::string::npos) {
			break;
		}
		string tmp = a.substr(0, pos);
	} 
	
	cout << res << endl;
	
	return 0;
}
