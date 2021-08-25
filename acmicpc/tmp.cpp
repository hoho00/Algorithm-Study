#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <string>
using namespace std;

int N;
int visited[1000001];
#include <string>
#include <vector>
#include <iostream>

using namespace std;

pair<string, int> simpleInfo(string str) {
    pair<string, int> res;
    string resStr = "";
    for (int i = 0; i < 5; i++) {
        if(i == 4) {
            int num = stoi(str);
            res.second = num;
            break;
        }
		int a = str.find(' ');
        resStr += str.substr(0, 1);
        str  = str.substr(a + 1);
        
    }
    res.first = resStr;
    return res;
}

int main()
{
	string test = "java backend junior pizza 150";
	pair<string, int> p = simpleInfo(test);
	cout << p.first << " " << p.second << endl;
	return 0;
}
