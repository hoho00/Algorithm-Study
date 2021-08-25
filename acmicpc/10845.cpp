#include <iostream>
#include <cstring>
#include <string>

const int maxLen = 100000;

using namespace std;

typedef enum {
	push, pop, size, empty, top
}Command;


class MyQueue {
	private:
		int arr[maxLen];
		int frontIndx;
		int backIndx;
	
	public:
		MyQueue() {
			frontIndx = -1;
			backIndx = 0;
		}
		
		void push(int v) {
			arr[backIndx] = v;
			backIndx++;
		}
		
		int pop() {
			if(this->size() == 0) {
				return -1;
			}
			else {
				frontIndx++;
				int ret = arr[frontIndx];
				return ret;
			}
		}
		
		int size() {
			return backIndx - frontIndx - 1;
		}
		
		int empty() {
			if(this->size() == 0) {
				return 1;
			}
			else return 0;
		}
		
		int front() {
			if(this->size() == 0) {
				return -1;
			}
			
			else {
				return arr[frontIndx + 1];
			}
		}
		
		int back() {
			if(this->size() == 0) {
				return -1;
			}
			
			else {
				return arr[backIndx - 1];
			}
		}
		
};
int main()
{
	int numberOfCommand;
	cin >> numberOfCommand;
	
	
	int *resultArray = new int[numberOfCommand];
	int arrayIndx = 0;
	MyQueue qu;
	
	for (int i = 0; i < numberOfCommand; i++) {
		string command;
		cin >> command;
		
		if (command.compare("push") == 0) {
			int data;
			cin >> data;
			qu.push(data);
		}
		
		else if (command.compare("pop") == 0) {
			resultArray[arrayIndx] = qu.pop();
			arrayIndx++;
		}
		
		else if (command.compare("size") == 0) {
			resultArray[arrayIndx] = qu.size();
			arrayIndx++;
		}
		
		else if (command.compare("empty") == 0) {
			resultArray[arrayIndx] = qu.empty();
			arrayIndx++;
		}
		
		else if (command.compare("front") == 0) {
			resultArray[arrayIndx] = qu.front();
			arrayIndx++;
		}
		
		else if (command.compare("back") == 0) {
			resultArray[arrayIndx] = qu.back();
			arrayIndx++;
		}
		
		else {
			
		}
	}
	
	for (int i = 0; i < arrayIndx; i++) {
		cout << resultArray[i] << endl;
	}
	
	return 0;
}
