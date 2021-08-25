#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int a[10001];
string s;
string output;

int n;

void dp1(int indx, string comp) {
	if(indx == n + 2) {
		return;
	}
	//cout << "res : "<< output << endl;
	//cout << "comp : " << comp << endl;
	if(comp < output) {
		output = comp;
		//return;
		//cout << "ttttttttt "<< endl;
		return;
 	}
	
	string::iterator iter = comp.begin() + indx;
	//cout << "indx : "<< indx << endl;
	string not_reversed = comp;
	reverse(comp.begin(), iter);
	string reversed = comp;
	//cout << "yes : "<< comp << endl << endl;
	dp1(indx + 1, not_reversed);
	dp1(indx + 1, reversed);
}




int main()
{
	ios::sync_with_stdio(false);
  	cin.tie(NULL);
  	cout.tie(NULL);
	cin >> s;
	n = s.size();
	output = s;
	//dp1(2, s);
	//sort(output.begin(), output.end());
	string comp  = "";
	comp += s.at(0);
	for (int i = 1; i < n; i++) {
		string left_add = comp + s.at(i);
		string right_add = s.at(i) + comp;
		if(left_add > right_add) {
			comp = right_add;
		}
		else {
			comp = left_add;
		}
	}
	
	cout << comp;
	return 0;
}
