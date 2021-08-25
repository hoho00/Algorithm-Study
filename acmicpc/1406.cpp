#include <iostream>
#include <cstdio>
#include <string>
#include <list>

using namespace std;

char s[600001];

int main()
{
	ios::sync_with_stdio(false);
   	cin.tie(NULL);
   	
   	list<char> l;
   	
	string input;
	cin >> input;
	int cursor = input.size();
	for (int i = 0; i < cursor; i++) {
		s[i] = input.at(i);
	}
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		string command;
		cin >> command;
		if(command.compare("L")) {
			
		}
		
		else if (command.compare("D")) {
			
		}
		
		else if (command.compare("B")) {
			
		}
		
		else if (command.compare("P")) {
			
		}
		
		else;
	}
	
	return 0;
}
