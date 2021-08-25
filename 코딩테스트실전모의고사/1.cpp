#include <iostream>
#include <string>
#define INT_MAX 987654321

using namespace std;

string s[31];

int main()
{
	ios_base::sync_with_stdio(false);
	int n, minString = INT_MAX, minStringIndx = 0;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		string inputTmp;
		cin >> inputTmp;
		s[i] = inputTmp;
		if(minString > inputTmp.size()) {
			minString = inputTmp.size();
			minStringIndx = i;
		}
	}
	
	string tmp = s[minStringIndx];
	//cout << tmp << endl;

	for (int i = 0; i < n; i++) {
		while(s[i].find(tmp) == string::npos) {
			tmp.pop_back();
		}
	}
	
	
	cout << tmp;
	return 0;
}
