#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	priority_queue<int> max;
	priority_queue<int, vector<int>, greater<int>> min;
	
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		
		if(i == 0) {
			max.push(input);
		}
		else {
			if(max.size() > min.size() || min.empty()) {
				min.push(input);
			}
			else {
				max.push(input);
			}
		}
		
		if(!min.empty() && max.top() > min.top()) {
			int tmpMax = max.top();
			int tmpMin = min.top();
			
			max.pop();
			min.pop();
			max.push(tmpMin);
			min.push(tmpMax);
		}
		
//		cout << "max : { ";
//		vector<int> tmpMax;
//		vector<int> tmpMin;
//		while(!max.empty()) {
//			cout << max.top() << ' ';
//			tmpMax.push_back(max.top());
//			max.pop();
//		}
//		for (int i = 0; i < tmpMax.size(); i++) {
//			max.push(tmpMax[i]);
//		}
//		cout << "} " << '\n';
//		
//		cout << "min : { ";
//		while(!min.empty()) {
//			cout << min.top() << ' ';
//			tmpMin.push_back(min.top());
//			min.pop();
//		}
//		for(int i = 0; i < tmpMin.size(); i++) {
//			min.push(tmpMin[i]);
//		}
//		
//		cout << "} " << '\n';
//		cout << "ans: " << max.top() << '\n';
		cout << max.top() << '\n';
	}
//	cout << '\n';
//	while(!max.empty()) {
//		cout << max.top() << ' ';
//		max.pop();
//	}
//	
//	cout << '\n';
//	while(!min.empty()) {
//		cout << min.top() << ' ';
//		min.pop();
//	}

	
	return 0;
}
