#include <iostream>
#include <string>
#include <queue>
using namespace std;

int alphabet[30];

int main()
{
	string s, t;
	cin >> s >> t;
	int tSize = t.size();
	queue<char> q;
	for (int i = 0; i < tSize; i++) {
		alphabet[t[i] - 'a']++;
	}
	for (int i = 0; i < tSize; i++) {
		
	}
	for (int i = 0; i < s.size(); i++) {
		
	}
	return 0;
}
