#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct Meeting {
	int start;
	int end;
	int term;
	Meeting(){
		
	}
	Meeting(int a, int b) {
		start = a;
		end = b;
		term = b - a;
	}
	bool operator<(const Meeting &b)const {
		if(b.end == this->end) {
			return this->start < b.start;
		}
		else {
			return this->end < b.end;
		}
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, count = 0;
	cin >> n;
	vector<Meeting> a;
	set <int> check;
	for (int i = 0; i < n; i++) {
		int start, end;
		cin >> start >> end;
		Meeting tmp(start, end);
		a.push_back(tmp);
	}
	
	sort(a.begin(), a.end());
	check.insert(0);
	int lastEnd = a[0].end;
	for (int i = 1; i < n; i++) {
		if(a[i].start >= lastEnd) {
			lastEnd = a[i].end;
			check.insert(i);
		}
	}
	
	cout << check.size();
	return 0;
}
