#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
	vector<pair<int, int>> pos;
	int W, H, T, S;
	cin >> W >> H >> T >> S;
	int max = 0;
	for (int i = 0; i < T; i++) {
		int x, y;
		cin >> x >> y;
		pos.push_back(make_pair(x, y));
	}
	
//	for (int i = 0; i <= W - S; i++) {
//		for (int j = 0; j <= H - S; j++) {
//			int countThisPoint = 0;
//			for (auto k : pos) {
//				if(k.first >= i && k.first <= i + S && k.second >= j && k.second <= j + S) {
//					countThisPoint ++;
//					//cout << "pair : "<< k.first << " " << k.second << endl;
//				}
//			}
//			//cout << endl << endl;
//			
//			if(countThisPoint > max) max = countThisPoint;
//		}
//	}
	
	for (int i = 0; i < pos.size(); i++) {
		for (int j = 0; j < pos.size(); j++) {
			int x = pos[i].first;
			int y = pos[j].second;
			int countThisPoint = 0;
			for (auto k : pos) {
				if(k.first >= x && k.first <= x + S && k.second >= y && k.second <= y + S) {
					countThisPoint ++;
					//cout << "pair : "<< k.first << " " << k.second << endl;
				}
			}
			if(countThisPoint > max) max = countThisPoint;
		}
	}
	cout << max;
	return 0;
}
