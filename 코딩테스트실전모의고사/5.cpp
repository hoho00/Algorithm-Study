#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Study{
	int st;
	int et;
	int effi;
	bool operator<(const Study &b) const {
		return this->et < b.et;
	}
};



int main() {
	ios_base::sync_with_stdio(false);
	
	
  	int N, M, R, answer = -2147000000;
  	cin >> N >> M >> R;
  	
	vector<Study> s;
	vector<int> dy(M + 1, 0);
	int ans = 0;
	
  	for (int i = 0; i < M; i++) {
  		int tmpSt, tmpEt, tmpEffi;
  		Study tmp;
  		cin >> tmpSt >> tmpEt >> tmpEffi;
  		tmp.st = tmpSt;
  		tmp.et = tmpEt;
  		tmp.effi = tmpEffi;
  		
  		s.push_back(tmp);
	}
	sort(s.begin(), s.end());
	
	for (int i = 0; i < M; i++) {
		dy[i] = s[i].effi;
	}

	for (int i = 0; i < M; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if(s[j].et + R <= s[i].st && dy[j] + s[i].effi > dy[i]) {
				dy[i] = s[i].effi + dy[j];
			}
		}
		answer = max(answer, dy[i]);
	}
	
	cout << answer;
  	return 0;
}
