#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

string bigNum(string n1, string n2) {
	long long sum = 0;
	string result;
	
	while(!n1.empty() || !n2.empty() || sum) {
		if(!n1.empty()) {
			sum += n1.back() - '0';
			n1.pop_back();
		}
		if(!n2.empty()) {
			sum += n2.back() - '0';
			n2.pop_back();
		}
		result.push_back((sum % 10) - '0');
		sum /= 10;
		
		
	}
	reverse(result.begin(), result.end());
	return result;
	
}

string subone(string num) {
	int back = num.back() - '0';
	num.pop_back();
	back -= 1;
	num.push_back(back + '0');
	return num;
}

void hanoi(int n, int start, int to, int end) {
	if(n == 0) {
		return;
	}
	hanoi(n - 1, start, end, to);
	printf("%d %d\n", start, end);
	hanoi(n - 1, to, start, end);
}

int main ()
{
	int N;
	cin >> N;
	
	if(N <= 20) {
		cout << (long long)pow(2, N) - 1<< endl;
		hanoi(N, 1, 2, 3);
	}
	
	else {
		string num = "2";
		for (int i = 0; i < N - 1; i++) {
			string tmp = bigNum(num, num);
			num = tmp;
		}
		cout << subone(num) <<'\n';
		
	}
	
	return 0;
}
