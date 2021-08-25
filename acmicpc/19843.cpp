#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	map<string, int> day;
	day.insert(map<string, int>::value_type("Mon", 1));
	day.insert(map<string, int>::value_type("Tue", 2));
	day.insert(map<string, int>::value_type("Wed", 3));
	day.insert(map<string, int>::value_type("Thu", 4));
	day.insert(map<string, int>::value_type("Fri", 5));
	int T, N;
	int sum = 0;
	cin >> T >> N;
	for (int i = 0; i < N; i++) {
		string day_1, day_2;
		int time_1, time_2;
		cin >> day_1 >> time_1 >> day_2 >> time_2;
		int diff = (int)(day.find(day_2)->second) - (day.find(day_1)->second);
		sum += (24 * diff + time_2 - time_1);
		//cout << (24 * diff + time_2 - time_1) << endl;
	}
	if((T - sum) > 48) {
		cout << "-1";
	}
	else if((T - sum) < 0){
		cout << 0;
	}
	else {
		cout << T - sum;
	}
	
	
	return 0;
}
