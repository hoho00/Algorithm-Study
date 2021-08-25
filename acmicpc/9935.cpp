#include <iostream>
#include <cstdio>
#include <string>
#include <stack>

using namespace std;

stack<char> st;
char output[1000001];

void explosion(string input, string bomb) {
	int bomb_size = bomb.size();
	int input_size = input.size();
	int outputIdx = 0;
	
	for (int i = 0; i < input_size; i++) {
		output[outputIdx] = input.at(i);
		int bombIdx = bomb_size - 1;
		bool flag = false;
		int outCount = 0;
		while (1) {
			if(output[outputIdx] != bomb.at(bombIdx)) {
				break;
			}
			outCount++;
			st.push(output[outputIdx]);
			if(bombIdx == 0) {
				flag = true;
				outputIdx--;
				break;
			}
			outputIdx--;
			bombIdx--;
		}
		
		if(flag == false) {
			outputIdx += outCount;
		}
		outputIdx++;
	}
	
	if (outputIdx == 0) {
		cout << "FRULA";
	}
	
	else {
		for (int i = 0; i < outputIdx; i++) {
			cout << output[i];
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string input;
	string bomb;
	
	
	cin >> input;
	cin >> bomb;
	
	explosion(input, bomb);
	return 0;
}
