#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

#define ARR_MAX 500

using namespace std;


class MyStack {
	int arr[ARR_MAX];
	int topIndx;
	
	publc:
		MyStack() {
			topIndx = -1;
		}
		
		void push(int x) {
			topIndx++;
			arr[topIndx] = x;
		}
		
		int pop() {
			if (topIndx == -1) {
				return -1;
			}
			
			else {
				int ret = arr[topIndx];
				topIndx--;
				return ret;
			}
		}
		
		int size() {
			return topIndx + 1;
		}
		
		int empty(){
			if (topIndx == -1) {
				return 1;
			}
			
			else {
				return 0;
			}
		}
		
		int top() {
			if(topIndx == -1) {
				return -1;
			}
			
			else {
				return arr[topIndx];
			}
		}
		void management(string command) {
			if (command.compare("push")) {
				int value;
				scanf("%d", &value);
				push(value);
			}
			
			if (command.compare("pop")) {
				printf("%d\n", pop());
			}
			
			if (command.compare("size")) {
				printf("%d\n", size());
			}
			
			if (command.compare("empty")) {
				printf("%d\n", empty());
			}
			
			if (command.compare("top")) {
				printf("%d\n", top());
			}
		}
};

int main()
{
	int n;
	scanf("%d", &n);
	
	Mystack myStack;
	for (int i = 0; i < n; i++) {
		string str;
		scanf("%s", &str);
		myStack.management(str);
	}
	
	return 0;
}
