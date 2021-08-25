#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <climits>

using namespace std;
int n;
int numCal = 0;
int a[12];
int cal[5];
int sol[12];
vector<int> arrCal;
stack<int> st;
int min = INT_MIN;
int max = INT_MAX;


int calculation(int a, int b, int cal) {
	if (cal == 1) {
		return a + b;
	}
	else if (cal == 2) {
		return a - b;
	}
	else if (cal == 3) {
		return a * b;
	}
	else if (cal == 4) {
		return a / b;
	}
	else {
		return -1;
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	
	for (int i = n - 1; i >= 0; i--) {
		st.push(a[i]);
	}
	//1: +, 2: -, 3: *, 4: /
	for (int i = 1; i <= 4; i++) {
		int cal;
		scanf("%d", &cal);
		
		for (int j = numCal; j < numCal + cal; j++) {
			arrCal.push_back(i);
		}
		numCal += cal;
	}
	do {
		for (int i = 0; i < n - 1; i++) {
			int a = st.top();
			st.pop();
			int b = st.top();
			st.pop();
			st.push(calculation(a, b, arrCal[i]));
			printf("%d\n", st.top());
		}
	}while (next_permutation(arrCal.begin(), arrCal.end()));
	
	printf("%d", st.top());
	return 0;
}
