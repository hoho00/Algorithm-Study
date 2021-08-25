#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

string p[10];


int solution(string s) {
	vector<int> resVector;
	
	p[0] = "zero";
	p[1] = "one";
	p[2] = "two";
	p[3] = "three";
	p[4] = "four";
	p[5] = "five";
	p[6] = "six";
	p[7] = "seven";
	p[8] = "eight";
	p[9] = "nine"; 
	
	string tmp = "";
	
	for (int i = 0; i < s.size(); i++) {
		if(s[i] <= '9' && s[i] >= '0') {
			resVector.push_back(int(s[i] - '0'));
		}
		else {
			tmp += s[i];
			for (int j = 0; j < 10; j++) {
				if(p[j].compare(tmp) == 0) {
					resVector.push_back(j);
					tmp = "";
				}
			}
		}
	}
	
	int res = 0;
	for (int i = 0; i < resVector.size(); i++) {
		res *= 10;
		res += resVector[i];
	}
	
	return res;
}

int main()
{
	string s;
	cin >> s;
	
	cout << solution(s);
	return 0;
}
