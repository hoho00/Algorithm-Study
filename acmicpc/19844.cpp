#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isMoum(char c) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'h';
}

bool isDan(string s) {
	return s == "c'" || s == "j'" || s == "n'" || s == "m'" || s == "t'" || s == "s'" || s == "l'" || s == "d'" || s == "qu'";
}



int main()
{
	string input_str;
	int sum = 0;
	getline(cin, input_str, '\n');
	//cout << input_str << endl;
	int size = input_str.size();
	string s = "";
	for (int i = 0; i < size; i++) {
		//string tmp(input_str.at(i));
		s += input_str.at(i);
		if(isDan(s)) {
			if(isMoum(input_str.at(i + 1))) {
				s = "";
				sum++;
			}
			
		}
		else if (input_str.at(i) == '-'){
			//cout << "hey\n";
			s = "";
			sum++;
		}
		else if (input_str.at(i) == ' ') {
			//cout << "hey\n";
			s = "";
			sum++;
		}
	}
	
	cout << sum + 1;
	
	return 0;
}
