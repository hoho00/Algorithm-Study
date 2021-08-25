#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string a[26];
bool isVisit[26][26] = {false, };
int n, homeCount = 0;
vector<int> answer;

int dx[4] = { 0, 1, 0, -1};
int dy[4] = { -1, 0, 1, 0};

void dfs(int x, int y) {
	isVisit[x][y] = true;
	homeCount++;
	
	for (int i = 0; i < 4; i++) {
		int newX = x + dx[i];
		int newY = y + dy[i];
		if(0 <= newX && newX < n && 0 <= newY && newY < n) {
			if(a[newX][newY] == '1' && !isVisit[newX][newY]) {
				dfs(newX, newY);
			}
		}		
	}
} 

int main()
{
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == '1' && !isVisit[i][j]) {
				homeCount = 0;
				dfs(i, j);
				answer.push_back(homeCount);
				//printf("%d\n", count);
			}
		}
	}
	
	sort(answer.begin(), answer.end());
	printf("%d\n", answer.size());
	for (int i = 0; i < answer.size(); i++) {
		printf("%d\n", answer[i]);
	}
	return 0;
}
