#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <set>

using namespace std;

int N;
vector<pair <int, int>> v;
set<int> s;


void dfs(int depth, int wSum, int bSum) {
	if(depth == N) {
		int c = abs(wSum - bSum);
		s.insert(c);
		return;
	}
	dfs(depth + 1, wSum+v[depth].first, bSum+v[depth].second);
	dfs(depth + 1, wSum+v[depth].second, bSum+v[depth].first); 
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		int w, b;
		cin >> w >> b;
		v.push_back(make_pair(w, b));
	}
	int min = INT_MAX;

	vector<int> ve;
	
	for (int i = 0; i < N; i++) {
		if(i < N / 2) {
			ve.push_back(0);
		}
		else {
			ve.push_back(1);
		}
	}
	do {
		int sum = 0;
		for (int i = 0; i < N; i++) {
			if(ve[i] == 0) {
				sum += v[i].first;
			}
			else {
				sum += -1 * v[i].second;
			}
		}
		sum = abs(sum);
		if (min > sum) min = sum;
	}while(next_permutation(ve.begin(), ve.end()));
	cout << min;
	return 0;
}
