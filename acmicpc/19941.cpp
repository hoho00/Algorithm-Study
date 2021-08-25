#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int N, K;
	string table;
	cin >> N >> K;
	cin >> table;
	int count = 0;
	for(int i = 0; i < N; i++) {
		if(table[i] == 'H' || table[i] == '*') continue;
		
		for (int j =  -1 * K; j <= K; j++) { 
			if(i + j >= 0 && i + j < N && table[i + j] == 'H') {
				table[i + j] = '*';
				count++;
				break;
			}
		}
	}
	cout << count;
	return 0;
}
