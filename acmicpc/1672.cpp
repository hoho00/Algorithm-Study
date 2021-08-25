#include <iostream>
#include <string>
#include <stack>

using namespace std;

int a[4][4] = {{0, 2, 0, 1}, {2, 1, 3, 0}, {0, 3, 2, 1}, {1, 0, 1, 3}};

int dnaToInt(char c) {
	if(c == 'A') {
		return 0;
	}
	if(c == 'G') {
		return 1;
	}
	if(c == 'C') {
		return 2;
	}
	if(c == 'T') {
		return 3;
	}
	return -1;
}

char dnaToChar(int n) {
	if(n == 0) {
		return 'A';
	}
	if(n == 1) {
		return 'G';
	}
	if(n == 2) {
		return 'C';
	}
	if(n == 3) {
		return 'T';
	}
	return 'X';
}

int main()
{
	int n;
	scanf("%d", &n);
	string input;
	cin >> input;
	stack<char> s;
	for (int i = 0; i < n; i++){
		char c;
		c = input.at(i);
		s.push(c);
	}
	
	while (s.size() > 1) {
		char last = s.top();
		s.pop();
		char pre = s.top();
		s.pop();
		int res = a[dnaToInt(pre)][dnaToInt(last)];
		s.push(dnaToChar(res));
	}
	char dna = s.top();
	printf("%c", dna);
	return 0;
}
